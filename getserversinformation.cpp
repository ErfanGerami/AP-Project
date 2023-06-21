#include "getserversinformation.h"
#include "ui_getserversinformation.h"
//for better reusablity and readability UpdateList and GetInfo work separately and totaly independed
GetServersInformation::GetServersInformation(QWidget *parent):
	QDialog(parent),
	ui(new Ui::GetServersInformation) {
	ui->setupUi(this);

	//name_ip_port.push_back({"salam",{"salam",2}});//test
	MainSocket = new QTcpSocket();
	ui->port->hide();
	ui->port_l->hide();
	ui->IP->hide();
	ui->IP_l->hide();

}


void GetServersInformation::GetInfo() {
	QTcpSocket *socket = new QTcpSocket;
	try {

		socket->connectToHost(ui->mai_servers_ip->text(), ui->mai_servers_port->text().toInt());

		if ( !socket->waitForConnected(3000) ) {
			throw Errors(Errors::cant_connect);
		}

		socket->write("read");

		socket->waitForBytesWritten(3000);

		if ( !socket->waitForReadyRead(3000) ) {
			throw Errors(Errors::cant_communicate);

		}

		QString message = socket->readAll();

		QStringList list = message.split(" ");

		if ( list.length() != 1 )
			for ( int i = 0; i + 1 < list.length(); i += 3 ) {
				name_ip_port.push_back({ list[i], { list[i + 1], list[i + 2].toInt() } });
			}

		socket->disconnect();



	}
	catch ( Errors err ) {
		QMessageBox::critical(this, "ERROR", err.what());
		socket->disconnect();
	}

	if ( socket != nullptr )
		delete socket;


}

void GetServersInformation::UpdateList() {

	ui->listWidget->clear();

	for ( const auto &i : name_ip_port ) {
		ui->listWidget->addItem(i.first + ' ' + i.second.first + ' ' + QString::number(i.second.second));
	}

}


GetServersInformation::~GetServersInformation() {
	delete ui;


}



void GetServersInformation::on_GetServersInformation_finished(int result) {


}



void GetServersInformation::on_reload_clicked() {
	GetInfo();
	UpdateList();
}


void GetServersInformation::on_checkBox_toggled(bool checked) {
	if ( checked ) {
		QPropertyAnimation *animation = new QPropertyAnimation(ui->connect, "geometry");
		animation->setStartValue(QRect(ui->connect->x(), ui->connect->y(), ui->connect->width(), ui->connect->height()));
		animation->setEndValue(QRect(ui->connect->x(), ui->connect->y() + 70, ui->connect->width(), ui->connect->height()));
		animation->setDuration(400);
		animation->start();
		ui->reload->setEnabled(false);
		ui->listWidget->setEnabled(false);
		connect(animation, &QPropertyAnimation::finished, [this] () {ui->port->show();
		ui->port_l->show();
		ui->IP->show();
		ui->IP_l->show(); });


	}
	else {
		QPropertyAnimation *animation = new QPropertyAnimation(ui->connect, "geometry");
		animation->setStartValue(QRect(ui->connect->x(), ui->connect->y(), ui->connect->width(), ui->connect->height()));
		animation->setEndValue(QRect(ui->connect->x(), ui->connect->y() - 70, ui->connect->width(), ui->connect->height()));
		animation->setDuration(400);
		animation->start();

		ui->reload->setEnabled(true);
		ui->listWidget->setEnabled(true);
		ui->port->hide();
		ui->port_l->hide();
		ui->IP->hide();
		ui->IP_l->hide();

	}
}


void GetServersInformation::on_connect_clicked() {

	try {
		if ( ui->checkBox->isChecked() ) {
			MainSocket->connectToHost(ui->IP->text(), ui->port->text().toInt());
			if ( !MainSocket->waitForConnected(3000) ) {

				throw Errors(Errors::cant_connect);
			}


		}
		else {
			MainSocket->connectToHost(ui->listWidget->selectedItems()[0]->text().split(' ')[1]
				, ui->listWidget->selectedItems()[0]->text().split(' ')[1].toInt());
			if ( !MainSocket->waitForConnected(3000) ) {

				throw Errors(Errors::cant_connect);
			}

		}


	}
	catch ( Errors err ) {
		QMessageBox::critical(this, "ERROR", err.what());


	}




}

