#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QFontDatabase>
#include "player.h"
#include "changeinfo.h"
#include "getserversinformation.h"
#include "SocketHandeling.h"
#include "waitmenu.h"
#include "dinogame.h"
#include <shootinggame.h>


namespace Ui {
	class MainMenu;
}

class MainMenu: public QDialog {
	Q_OBJECT

public:
	explicit MainMenu(QWidget *parent = nullptr);
	~MainMenu();
	SocketHandeling *client;

private slots:

    void SetTexts();
	void on_change_info_clicked();
	void on_create_server_clicked();
	void on_ip_connect_clicked();
	void on_join_server_clicked();


	void on_pushButton_clicked();

	void on_join_server_2_clicked();

    void on_join_server_3_clicked();

public slots:
	void show_me();
	void server_joining_finished(bool is_connected);
signals:
	void show_parent();
private:
	int coins_first_place;
	bool *is_connected;
	WaitMenu *wait_menu;
	Ui::MainMenu *ui;



};

#endif // MAINMENU_H
