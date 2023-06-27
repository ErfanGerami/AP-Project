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
void SocketHandeling::client_run_fast_connect(QString username) {
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
		//tcp_socket->waitForConnected(-1);
		//tcp_socket->write(name.toUtf8());
		//tcp_socket->waitForBytesWritten(-1);
		name = username;


	}
	else {
		logWriteClient("> no server found\n\n");
		throw Errors(Errors::server_not_found);
	}
}

void SocketHandeling::client_run(QHostAddress ip, QString username) {
	name = username;

	logWriteClient("> trying to connect to server with ip '" + ip.toString().toStdString() + "'\n\n");

	tcp_socket->connectToHost(ip, 1500);

	if ( !tcp_socket->waitForConnected(1000) ) {

		logWriteClient("> connection failed\n\n");
		throw Errors(Errors::cant_connect);
	}
}

bool operator<(const QHostAddress &a, const QHostAddress &b) {
	QStringList a_list = a.toString().split('.');
	QStringList b_list = b.toString().split('.');

	return
		a_list[0].toInt() < b_list[0].toInt() ||
		a_list[1].toInt() < b_list[1].toInt() ||
		a_list[2].toInt() < b_list[2].toInt() ||
		a_list[3].toInt() < b_list[3].toInt();
}

QMap<QHostAddress, QPair<QString, QString>> SocketHandeling::get_servers() {

	logWriteClient("> trying to catch server ip through udp socket\n\n");
	udp_socket->bind(QHostAddress::AnyIPv4, 1500);
	QMap<QHostAddress, QPair<QString, QString>> server_map;

	for ( int i = 0; i < 20 && udp_socket->waitForReadyRead(200 + i * 5); i++ ) {


		QByteArray buffer;
		QHostAddress ip;
		quint16 port;

		buffer.resize(udp_socket->pendingDatagramSize());
		udp_socket->readDatagram(buffer.data(), buffer.size(), &ip, &port);
		QByteArrayList list = buffer.split('&');
		qDebug() << ip;
		qDebug() << list[0];
		server_map[ip] = qMakePair<QString, QString>(list[0], list[1]);
		udp_socket->flush();
	}

	logWriteClient("> " + QString::number(server_map.size()).toStdString() + " server found\n\n");

	return server_map;

}

bool SocketHandeling::is_client_connected() {
	return tcp_socket->isOpen();

}

bool SocketHandeling::is_server_connected() {
	return tcp_server->isListening();
}


void SocketHandeling::reading_data_socket() {

	QByteArray block = tcp_socket->readAll();

	char *code = new char[4];
	for ( int i = 0; i < 4; i++ )
		code[i] = block[i];

	block.remove(0, 4);


	QDataStream in(&block, QIODevice::ReadOnly);
	DataPacket data_packet;
	in >> data_packet;


	//now do things with data packet and code



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

		std::this_thread::sleep_for(milliseconds(40));
		udp_socket->flush();
	}

}

void SocketHandeling::send_data(char *code, DataPacket *data) {

	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);

	out << *data;
	QByteArray front = "";
	front[0] = code[0];
	front[1] = code[1];
	front[2] = code[2];
	front[3] = code[3];


	QByteArray final_block = front + block;
	if ( is_the_server ) {
		for ( auto i : channels ) {
			i->send_data(final_block);
		}
	}
	else
		tcp_socket->write(final_block);



}

void SocketHandeling::new_connection_server() {
	channel *new_channel = new channel(tcp_server->nextPendingConnection(), channels.size());
	channels.push_back(new_channel);

	logWriteServer("> new client connected, client number: " + QString::number(channels.size()).toStdString() + "\n\n");
}


