#include "login.h"
#include "ui_login.h"
#include <QAbstractAnimation>
#include <QPropertyAnimation>
#include <QVBoxLayout>
#include "player.h"
#include "game.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
extern Player* MainPlayer;
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
    QMediaPlayer* media=new QMediaPlayer();
    QMediaPlaylist* playlist=new QMediaPlaylist;
    playlist->addMedia(QUrl("qrc:/sounds/sounds/UiBackSound.mp3"));
    media->setPlaylist(playlist);
    media->setVolume(30);
    media->play();







}



Login::~Login()
{

    delete ui;
}







void Login::on_start_clicked()
{

}


void Login::on_login_clicked()
{
    try{
        auto vec=FileHandeling::read(ui->user->text()+".txt");
        Game* prev=new Game(vec[5],vec[6]);
        MainPlayer=new Player(vec[0],vec[1],vec[2].toInt(),vec[3].toInt(),vec[4].toInt(),prev);

    }catch(Errors err){
        ui->statusbar->setStyleSheet("#statusbar{color:red;}");
        ui->statusbar->showMessage("user not found or access denied");
        QApplication::beep();


    }
}

