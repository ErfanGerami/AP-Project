#include "login.h"
#include "ui_login.h"




extern Player *MainPlayer;
Login::Login(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::Login) {
	ui->setupUi(this);
	QPropertyAnimation *anim = new QPropertyAnimation(ui->label, "geometry");
	anim->setDuration(1000);
	anim->setStartValue(QRect(-110, -110, 911, 720));
	anim->setEndValue(QRect(0, 0, 160, 100));
	anim->start();
	QSound::play(":/sounds/sounds/laugh.wav");
	QMediaPlayer *media = new QMediaPlayer();
	QMediaPlaylist *playlist = new QMediaPlaylist;
	playlist->addMedia(QUrl("qrc:/sounds/sounds/UiBackSound.mp3"));
	media->setPlaylist(playlist);
	media->setVolume(30);
	media->play();
	test *tst = new test;
	tst->show();






}



Login::~Login() {

	delete ui;
}


void Login::show_me() { this->show(); }



void Login::on_start_clicked() {
	sign = new SignUp(this);
	sign->show();
	this->hide();
}


void Login::on_login_clicked() {
	try {

		MainPlayer = FileHandeling::file_read(ui->user->text(), ui->pass->text());

	}
	catch ( Errors err ) {
		ui->statusbar->setStyleSheet("#statusbar{color:red;}");
		//ui->statusbar->showMessage("user not found or access denied");
		QMessageBox::critical(this, "ERROR", err.what());
		QApplication::beep();


	}
}


void Login::on_forgot_clicked() {
	forgot_password = new ForgotMyPassword(this);
	forgot_password->show();
	this->hide();
}

