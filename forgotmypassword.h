#ifndef FORGOTMYPASSWORD_H
#define FORGOTMYPASSWORD_H

#include <QDialog>
#include <QPropertyAnimation>
#include "filehandeling.h"

namespace Ui {
	class ForgotMyPassword;
}

class ForgotMyPassword: public QDialog {
	Q_OBJECT

public:
	explicit ForgotMyPassword(QWidget *parent = nullptr);
	~ForgotMyPassword();
	void EndOfFadingOut();
	void AnimationAfterFadingIn();

private slots:
	void on_check_clicked();
	void on_confirm_clicked();
private:
	Ui::ForgotMyPassword *ui;
};

#endif // FORGOTMYPASSWORD_H
