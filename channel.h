#ifndef CHANNEL_H
#define CHANNEL_H

#include <QObject>
#include <QTcpSocket>
#include <QTextBrowser>
#include <qUdpSocket>
#include "SocketHandeling.h"


class channel: public QObject {
	Q_OBJECT


public:
	channel(QTcpSocket *_socket, int _client_number, std::fstream *_socket_log, QObject *parent = nullptr);
	~channel();


	void close_socket();
private:
	QTcpSocket *socket = nullptr;
	QUdpSocket *udp_socket = nullptr;
	QString client_name;
	std::fstream *socket_log;
	int client_number;

public slots:
	void reading_data();
	void writing_data();
	void disconnected_from_server();
	void send_data(QByteArray data);

};

#endif // CHANNEL_H
