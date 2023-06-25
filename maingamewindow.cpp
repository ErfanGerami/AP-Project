#include "maingamewindow.h"
#include "ui_maingamewindow.h"

MainGameWindow::MainGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainGameWindow)
{
    ui->setupUi(this);
}

MainGameWindow::~MainGameWindow()
{
    delete ui;
}
