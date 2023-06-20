#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QTcpServer>
#include <QTcpSocket>
#include <thread>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTcpServer* server;
    std::vector<std::pair<QString,std::pair<QString,int>>> name_ip_port;
    std::vector<std::thread> threads;
    void comminucate(QTcpSocket* socket);
private slots:

     void connecting();



};
#endif // MAINWINDOW_H
