#pragma once
#include <QObject>
#include <iostream>
#include <QUdpSocket>
#include <qmap.h>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDataStream>
#include <QbyteArray>
#include <thread>
#include <chrono>
#include "errors.h"
#include "channel.h"
#include "DataPacket.h"
#include <fstream>
#include <ctime>
#include <sstream>
#include "Code.h"

class channel;

class SocketHandeling: public QObject {
	Q_OBJECT

public:
	SocketHandeling(QObject *parent = nullptr);
	~SocketHandeling();

	void client_run_fast_connect(QString username);
	void client_run(QHostAddress ip, QString username);
	void send_data(char *code, DataPacket *data, int client_number = -1);


	int get_joined_players_count();
	int get_player_count();
	bool am_i_the_server();

	void server_run(QString server_name, QString username, int player_count);


	static std::string make_time();
	QMap<QHostAddress, QPair<QString, QString>> get_servers();

	bool is_client_connected();
	bool is_server_connected();

	QTcpSocket *get_tcp_socket();
	QTcpServer *get_tcp_server();
	QString get_name();
	channel *get_channel_pointer();
private:
	int player_count;
	void logWriteServer(std::string str);
	void logWriteClient(std::string str);
	QString name;

	channel *channel_pointer;

	QUdpSocket *udp_socket = nullptr;
	QTcpSocket *tcp_socket = nullptr;
	QTcpServer *tcp_server = nullptr;

	std::thread broadcast_ip_thread;

	std::vector<channel *> channels;


	std::fstream server_log;
	std::fstream client_log;

	bool is_the_server = false;

	void broadcast_ip(QString server_name, QString username);

public slots:
	void new_connection_server();
	QVector<QPair< char *, DataPacket * >> read_data_as_server();
	QPair<char *, DataPacket *> reading_data_socket();
	void writing_data_socket();
	void connected_to_server_socket();
	void disconnected_from_server_socket();


	void func(QString name);


private slots:


signals:
	void newplayer(QString name);
	void newplayer_socket();
};

