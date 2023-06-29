#ifndef WAITMENU_H
#define WAITMENU_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPropertyAnimation>
#include <QGraphicsProxyWidget>
#include "SocketHandeling.h"
#include "maingamewindow.h"
#include "Code.h"

extern QString ServerName;
namespace Ui {
	class WaitMenu;
}

class WaitMenu: public QMainWindow {
	Q_OBJECT

public:
	WaitMenu(SocketHandeling *connection, SocketHandeling *client_, QWidget *parent = nullptr);
	WaitMenu(SocketHandeling *client_, QWidget *parent = nullptr);



	~WaitMenu();



public slots:
	void new_player(QString name);

	void new_player_socket();
	void new_player_socket2();

	void on_pushButton_clicked();
private:
	QVector<QString> name_vec;
	Ui::WaitMenu *ui;
	QGraphicsScene *scene;
	int player_count;
	int player_joined = 0;
	SocketHandeling *server;
	SocketHandeling *client;

	bool am_i_server;
};

#endif // WAITMENU_H
