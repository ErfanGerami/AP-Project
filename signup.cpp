#include "signup.h"
#include "ui_signup.h"


SignUp::SignUp(QWidget *parent):
	QDialog(parent),
	ui(new Ui::SignUp) {
	ui->setupUi(this);

	connect(this, SIGNAL(show_parent()), parent, SLOT(show_me()));

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


	/*if ( pass.indexOf('/') != -1 || user.indexOf('/') != -1 || adr.indexOf('/') != -1 || phone_number.indexOf('/') != -1 ) {
		QMessageBox::critical(this, "ERROR", "The queries should not contain the character '/'");
		return;
	}*/

	try {
		if ( !FileHandeling::is_players_file_open() )
			throw Errors(Errors::file_openning_error);

		if ( !agreed )
			throw Errors(Errors::not_agreed_with_terms);

		if ( !FileHandeling::is_user_unique(user) )
			throw Errors(Errors::username_not_unique);

		if ( confirm != pass )
			throw Errors(Errors::inputed_passwords_dont_match);

		if ( email.indexOf('@') == -1 )
			throw Errors(Errors::invalid_email);

	}
	catch ( Errors err ) {
		QMessageBox::critical(this, "ERROR", err.what());
		return;
	}

	//MainPlayer = new Player(user, pass, 0, 0, 0, phone_number, adr, email, nullptr);// now player should login
	//FileHandeling::write(user, MainPlayer->Parse());


    Player *new_player = new Player(user.toStdString(), pass.toStdString(), 0, 0, 0, phone_number.toStdString(), adr.toStdString(), email.toStdString(),1000);
	FileHandeling::file_write(new_player);

	this->close();
	emit show_parent();
}

void SignUp::do_show_parent() {
	emit show_parent();
}

void SignUp::closeEvent(QCloseEvent *event) {

	if ( event->spontaneous() ) {
		emit show_parent();
	}
	else {
		QWidget::closeEvent(event);
	}
}