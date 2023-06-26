#include "SocketHandeling.h"

#pragma warning(disable:4996)
using namespace std::chrono;
using namespace std;


std::string SocketHandeling::make_time() {
	const time_t now = time(0);
	struct tm *t = localtime(&now);
	std::stringstream out;
	out << t->tm_year << "/" << t->tm_mon << "/" << t->tm_mday << "|" << t->tm_hour << ":" << t->tm_min << ":" << t->tm_sec;
	std::string retrn;
	out >> retrn;
	retrn += '\n';
	return retrn;
}

void SocketHandeling::logWriteServer(std::string str) {
	server_log.open("server-log.txt", ios::out | ios::app);
	server_log << make_time() << str;
	server_log.close();
}

void SocketHandeling::logWriteClient(std::string str) {
	client_log.open("client-log.txt", ios::out | ios::app);
	client_log << make_time() << str;
	client_log.close();
}


SocketHandeling::SocketHandeling(QObject *parent) {

	udp_socket = new QUdpSocket();
	tcp_socket = new QTcpSocket();
	tcp_server = new QTcpServer();


	connect(tcp_socket, SIGNAL(connected()), this, SLOT(connected_to_server_socket()));
	connect(tcp_socket, SIGNAL(bytesWritten(qint64)), this, SLOT(writing_data_socket()));
	connect(tcp_socket, SIGNAL(readyRead()), this, SLOT(reading_data_socket()));
	connect(tcp_socket, SIGNAL(disconnected()), this, SLOT(disconnected_from_server_socket()));

	//server_log.open("server-log.txt", ios::out | ios::trunc | ios::ate);
	//server_log << "> init log\n\n";
	//server_log.close();
	//
	//client_log.open("client-log.txt", ios::out | ios::trunc | ios::ate);
	//client_log << "> init log\n\n";
	//client_log.close();
}

SocketHandeling::~SocketHandeling() {
	broadcast_ip_thread.join();

	udp_socket->disconnect();
	tcp_server->disconnect();
	tcp_socket->disconnect();

	delete udp_socket;
	delete tcp_socket;
	delete tcp_server;

	for ( auto a : channels ) {
		a->close_socket();
		delete a;
	}

	if ( channels.size() )
		channels.clear();


}


//client
void SocketHandeling::client_run(QString username) {
	logWriteClient("> trying to catch server ip through udp socket\n\n");
	udp_socket->bind(QHostAddress::Any, 1500);

	if ( udp_socket->waitForReadyRead(1000) ) {
		logWriteClient("> server found\n\n");

		QByteArray buffer;
		QHostAddress ip;
		quint16 port;

		buffer.resize(udp_socket->pendingDatagramSize());
		udp_socket->readDatagram(buffer.data(), buffer.size(), &ip, &port);
		QByteArrayList list = buffer.split('&');


		logWriteClient("> trying to connect to server with name '" + list[0].toStdString() + "' created by '" + list[1].toStdString() + "'\n\n");


		tcp_socket->connectToHost(ip, 1500);

		name = username;



		//tcp_socket->waitForConnected(-1);

		//logWriteClient("> connected to server\n\n");




		//tcp_socket->write("1234567");
		//tcp_socket->waitForBytesWritten(-1);

		//logWriteClient("> written name as client\n\n");

	}
	else {
		logWriteClient("> no server found\n\n");
		throw Errors(Errors::server_not_found);
	}
}


void SocketHandeling::reading_data_socket() {

}

void SocketHandeling::connected_to_server_socket() {
	logWriteClient("> connected to server\n\n");
	tcp_socket->write(name.toUtf8());
}

void SocketHandeling::writing_data_socket() {
	logWriteClient("> written to socket as client\n\n");

}

void SocketHandeling::disconnected_from_server_socket() {
	logWriteClient("> server disconnected\n\n");
}





//server:
void SocketHandeling::server_run(QString server_name, QString username) {
	name = username;


	logWriteServer("> trying to create server with name: '" + server_name.toStdString() + "' and created by '" + username.toStdString() + "'\n\n");

	broadcast_ip_thread = std::thread { &SocketHandeling::broadcast_ip, this, server_name, username };//continously announce ip

	tcp_server = new QTcpServer();
	tcp_server->listen(QHostAddress::Any, 1500);

	if ( tcp_server->isListening() ) {
		logWriteServer("> server created and listening on port 1500\n\n");

		connect(tcp_server, SIGNAL(newConnection()), this, SLOT(new_connection_server()));

		is_the_server = true;
	}
	else {
		logWriteServer("> failed to start server\n\n");
		throw Errors(Errors::server_initiation_failed);
	}


}

void SocketHandeling::broadcast_ip(QString server_name, QString username) {
	while ( true ) {
		QByteArray message = QString(server_name + "&" + username).toUtf8();
		udp_socket->writeDatagram(message, QHostAddress::Broadcast, 1500);
		std::this_thread::sleep_for(milliseconds(50));
		udp_socket->flush();
		std::this_thread::sleep_for(milliseconds(50));


	}

}

void SocketHandeling::new_connection_server() {
	channel *new_channel = new channel(tcp_server->nextPendingConnection(), channels.size());
	channels.push_back(new_channel);

	logWriteServer("> new client connected, client number: " + QString::number(channels.size()).toStdString() + "\n\n");
}


