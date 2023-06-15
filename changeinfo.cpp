#include "changeinfo.h"
#include "ui_changeinfo.h"

ChangeInfo::ChangeInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeInfo)
{
    ui->setupUi(this);
    ui->pass->hide();
    ui->passL->hide();
    ui->user->hide();
    ui->userL->hide();
    ui->email->hide();
    ui->confirm->hide();
    ui->emailL->hide();
    ui->phone->hide();
    ui->phoneL->hide();
}

ChangeInfo::~ChangeInfo()
{
    delete ui;
}



void ChangeInfo::on_user_check_toggled(bool checked)
{
   if(checked)
        ui->user_check->setStyleSheet("border-style:solid; background-color: rgba(3, 72, 3,100); color:white;font-size:17px;");
    else
        ui->user_check->setStyleSheet("border-style:solid; background-color: rgba(72, 3, 3,100); color:white;font-size:17px;");


}





void ChangeInfo::on_pass_check_toggled(bool checked)
{
    if(checked)
         ui->pass_check->setStyleSheet("border-style:solid; background-color: rgba(3, 72, 3,100); color:white;font-size:17px;");
     else
         ui->pass_check->setStyleSheet("border-style:solid; background-color: rgba(72, 3, 3,100); color:white;font-size:17px;");

}


void ChangeInfo::on_email_check_toggled(bool checked)
{
    if(checked)
         ui->email_check->setStyleSheet("border-style:solid; background-color: rgba(3, 72, 3,100); color:white;font-size:17px;");
     else
         ui->email_check->setStyleSheet("border-style:solid; background-color: rgba(72, 3, 3,100); color:white;font-size:17px;");

}





void ChangeInfo::on_phone_check_toggled(bool checked)
{
    if(checked)
         ui->phone_check->setStyleSheet("border-style:solid; background-color: rgba(3, 72, 3,100); color:white;font-size:17px;");
     else
         ui->phone_check->setStyleSheet("border-style:solid; background-color: rgba(72, 3, 3,100); color:white;font-size:17px;");

}

