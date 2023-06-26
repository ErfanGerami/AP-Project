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
Player *MainPlayer = nullptr;
QTcpSocket *MainSocket;

int main(int argc, char *argv[]) {
	srand(time(NULL));
	//to create the file if it doesn't already exist
	FILE *temp = fopen("players.bin", "ab+");
	fclose(temp);

	QApplication a(argc, argv);


	MainGameWindow *g = new MainGameWindow;
	g->show();

	//Login l = new Login();
	//l.show();


	return a.exec();
}
