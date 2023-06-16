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


void ChangeInfo::on_submit_clicked()
{
    string username=MainPlayer->GetUserName();
    string phone_number=MainPlayer->GetPhonNnumber();
    string email=MainPlayer->GetEmail();
    unsigned long confirm=MainPlayer->GetPassWord();
    unsigned long password=MainPlayer->GetPassWord();


    if(ui->user_check->isChecked()){
        username=ui->user->text().toStdString();
    }
    //notice that if username is changed the hashed password must be changed too so the password is hashed using
    //the new username a
    if(ui->pass_check->isChecked()){
        password=Player::hash(ui->pass->text().toStdString(),username);
         password=Player::hash(ui->confirm->text().toStdString(),username);
    }
    if(ui->email_check->isChecked()){
        email=ui->email->text().toStdString();
    }
    if(ui->phone_check->isChecked()){
        phone_number=ui->phone->text().toStdString();

    }

    try {
        if ( !FileHandeling::is_players_file_open() )
            throw Errors(Errors::file_openning_error);


        if ( !FileHandeling::is_user_unique(QString(username.c_str()) ))
            throw Errors(Errors::username_not_unique);

        if ( confirm != password )
            throw Errors(Errors::inputed_passwords_dont_match);

        if ( QString(email.c_str()).indexOf('@') == -1 )
            throw Errors(Errors::invalid_email);

    }

    catch ( Errors err ) {
        QMessageBox::critical(this, "ERROR", err.what());
        return;
    }
}

