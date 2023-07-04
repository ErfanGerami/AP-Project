#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QSound>
#include <thread>
#include "filehandeling.h"
#include "errors.h"
#include <QAbstractAnimation>
#include <QPropertyAnimation>
#include <QVBoxLayout>
#include "player.h"
#include "game.h"
#include "signup.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "forgotmypassword.h"
#include "mainmenu.h"
#include "SocketHandeling.h"

extern QString SavedPassword;
extern Player *MainPlayer;

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login: public QMainWindow {
	Q_OBJECT

public:
	Login(QWidget *parent = nullptr);
	~Login();
private slots:
	void on_start_clicked();

	void on_login_clicked();

	void on_forgot_clicked();


	void on_horizontalSlider_valueChanged(int value);

private:

	std::thread *th;
	Ui::Login *ui;
	ForgotMyPassword *forgot_password;
	SignUp *sign;
	SocketHandeling *s;
	SocketHandeling *t;
public slots:
	void show_me();

};
#endif // LOGIN_H
