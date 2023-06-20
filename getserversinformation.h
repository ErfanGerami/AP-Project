#ifndef GETSERVERSINFORMATION_H
#define GETSERVERSINFORMATION_H
#include <QMessageBox>
#include <QDialog>
#include <vector>
#include <QTcpSocket>
#include <QDebug>
namespace Ui {
class GetServersInformation;
}

class GetServersInformation : public QDialog
{
    Q_OBJECT

public:
    explicit GetServersInformation(QWidget *parent = nullptr);
    ~GetServersInformation();


private slots:

    void on_GetServersInformation_finished(int result);

private:
    Ui::GetServersInformation *ui;
    std::vector<std::pair<QString,std::pair<QString,int>>> name_ip_port;
    void GetInfo();
    void UpdateList();
};

#endif // GETSERVERSINFORMATION_H
