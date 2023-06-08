#include "login.h"

#include <QApplication>
#include "filehandeling.h"
#include <QtDebug>
#include <QDir>
#include "player.h"
Player* MainPlayer=nullptr;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();

   FileHandeling::read("salam.txt")[0];
    return a.exec();
}
