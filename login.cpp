#include "login.h"
#include "ui_login.h"




Login::Login(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::Login) {
	ui->setupUi(this);
	setFixedSize(size());
	QPropertyAnimation *anim = new QPropertyAnimation(ui->label, "geometry");
	anim->setDuration(1000);
	anim->setStartValue(QRect(-110, -110, 911, 720));
	anim->setEndValue(QRect(0, 0, 160, 100));
	anim->start();
	QSound::play(":/sounds/sounds/laugh.wav");
	media = new QMediaPlayer();
	QMediaPlaylist *playlist = new QMediaPlaylist;


	playlist->addMedia(QUrl("qrc:/sounds/sounds/UiBackSound.mp3"));

	/*playlist->addMedia(QUrl("qrc:/sounds/sounds/Skull_King_Start.wav"));
	playlist->addMedia(QUrl("qrc:/sounds/sounds/Skull_King_Loop.wav"));
	playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

	media->setPlaylist(playlist);
	media->setVolume(30);
	ui->horizontalSlider->setValue(30);
	media->play();

	QObject::connect(media, &QMediaPlayer::mediaStatusChanged, [=] (QMediaPlayer::MediaStatus status) {
		if ( status == QMediaPlayer::EndOfMedia ) {
			playlist->setCurrentIndex(1);
			media->play();
		}
		});*/


	media->setPlaylist(playlist);
	media->setVolume(30);
	ui->horizontalSlider->setValue(30);
	media->play();
	connect(media, &QMediaPlayer::stateChanged, [this] () {media->play(); });







}



Login::~Login() {

	delete ui;
}


void Login::show_me() { this->show(); ui->pass->setText(""); ui->user->setText(""); }



void Login::on_start_clicked() {
	sign = new SignUp(this);
	sign->show();
	this->hide();
}


void Login::on_login_clicked() {
	try {

		MainPlayer = FileHandeling::file_read(ui->user->text(), ui->pass->text());
		SavedPassword = ui->pass->text();
		MainMenu *main_menu = new MainMenu(this);
		main_menu->show();
		this->hide();

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


void Login::on_horizontalSlider_valueChanged(int value) {
	media->setVolume(value);
}

