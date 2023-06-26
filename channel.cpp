#include "channel.h"


channel::channel(QTcpSocket *_socket, int _client_number, std::fstream *_socket_log, QObject *parent) {
	socket = _socket;
	socket_log = _socket_log;

	socket->waitForReadyRead(-1);
	client_name = socket->readAll();



	connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(writing_data()));
	connect(socket, SIGNAL(readyRead()), this, SLOT(reading_data()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected_from_server()));

	client_number = _client_number;
	udp_socket = new QUdpSocket();

}



void channel::writing_data() {


	//*socket_log << SocketHandeling::make_time() << "> written seccessfully as server to client number " << client_number << " and name '" << client_name.toStdString() << "'\n\n";

}

void channel::reading_data() {



}

void channel::disconnected_from_server() {

	//*socket_log << SocketHandeling::make_time() << "> client number " << client_number << " and name '" << client_name.toStdString() << "' disconnectd\n\n";

}

void channel::send_data(QByteArray data) {

	socket->write(data);
}

void channel::close_socket() {

	socket->disconnect();

	//*socket_log << SocketHandeling::make_time() << "> disconnected client number " << client_number << " and name '" << client_name.toStdString() << "'\n\n";
}

channel::~channel() {

	qDebug() << "channel closed";
	if ( socket != nullptr )
		delete socket;
}
