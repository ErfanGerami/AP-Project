#include "signup.h"
#include "ui_signup.h"
SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_agree_stateChanged(int arg1)
{
    if(this->ui->agree->isChecked()){
        this->ui->agree->setStyleSheet("#agree{color:white;font-size:20px;}");

    }else{
        this->ui->agree->setStyleSheet("#agree{color:red;font-size:20px;}");

    }
}


void SignUp::on_start_clicked()
{
    QString pass=ui->PassL->text();
    QString user=ui->UseL->text();
    QString adr=ui->adrL->text();
    QString phone_number=ui->phoneL->text();
    QString confirm=ui->ConfirmL->text();
    QString email=ui->emailL->text();
    bool agreed=ui->agree->isChecked();
    if(!agreed){
        QMessageBox::critical(this,"ERROR","You should agree to the terms first");
        return;
    }
    if(pass.indexOf('/')!=-1||user.indexOf('/')!=-1||adr.indexOf('/')!=-1||phone_number.indexOf('/')!=-1){
        QMessageBox::critical(this,"ERROR","The queries should not contain the character '/'");
        return;
    }
    if(FileHandeling::IsAPlayer(user)){
        QMessageBox::critical(this,"ERROR","A player with that name already exists(or the name is restricted or access to files is denied)");
        return;
    }
    if(confirm!=pass){
        QMessageBox::critical(this,"ERROR","Confirmed password and password doesnt match");
        return;
    }
    if(confirm!=pass){
        QMessageBox::critical(this,"ERROR","Confirmed password and password doesnt match");
        return;
    }
    if(email.indexOf('@')==-1){
        QMessageBox::critical(this,"ERROR","email address is not valid");
        return;

    }

    MainPlayer=new Player(user,pass,0,0,0,phone_number,adr,email,nullptr);

    FileHandeling::write(user,MainPlayer->Parse());


}

