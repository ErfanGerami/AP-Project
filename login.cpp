#include "login.h"
#include "ui_login.h"
#include <QAbstractAnimation>
#include <QPropertyAnimation>
#include <QVBoxLayout>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    QPropertyAnimation* anim=new QPropertyAnimation(ui->label,"geometry");
    anim->setDuration(1000);
    anim->setStartValue(QRect(-110,-110,911,720));
    anim->setEndValue(QRect(0,0,160,100));
    anim->start();
    QSound::play(":/sounds/sounds/laugh.wav");




}



Login::~Login()
{
    delete ui;
}






