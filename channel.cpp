#include "channel.h"
using namespace std;

channel::channel(QTcpSocket *_socket, int _client_number, QObject *parent) {
	socket = _socket;


	connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(writing_data()));
	connect(socket, SIGNAL(readyRead()), this, SLOT(reading_data()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected_from_server()));

	client_number += _client_number;
	udp_socket = new QUdpSocket();

}


void channel::logWriteServer(std::string str) {
	fstream server_log;
	server_log.open("server-log.txt", ios::out | ios::app);
	server_log << SocketHandeling::make_time() << str;
	server_log.close();
}




void channel::writing_data() {


	logWriteServer("> written seccessfully as server to client number " + client_number + " and name '" + client_name.toStdString() + "'\n\n");

}

void channel::reading_data() {
	logWriteServer("> reading data\n\n");

	QByteArray block;

	block = socket->readAll();

	if ( client_name.size() == 0 ) {
		client_name = block;
		logWriteServer("> client name recieved: " + client_name.toStdString() + "\n\n");
	}
	else {

		

		char *code = new char[4];
		for ( int i = 0; i < 4; i++ )
			code[i] = block[i];

		block.remove(0, 4);


		QDataStream in(&block, QIODevice::ReadOnly);
		DataPacket data_packet;
		in >> data_packet;


		//now do things with data packet and code

	}

}

void channel::disconnected_from_server() {

	logWriteServer("> client number " + client_number + " and name '" + client_name.toStdString() + "' disconnectd\n\n");

}

void channel::send_data(QByteArray block) {

	socket->write(block);
}

void channel::close_socket() {

	socket->disconnect();

	logWriteServer("> disconnected client number " + client_number + " and name '" + client_name.toStdString() + "'\n\n");
}

channel::~channel() {


	if ( socket != nullptr )
		delete socket;
}
