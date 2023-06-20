#include "serverselection.h"
#include "ui_serverselection.h"

ServerSelection::ServerSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerSelection)
{
    ui->setupUi(this);
}

ServerSelection::~ServerSelection()
{
    delete ui;
}
void ServerSelection::GetInfo(){

}
