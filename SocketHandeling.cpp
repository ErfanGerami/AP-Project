#include "SocketHandeling.h"

#pragma warning(disable:4996)
using namespace std::chrono;


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



SocketHandeling::SocketHandeling(QObject *parent) {

	udp_socket = new QUdpSocket();
	tcp_socket = new QTcpSocket();
	tcp_server = new QTcpServer();
	socket_log.open("socket-log.txt", std::ios::out | std::ios::ate | std::ios::trunc);
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

	socket_log.close();
}



void SocketHandeling::client_run(QString username) {
	socket_log << make_time() << "> trying to catch server ip through udp socket\n\n";
	udp_socket->bind(QHostAddress::AnyIPv4, 1500);

	if ( udp_socket->waitForReadyRead(1000) ) {
		socket_log << make_time() << "> server found\n\n";

		QByteArray buffer;
		QHostAddress ip;
		quint16 port;

		buffer.resize(udp_socket->pendingDatagramSize());
		udp_socket->readDatagram(buffer.data(), buffer.size(), &ip, &port);
		QByteArrayList list = buffer.split('&');


		socket_log << make_time() << "> trying to connect to server with name '" << list[0].toStdString() << "' created by '" << list[1].toStdString() << "'\n\n";


		tcp_socket->connectToHost(ip, port);

		tcp_socket->waitForConnected(-1);

		connect(tcp_socket, SIGNAL(bytesWritten(qint64)), this, SLOT(writing_data_socket()));
		connect(tcp_socket, SIGNAL(readyRead()), this, SLOT(reading_data_socket()));
		connect(tcp_socket, SIGNAL(disconnected()), this, SLOT(disconnected_from_server_socket()));

		socket_log << make_time() << "> connected to server\n\n";

		tcp_socket->write(username.toUtf8());

		tcp_socket->waitForBytesWritten(-1);

		socket_log << make_time() << "> written name as client\n\n";

	}
	else {
		socket_log << make_time() << "> no server found\n\n";
		throw Errors(Errors::server_not_found);
	}
}

void SocketHandeling::server_run(QString server_name, QString username) {

	socket_log << make_time() << "> trying to create server with name: '" << server_name.toStdString() << "' and created by '" << username.toStdString() << "'\n\n";

	broadcast_ip_thread = std::thread { &SocketHandeling::broadcast_ip, this, server_name, username };//continously announce ip

	tcp_server = new QTcpServer();
	tcp_server->listen(QHostAddress::Any, 1500);

	if ( tcp_server->isListening() ) {
		socket_log << make_time() << "> server created and listening on port 1500\n\n";

		connect(tcp_server, SIGNAL(newConnection()), this, SLOT(new_connection_server()));

		is_the_server = true;
	}
	else {
		socket_log << make_time() << "> failed to start server\n\n";
		throw Errors(Errors::server_initiation_failed);
	}


}

void SocketHandeling::broadcast_ip(QString server_name, QString username) {
	while ( true ) {
		QByteArray message = QString(server_name + "&" + username).toUtf8();
		udp_socket->writeDatagram(message, QHostAddress::Broadcast, 1500);
		std::this_thread::sleep_for(milliseconds(100));
		udp_socket->flush();


	}

}

void SocketHandeling::new_connection_server() {
	channel *new_channel = new channel(tcp_server->nextPendingConnection(), channels.size() + 1, &socket_log);
	channels.push_back(new_channel);
	socket_log << make_time() << "> new client connected, client number: " << channels.size() << "\n\n";
}


void SocketHandeling::reading_data_socket() {

}

void SocketHandeling::writing_data_socket() {
	socket_log << make_time() << "> written to socket as client\n\n";

}

void SocketHandeling::disconnected_from_server_socket() {
	socket_log << make_time() << "> server disconnected\n\n";
}