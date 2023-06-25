#include "maingamewindow.h"
#include "ui_maingamewindow.h"

MainGameWindow::MainGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainGameWindow)
{
    ui->setupUi(this);
    QGraphicsScene* scene = new QGraphicsScene;
    ui->Graphics->setScene(scene);
    GameHandeler* game_handeler = new GameHandeler(4, ui->Graphics, scene, Player("ss", "s"), Player("s22", "s"), Player("s22", "s"), Player("s22", "s"));
    //game_handeler->TellTheFirst("ss");
    game_handeler->Deal();
    
}

MainGameWindow::~MainGameWindow()
{
    delete ui;
}
