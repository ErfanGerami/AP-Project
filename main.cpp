#define I srand(time(NULL));
#define REALLY srand(time(NULL));
#define HATE FILE *temp = fopen("players.bin", "ab+");
#define QTFRAMEWORK QApplication a(argc, argv);


#include "login.h"
#include <QApplication>
#include "filehandeling.h"
#include <QtDebug>
#include <QDir>
#include "player.h"
#include <QPushButton>
#include <QTimer>
#include <mainmenu.h>
#include <changeinfo.h>
#include "getserversinformation.h"
#include "waitmenu.h"
#include <maingamewindow.h>
#include "DataPacket.h"
#include "SocketHandeling.h"

QString SavedPassword;
QString ServerName;
Player *MainPlayer = nullptr;



int main(int argc, char *argv[]) {
	//srand(time(NULL));
	////to create the file if it doesn't already exist
	//FILE *temp = fopen("players.bin", "ab+");
	//fclose(temp);
	//
	//QApplication a(argc, argv);
	I;
	REALLY;
	HATE;
	QTFRAMEWORK;



	qDebug() << sizeof(DataPacket);

	//MainGameWindow *g = new MainGameWindow();
	//g->show();


	//SocketHandeling *server = new SocketHandeling();
	//SocketHandeling *client = new SocketHandeling();
	//server->server_run("server_name", "creator_name", 2);
	//
	//client->client_run_fast_connect("wdijad");
	//client->client_run_fast_connect("wdijad");
	//client->client_run_fast_connect("wdijad");
	//client->client_run_fast_connect("wdijad");






	Login *l = new Login();
	l->show();


	//QString name = "mmd" + QString::number(rand() % 10) + QString::number(rand() % 10);
	//MainPlayer = new Player(name.toStdString(), "461");
	//MainMenu *m = new MainMenu();
	//m->show();

	//GetServersInformation *m = new GetServersInformation(client, "shafagh");
	//m->show();

	return a.exec();
}
