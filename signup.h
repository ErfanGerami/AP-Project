#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QMessageBox>
#include "player.h"
#include "filehandeling.h"
#include <QCloseEvent>

extern Player *MainPlayer;

namespace Ui {
	class SignUp;
}

class SignUp: public QDialog {
	Q_OBJECT

public:
	explicit SignUp(QWidget *parent = nullptr);
	~SignUp();

private slots:
	void on_agree_stateChanged(int arg1);

	void on_start_clicked();

private:
	Ui::SignUp *ui;
	void do_show_parent();
protected:
	void closeEvent(QCloseEvent *event) override;

signals:
	void show_parent();
};

#endif // SIGNUP_H
