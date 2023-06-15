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

Player *MainPlayer = nullptr;

int main(int argc, char *argv[]) {

	//to create the file if it doesn't already exist
	FILE *temp = fopen("players.bin", "ab+");
	fclose(temp);

	QApplication a(argc, argv);
    Login *w = new Login;
    ChangeInfo* m=new ChangeInfo;
    m->show();
	w->show();

	return a.exec();
}
