#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QFontDatabase>
#include "player.h"
#include "changeinfo.h"
#include "getserversinformation.h"
#include "SocketHandeling.h"
#include "waitmenu.h"


namespace Ui {
	class MainMenu;
}

class MainMenu: public QDialog {
	Q_OBJECT

public:
	explicit MainMenu(QWidget *parent = nullptr);
	~MainMenu();

private slots:

	void on_change_info_clicked();
	void on_create_server_clicked();
	void on_join_server_clicked();


public slots:
	void show_me();
	void server_joining_finished(bool is_connected);

private:
	bool *is_connected;
	WaitMenu *wait_menu;
	SocketHandeling *client;
	Ui::MainMenu *ui;



};

#endif // MAINMENU_H
