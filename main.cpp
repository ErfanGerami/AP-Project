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
	srand(time(NULL));
	//to create the file if it doesn't already exist
	FILE *temp = fopen("players.bin", "ab+");
	fclose(temp);

	QApplication a(argc, argv);


    MainGameWindow *g = new MainGameWindow;
    g->show();


	//SocketHandeling *server = new SocketHandeling();
	//server->server_run("server_name", "creator_name", 2);


	//SocketHandeling *client = new SocketHandeling();

    //Login *l = new Login();
    //l->show();




	//GetServersInformation *m = new GetServersInformation(client, "shafagh");
	//m->show();

	return a.exec();
}
