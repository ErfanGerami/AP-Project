#include "maingamewindow.h"
#include "ui_maingamewindow.h"

MainGameWindow::MainGameWindow(QWidget *parent):
	QDialog(parent),
	ui(new Ui::MainGameWindow) {
	ui->setupUi(this);
	ui->Graphics->setAlignment(Qt::Alignment(0));
	scene = new QGraphicsScene;
	ui->Graphics->setScene(scene);
	sticker_scene = new QGraphicsScene;
	ui->sticker_graphics->setScene(sticker_scene);

	//game_handeler = new GameHandeler(this, 2, ui->Graphics, scene, ui->sticker_graphics, sticker_scene, 0
	//, Player("ss", "s"), Player("s22", "s"), Player("s22", "s"), Player("s22", "s"));
	//game_handeler->TellTheFirst(1);
	//game_handeler->Deal();

	// game_handeler->collect(nullptr);


}

MainGameWindow::~MainGameWindow() {
	delete ui;
}

void MainGameWindow::on_pushButton_clicked() {
	game_handeler->AddStickers("cry", game_handeler->GetMe());


}


void MainGameWindow::on_pushButton_2_clicked() {
	game_handeler->AddStickers("happy", game_handeler->GetMe());

}



void MainGameWindow::on_pushButton_3_clicked() {
	game_handeler->AddStickers("wondered", game_handeler->GetMe());

}


void MainGameWindow::on_pushButton_4_clicked() {
	game_handeler->AddStickers("VeryHappy", game_handeler->GetMe());
}


void MainGameWindow::on_pushButton_5_clicked() {
	game_handeler->AddStickers("laugh", game_handeler->GetMe());
}


void MainGameWindow::on_pushButton_6_clicked() {
	game_handeler->AddStickers("sleep", game_handeler->GetMe());
}

