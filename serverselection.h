#ifndef SERVERSELECTION_H
#define SERVERSELECTION_H

#include <QDialog>
#include <QTcpSocket>
#include <vector>

namespace Ui {
class ServerSelection;
}

class ServerSelection : public QDialog
{
    Q_OBJECT

public:
    explicit ServerSelection(QWidget *parent = nullptr);
    ~ServerSelection();

private:
    Ui::ServerSelection *ui;
    std::vector<QString,int> ip_port;
    void GetInfo();
};

#endif // SERVERSELECTION_H
