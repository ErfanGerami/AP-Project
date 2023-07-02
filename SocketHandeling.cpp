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
	server_log << make_time() << str << endl;
	server_log.close();
}

void SocketHandeling::logWriteClient(std::string str) {
	client_log.open("client-log.txt", ios::out | ios::app);
	client_log << make_time() << str << endl;
	client_log.close();
}


SocketHandeling::SocketHandeling(QObject *parent) {

	tcp_socket = new QTcpSocket();
	tcp_server = new QTcpServer();
	/*udp_socket = new QUdpSocket();
	udp_socket->bind(QHostAddress::Any, 1500);*/
	udp_socket = new QUdpSocket();



	connect(tcp_socket, SIGNAL(connected()), this, SLOT(connected_to_server_socket()));
	connect(tcp_socket, SIGNAL(bytesWritten(qint64)), this, SLOT(writing_data_socket()));
	//////connect(tcp_socket, SIGNAL(readyRead()), this, SLOT(reading_data_socket()));
	connect(tcp_socket, SIGNAL(disconnected()), this, SLOT(disconnected_from_server_socket()));
	connect(tcp_server, SIGNAL(newConnection()), this, SLOT(new_connection_server()));


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

void SocketHandeling::client_bytesAvailabe() {
	qDebug() << "++++++++++++++++++++++++++++thread initialized";
	while ( true ) {
		if ( data_vector_mutex.try_lock() ) {
			if ( tcp_socket->bytesAvailable() ) {
				emit main_game_read();
				qDebug() << "+++++++++++++++++++++++++ has unread data";

			}
			data_vector_mutex.unlock();
		}

		std::this_thread::sleep_for(milliseconds(1000));
	}

}
//client
void SocketHandeling::client_run_fast_connect(QString username) {
	client_log.open("client-log.txt", ios::out | ios::trunc);
	client_log.close();

	logWriteClient("> trying to catch server ip through udp socket");



	udp_socket->bind(QHostAddress::Any, 1500);

	if ( udp_socket->waitForReadyRead(1000) ) {
		logWriteClient("> server found");

		QByteArray buffer;
		QHostAddress ip;
		quint16 port;

		buffer.resize(udp_socket->pendingDatagramSize());
		udp_socket->readDatagram(buffer.data(), buffer.size(), &ip, &port);
		QByteArrayList list = buffer.split('&');


		logWriteClient("> trying to connect to server with name '" + list[0].toStdString() + "' created by '" + list[1].toStdString() + "'");


		tcp_socket->connectToHost(ip, 1500);


		client_bytesAvailabe_emit = std::thread { &SocketHandeling::client_bytesAvailabe, this };
		name = username;


	}
	else {
		logWriteClient("> no server found");
		throw Errors(Errors::server_not_found);
	}
}


void SocketHandeling::client_thread_funtion() {
	while ( true ) {
		if ( tcp_socket->bytesAvailable() || tcp_socket->waitForReadyRead(-1) ) {
			DataPacket *data_packet = new DataPacket();
			char *code = new char[6];
			QByteArray block;
			while ( true ) {
				if ( tcp_socket_mutex.try_lock() ) {
					block = tcp_socket->read(220);
					tcp_socket_mutex.unlock();
					break;
				}
			}

			while ( block[0] == '&' )
				block.remove(0, 1);

			logWriteClient("> read " + to_string(block.size()) + "bytes of data from server");

			for ( int i = 0; i < 5; i++ )
				code[i] = block[i];
			code[5] = '\0';

			block.remove(0, 5);




			QDataStream in(&block, QIODevice::ReadOnly);
			;
			in >> *data_packet;


			while ( true ) {
				if ( data_vector_mutex.try_lock() ) {
					qDebug() << "locked";
					data_pair_vector.push_back(QPair<char *, DataPacket *>(code, data_packet));
					data_vector_mutex.unlock();
					qDebug() << "unlocked";
					break;
				}
			}

			cond_var.notify_one();

		}
	}
}


QPair<char *, DataPacket *> SocketHandeling::reading_data_socket(bool force_read) {

	DataPacket *data_packet = new DataPacket();
	char *code = new char[6];


	if ( force_read || tcp_socket->bytesAvailable() || tcp_socket->waitForReadyRead(-1) ) {
		QByteArray block;
		while ( true ) {
			if ( tcp_socket_mutex.try_lock() ) {
				block = tcp_socket->read(220);
				tcp_socket_mutex.unlock();
				break;
			}
		}

		while ( block[0] == '&' )
			block.remove(0, 1);

		logWriteClient("> read " + to_string(block.size()) + "bytes of data from server");

		for ( int i = 0; i < 5; i++ )
			code[i] = block[i];
		code[5] = '\0';

		block.remove(0, 5);




		QDataStream in(&block, QIODevice::ReadOnly);
		;
		in >> *data_packet;




	}

	return QPair<char *, DataPacket *>(code, data_packet);

	//while ( data_pair_vector.isEmpty() ) { _sleep(200); }

	//std::unique_lock<mutex> lck{data_vector_mutex};

	//cond_var.wait(lck, [this] { return !data_pair_vector.isEmpty(); });
	////data_vector_mutex.lock();
	//QPair<char *, DataPacket *> data = data_pair_vector.front();
	//data_pair_vector.pop_front();
	////data_vector_mutex.unlock();
	//lck.unlock();
	//return data;

}


void SocketHandeling::client_run(QHostAddress ip, QString username) {
	name = username;

	logWriteClient("> trying to connect to server with ip '" + ip.toString().toStdString() + "'");

	tcp_socket->connectToHost(ip, 1500);
	//connect(tcp_socket, SIGNAL(connected()), this, SLOT(connected_to_server_socket()));
	client_bytesAvailabe_emit = std::thread { &SocketHandeling::client_bytesAvailabe, this };
	if ( !tcp_socket->waitForConnected(1000) ) {

		logWriteClient("> connection failed");
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

	logWriteClient("> trying to catch server ip through udp socket");
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

	logWriteClient("> " + QString::number(server_map.size()).toStdString() + " server found");

	return server_map;


}

bool SocketHandeling::is_client_connected() {
	return tcp_socket->isOpen();

}

bool SocketHandeling::is_server_connected() {

	return tcp_server->isListening();
}

QTcpSocket *SocketHandeling::get_tcp_socket() {
	return tcp_socket;
}

QTcpServer *SocketHandeling::get_tcp_server() {
	return tcp_server;
}

QUdpSocket *SocketHandeling::get_udp_socket() {
	return udp_socket;
}

QString SocketHandeling::get_name() {
	return name;
}

channel *SocketHandeling::get_channel_pointer() {
	return channel_pointer;
}

QVector<QPair<char *, DataPacket *>> SocketHandeling::read_data_as_server(int player_number) {

	QVector<QPair<char *, DataPacket *>> data_vector;

	int ctr = 0;
	for ( auto i : channels ) {
		QPair<char *, DataPacket *> pair;
		if ( player_number == ctr++ || player_number == -1 )
			pair = i->reading_data();
		data_vector.push_back(pair);
	}

	return data_vector;
}




void SocketHandeling::connected_to_server_socket() {
	logWriteClient("> connected to server");
	tcp_socket->write(name.toUtf8());
	//client_thread = std::thread { &SocketHandeling::client_thread_funtion, this };
}

void SocketHandeling::writing_data_socket() {
	logWriteClient("> written to socket as client");
}

void SocketHandeling::disconnected_from_server_socket() {
	logWriteClient("> server disconnected");
}




//server:
void SocketHandeling::server_run(QString server_name, QString username, int player_count) {
	server_log.open("server-log.txt", ios::out | ios::trunc);
	server_log.close();


	name = username;
	this->player_count = player_count;

	logWriteServer("> trying to create server with name: '" + server_name.toStdString() + "' and created by '" + username.toStdString() + "'");



	//udp_socket = new QUdpSocket();
	//udp_socket->bind(QHostAddress::Any, 1500);
	broadcast_ip_thread = std::thread { &SocketHandeling::broadcast_ip, this, server_name, username };//continously announce ip


	tcp_server = new QTcpServer();
	tcp_server->listen(QHostAddress::Any, 1500);

	if ( tcp_server->isListening() ) {
		logWriteServer("> server created and listening on port 1500");

		connect(tcp_server, SIGNAL(newConnection()), this, SLOT(new_connection_server()));

		is_the_server = true;


	}
	else {
		logWriteServer("> failed to start server");
		throw Errors(Errors::server_initiation_failed);
	}


}

void SocketHandeling::broadcast_ip(QString server_name, QString username) {
	while ( true ) {


		QByteArray message = QString(server_name + "&" + username).toUtf8();

		udp_socket->writeDatagram(message, QHostAddress::Broadcast, 1500);

		std::this_thread::sleep_for(milliseconds(400));

	}
	Q_ASSERT(false);
}

void SocketHandeling::send_data(char *code, DataPacket *data, int client_number) {




	QByteArray block = "";
	QDataStream out(&block, QIODevice::WriteOnly);
	out << *data;

	QByteArray front = "";

	for ( int i = 0; i < 5; i++ )
		front[i] = code[i];



	QByteArray final_block = front + block;

	Q_ASSERT(final_block.size() < 220);
	if ( final_block.size() < 220 ) {
		int add = 220 - final_block.size();
		QByteArray add_arr(add, '&');
		final_block = add_arr + final_block;
	}
	Q_ASSERT(final_block.size() == 220);






	if ( is_the_server ) {

		int ctr = 0;
		for ( auto i : channels ) {
			if ( client_number == ctr++ || client_number == -1 ) {
				i->send_data(final_block);
				logWriteServer("> sent " + to_string(final_block.size()) + "bytes of data to client number " + to_string(ctr));
			}
		}


	}
	else {
		tcp_socket->write(final_block);
		tcp_socket->waitForBytesWritten(-1);
		logWriteClient("> sent " + to_string(final_block.size()) + "bytes of data");
	}


}


void SocketHandeling::new_connection_server() {
	if ( channels.size() >= player_count - 1 )
		disconnect(tcp_server, SIGNAL(newConnection()), this, SLOT(new_connection_server()));
	channel *new_channel = channel_pointer = new channel(tcp_server->nextPendingConnection(), channels.size(), this);

	channels.push_back(new_channel);

	logWriteServer("> new client connected, client number: " + QString::number(channels.size()).toStdString());

}

void SocketHandeling::func(QString name) { emit newplayer(name); }

int SocketHandeling::get_joined_players_count() { return channels.size(); }

int SocketHandeling::get_player_count() {
	return player_count;
}

bool SocketHandeling::am_i_the_server() {
	return is_the_server;
}
