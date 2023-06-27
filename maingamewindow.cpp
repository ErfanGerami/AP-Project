#include "maingamewindow.h"
#include "ui_maingamewindow.h"

MainGameWindow::MainGameWindow(QWidget *parent):
	QDialog(parent),
	ui(new Ui::MainGameWindow) {
	ui->setupUi(this);
	ui->Graphics->setAlignment(Qt::Alignment(0));
	QGraphicsScene *scene = new QGraphicsScene;
	ui->Graphics->setScene(scene);
	GameHandeler *game_handeler = new GameHandeler(this, 4, ui->Graphics, scene, 0, Player("ss", "s"), Player("s22", "s"), Player("s22", "s"), Player("s22", "s"));
	//game_handeler->TellTheFirst(1);
	game_handeler->Deal();

	game_handeler->collect(nullptr);


}

MainGameWindow::~MainGameWindow() {
	delete ui;
}
