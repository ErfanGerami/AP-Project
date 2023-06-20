#include "getserversinformation.h"
#include "ui_getserversinformation.h"

GetServersInformation::GetServersInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetServersInformation)
{
    ui->setupUi(this);
    //name_ip_port.push_back({"salam",{"salam",2}});
    GetInfo();
    UpdateList();
}


void GetServersInformation::GetInfo(){
    QTcpSocket* socket=new QTcpSocket;
    socket->connectToHost("127.0.0.1",1025);
    socket->waitForConnected(1000);
    socket->write("read");
    socket->waitForReadyRead(1000);
    QString message=socket->readAll();
    QStringList list=message.split("/");
    if(list.length()!=1)
        for(int i=0;i<list.length();i+=3){
            name_ip_port.push_back({list[i],{list[i+1],list[i+2].toInt()}});
        }


}

void GetServersInformation::UpdateList(){
    for(const auto& i:name_ip_port){
        ui->listWidget->addItem(i.first+' '+i.second.first+' '+QString::number(i.second.second));
    }
}
GetServersInformation::~GetServersInformation(){
    delete ui;


}



void GetServersInformation::on_GetServersInformation_finished(int result)
{


}

