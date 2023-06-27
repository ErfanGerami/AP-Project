#include "getserversinformation.h"
#include "ui_getserversinformation.h"
//for better reusablity and readability UpdateList and GetInfo work separately and totaly independed
GetServersInformation::GetServersInformation(SocketHandeling *connection, QString client_name, QWidget *parent):
	QDialog(parent),
	ui(new Ui::GetServersInformation) {
	ui->setupUi(this);



	this->is_connected = is_connected;
	this->client_name = client_name;


	connect(this, SIGNAL(show_parent(bool)), parent, SLOT(server_joining_finished(bool)));


}




GetServersInformation::~GetServersInformation() {
	delete ui;


}


void GetServersInformation::on_reload_clicked() {
	connection = new SocketHandeling();

	server_map = connection->get_servers();


	UpdateList();
}

void GetServersInformation::UpdateList() {

	ui->listWidget->clear();

	int ctr = 1;
	for ( auto i = server_map.begin(); i != server_map.end(); i++, ctr++ ) {
		auto a = i.key();
		ui->listWidget->addItem(QString::number(ctr) + "- name: " + i.value().first + "| creator: " + i.value().second + "| ip:" + i.key().toString());
	}

}


void GetServersInformation::on_connect_clicked() {

	try {
		if ( server_map.size() < ui->server_number->text().toInt() )
			throw Errors(Errors::invalid_server_number);

		auto it = server_map.begin();

		for ( int i = 1; i < ui->server_number->text().toInt(); i++, it++ );

		QHostAddress ip = it.key();

		connection->client_run(ip, client_name);


		if ( connection->is_client_connected() ) {
			QMessageBox::information(this, "success", "connection successfull");
			is_connected = true;
		}
		else {
			QMessageBox::information(this, "failure", "connection failed");
			is_connected = false;
		}
		this->close();


	}
	catch ( Errors err ) {
		QMessageBox::critical(this, "ERROR", err.what());
	}

}

void GetServersInformation::closeEvent(QCloseEvent *event) {

	if ( event->spontaneous() ) {
		emit show_parent(is_connected);
	}
	else {
		QWidget::closeEvent(event);
		emit show_parent(is_connected);

	}
}
