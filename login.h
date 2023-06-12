#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QSound>
#include <thread>
#include "filehandeling.h"
#include "errors.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
private slots:
    void on_start_clicked();

    void on_login_clicked();

    void on_forgot_clicked();

private:
    std::thread * th;
    Ui::Login *ui;
};
#endif // LOGIN_H
