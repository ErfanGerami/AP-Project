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
QString SavedPassword;
Player *MainPlayer = nullptr;
QTcpSocket *MainSocket;

int main(int argc, char *argv[]) {
    srand(time(NULL));
	//to create the file if it doesn't already exist
	FILE *temp = fopen("players.bin", "ab+");
	fclose(temp);

	QApplication a(argc, argv);


    MainMenu* g=new MainMenu;
    g->show();



	return a.exec();
}
