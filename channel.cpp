#include "channel.h"
using namespace std;

channel::channel(QTcpSocket *_socket, int _client_number, QObject *parent):
	QObject(parent) {
	socket = _socket;


	connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(writing_data()));
	connect(socket, SIGNAL(readyRead()), this, SLOT(reading_data()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected_from_server()));
	connect(this, SIGNAL(newplayer(QString)), parent, SLOT(func(QString)));
	client_number = to_string(_client_number);
	udp_socket = new QUdpSocket();

}


void channel::logWriteServer(std::string str) {
	fstream server_log;
	server_log.open("server-log.txt", ios::out | ios::app);
	server_log << SocketHandeling::make_time() << str;
	server_log.close();
}




void channel::writing_data() {


	logWriteServer("> written seccessfully as server to client number " + client_number + " and name '" + client_name.toStdString() + "'");

}

QPair<char *, DataPacket *> channel::reading_data() {
	logWriteServer("> reading data from socket number: " + client_number);

	QByteArray block;
	DataPacket *data_packet = new DataPacket();
	char *code = new char[6];

	//-----------
	while ( true )
		if ( client_name.size() == 0 || socket->bytesAvailable() || socket->waitForReadyRead(1000) ) {

			block = socket->read(220);

			while ( block[0] == '&' )
				block.remove(0, 1);

			logWriteServer("> read " + to_string(block.size()) + "bytes of data");


			if ( client_name.size() == 0 ) {
				client_name = block;
				emit newplayer(client_name);
				logWriteServer("> client name recieved: " + client_name.toStdString());

				disconnect(socket, SIGNAL(readyRead()), this, SLOT(reading_data()));

			}
			else {

				for ( int i = 0; i < 5; i++ )
					code[i] = block[i];
				code[5] = '\0';

				block.remove(0, 5);

				//logWriteServer("code: " + std::string(code));

				QDataStream in(&block, QIODevice::ReadOnly);
				in >> *data_packet;

			}
			break;
		}

	return QPair<char *, DataPacket *>(code, data_packet);
}

void channel::disconnected_from_server() {

	logWriteServer("> client number " + client_number + " and name '" + client_name.toStdString() + "' disconnectd");

}

void channel::send_data(QByteArray block) {

	socket->write(block);
	socket->waitForBytesWritten(-1);
}

void channel::close_socket() {

	socket->disconnect();

	logWriteServer("> disconnected client number " + client_number + " and name '" + client_name.toStdString() + "'");
}

QString channel::get_name() {
	return client_name;
}

channel::~channel() {


	if ( socket != nullptr )
		delete socket;
}
