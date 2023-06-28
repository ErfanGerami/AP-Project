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

QPair<char *, DataPacket *> channel::reading_data() {
	logWriteServer("> reading data\n\n");

	QByteArray block;
	DataPacket *data_packet = new DataPacket();
	char *code = new char[6];
	code[0] = 4;
	if ( socket->waitForReadyRead(1000) ) {

		block = socket->readAll();

		if ( client_name.size() == 0 ) {
			client_name = block;
			logWriteServer("> client name recieved: " + client_name.toStdString() + "\n\n");

			disconnect(socket, SIGNAL(readyRead()), this, SLOT(reading_data()));

		}
		else {

			for ( int i = 0; i < 5; i++ )
				code[i] = block[i];

			block.remove(0, 4);


			if ( code[0] == '0' || code[0] == '1' ) {
				//now do shit
			}
			else {

				QDataStream in(&block, QIODevice::ReadOnly);
				in >> *data_packet;

				//now do shit
			}



		}

	}

	return QPair<char *, DataPacket *>(code, data_packet);
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
