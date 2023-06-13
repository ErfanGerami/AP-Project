#include "login.h"
#include "ui_login.h"
#include <QAbstractAnimation>
#include <QPropertyAnimation>
#include <QVBoxLayout>
#include "player.h"
#include "game.h"
#include "signup.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "forgotmypassword.h"
#include "test.h"

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
    test* tst=new test;
    tst->show();






}



Login::~Login()
{

    delete ui;
}







void Login::on_start_clicked()
{
    SignUp* sign=new SignUp();
    sign->show();
}


void Login::on_login_clicked()
{
    try{
        auto vec=FileHandeling::read(ui->user->text()+".txt");
        Game* prev;
        if(vec[7]!="null")
            prev=new Game(vec[8],vec[9]);
        else

            prev=nullptr;
        MainPlayer=new Player(vec[0],vec[1],vec[2].toInt(),vec[3].toInt(),vec[4].toInt(),vec[5],vec[6],vec[7],prev);

    }catch(Errors err){
        ui->statusbar->setStyleSheet("#statusbar{color:red;}");
        ui->statusbar->showMessage("user not found or access denied");
        QApplication::beep();


    }
}


void Login::on_forgot_clicked()
{
    ForgotMyPassword* forgot_password=new ForgotMyPassword();
    forgot_password->show();
}

