#ifndef CHANNEL_H
#define CHANNEL_H

#include <QObject>
#include <QTcpSocket>
#include <QTextBrowser>
#include <qUdpSocket>
#include <fstream>
#include "SocketHandeling.h"
#include "DataPacket.h"


class channel: protected QObject {
	Q_OBJECT


public:
	channel(QTcpSocket *_socket, int _client_number, QObject *parent = nullptr);
	~channel();


	void close_socket();
private:
	QTcpSocket *socket = nullptr;
	QUdpSocket *udp_socket = nullptr;
	QString client_name;

	std::string client_number;
	static void logWriteServer(std::string str);


public slots:
	QPair<char *, DataPacket *> reading_data();
	void writing_data();
	void disconnected_from_server();
	void send_data(QByteArray block);

};

#endif // CHANNEL_H
