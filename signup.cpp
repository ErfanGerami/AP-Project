#include "signup.h"
#include "ui_signup.h"


SignUp::SignUp(QWidget *parent):
	QDialog(parent),
	ui(new Ui::SignUp) {
	ui->setupUi(this);
}

SignUp::~SignUp() {
	delete ui;
}


void SignUp::on_agree_stateChanged(int arg1) {
	if ( this->ui->agree->isChecked() ) {
		this->ui->agree->setStyleSheet("#agree{color:white;font-size:20px;}");

	}
	else {
		this->ui->agree->setStyleSheet("#agree{color:red;font-size:20px;}");

	}
}


void SignUp::on_start_clicked() {
	QString pass = ui->passL->text();
	QString user = ui->userL->text();
	QString adr = ui->adrL->text();
	QString phone_number = ui->phoneL->text();
	QString confirm = ui->ConfirmL->text();
	QString email = ui->emailL->text();
	bool agreed = ui->agree->isChecked();


	//if ( !FileHandeling::is_players_file_open() )
	//	throw Errors(Errors::file_openning_error);

	if ( !agreed ) {
		QMessageBox::critical(this, "ERROR", "You should agree to the terms first");
		return;
	}
	/*if ( pass.indexOf('/') != -1 || user.indexOf('/') != -1 || adr.indexOf('/') != -1 || phone_number.indexOf('/') != -1 ) {
		QMessageBox::critical(this, "ERROR", "The queries should not contain the character '/'");
		return;
	}*/
	if ( !FileHandeling::is_user_unique(user) ) {
		QMessageBox::critical(this, "ERROR", "A player with that name already exists(or the name is restricted or access to files is denied)");
		return;
	}
	if ( confirm != pass ) {
		QMessageBox::critical(this, "ERROR", "Confirmed password and password doesnt match");
		return;
	}
	if ( email.indexOf('@') == -1 ) {
		QMessageBox::critical(this, "ERROR", "email address is not valid");
		return;

	}

	//MainPlayer = new Player(user, pass, 0, 0, 0, phone_number, adr, email, nullptr);// now player should login
	//FileHandeling::write(user, MainPlayer->Parse());


	Player *new_player = new Player(user.toStdString(), pass.toStdString(), 0, 0, 0, phone_number.toStdString(), adr.toStdString(), email.toStdString());
	FileHandeling::file_write(new_player);


}

