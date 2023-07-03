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

	I;
	REALLY;
	HATE;
	QTFRAMEWORK;


	Login *login = new Login();
	login->show();




	return a.exec();
}
