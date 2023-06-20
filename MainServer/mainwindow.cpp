#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent):
	QMainWindow(parent),
	ui(new Ui::MainWindow) {
	ui->setupUi(this);


	name_ip_port.push_back({ "sal", { "sala", 1 } });
	server = new QTcpServer;
	server->listen(QHostAddress::Any, 1025);
	if ( !server->isListening() ) {
		ui->textEdit->append("SERVER IS DOWN\n");
		return;
	}
	else {
		ui->textEdit->append("SERVER IS LISTENNING\n");
		connect(server, SIGNAL(newConnection()), this, SLOT(connecting()));


	}
}
void MainWindow::connecting() {
	QTcpSocket *socket = server->nextPendingConnection();

	threads.push_back(std::thread(&MainWindow::comminucate, this, socket));

}
void MainWindow::comminucate(QTcpSocket *socket) {
	socket->waitForReadyRead(1000);
	QString message = socket->readAll();
	if ( message == "read" ) {
		ui->textEdit->append("a client has arrived to read info\n");
		QString all = "";
		for ( const auto &i : name_ip_port ) {
			all += i.first + '/' + i.second.first + '/' + QString::number(i.second.second);

		}
		socket->write(all.toStdString().c_str());
		socket->waitForBytesWritten(1000);
	}

	else if ( message == "add" ) {
		ui->textEdit->append("a client has arrived to add info\n");
		socket->waitForReadyRead(1000);


		QString ip_port_string = socket->readAll();
		qDebug() << ip_port_string;
		name_ip_port.push_back({ ip_port_string.split('/')[0], { ip_port_string.split('/')[1], ip_port_string.split('/')[2].toInt() } });

	}
	else if ( message == "remove" ) {
		ui->textEdit->append("a client has arrived to remove info\n");
		socket->waitForReadyRead(1000);


		QString name = socket->readAll();

		for ( std::vector<std::pair<QString, std::pair<QString, int>>>::iterator iterator = name_ip_port.begin();
			iterator != name_ip_port.end(); iterator++ ) {
			if ( iterator->first == name ) {
				name_ip_port.erase(iterator);
				name_ip_port.shrink_to_fit();
				break;
			}

		}



	}
	socket->disconnect();

}
MainWindow::~MainWindow() {
	for ( auto &i : threads ) {
		i.join();
	}
}
