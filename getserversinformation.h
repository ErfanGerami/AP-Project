#ifndef GETSERVERSINFORMATION_H
#define GETSERVERSINFORMATION_H
#include <QMessageBox>
#include <QDialog>
#include <vector>
#include <QTcpSocket>
#include <QDebug>
#include <QPropertyAnimation>
#include <QTcpSocket>
#include "errors.h"
#include "SocketHandeling.h"
#include <QMap>
#include <QCloseEvent>


extern QString ServerName;
namespace Ui {

	class GetServersInformation;
}
class GetServersInformation: public QDialog {
	Q_OBJECT

public:
	explicit GetServersInformation(SocketHandeling *connection, QString client_name, QWidget *parent = nullptr);
	~GetServersInformation();


private slots:



	void on_reload_clicked();



	void on_connect_clicked();

private:
	bool is_connected;
	SocketHandeling *connection;
	QMap<QHostAddress, QPair<QString, QString>> server_map;

	QString client_name;

	Ui::GetServersInformation *ui;
	std::vector<std::pair<QString, std::pair<QString, int>>> name_ip_port;

	void UpdateList();


	void closeEvent(QCloseEvent *event) override;

signals:
	void show_parent(bool);
};

#endif // GETSERVERSINFORMATION_H
