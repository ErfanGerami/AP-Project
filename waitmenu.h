#ifndef WAITMENU_H
#define WAITMENU_H

#include <QDialog>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPropertyAnimation>
#include <QGraphicsProxyWidget>
#include "SocketHandeling.h"

extern QString ServerName;
namespace Ui {
	class WaitMenu;
}

class WaitMenu: public QDialog {
	Q_OBJECT

public:
	explicit WaitMenu(SocketHandeling *connection, SocketHandeling *client = nullptr, QWidget *parent = nullptr);


	~WaitMenu();

public slots:
	void new_player(QString name);

private:
	Ui::WaitMenu *ui;
	QGraphicsScene *scene;

	SocketHandeling *server;
	SocketHandeling *client;
	bool am_i_server;
};

#endif // WAITMENU_H
