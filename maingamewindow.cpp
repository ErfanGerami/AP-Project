#include "maingamewindow.h"
#include "ui_maingamewindow.h"


MainGameWindow::MainGameWindow(SocketHandeling *connection, SocketHandeling *client, QVector<QString> name_vec, QWidget *parent):
	QDialog(parent),
	ui(new Ui::MainGameWindow) {
	ui->setupUi(this);
	setFixedSize(size());
	ui->Graphics->setAlignment(Qt::Alignment(0));

	scene = new QGraphicsScene;
	ui->Graphics->setScene(scene);
	QGraphicsItemGroup *fixedItemsGroup = new QGraphicsItemGroup;
	fixedItemsGroup->setHandlesChildEvents(false);
	scene->addItem(fixedItemsGroup);

	ui->Graphics->setAlignment(Qt::AlignLeft | Qt::AlignTop);

	sticker_scene = new QGraphicsScene;
	ui->sticker_graphics->setScene(sticker_scene);




    int player_count = name_vec.size();

    while ( name_vec.size() < 4 )
        name_vec.push_back("");
	if ( connection->am_i_the_server() ) {
		server = connection;
		this->client = client;



        Logic *logic = new Logic(server, PlayerInGame(Player(name_vec[0].toStdString(), ""), this, 0,{},0)
                , PlayerInGame(Player(name_vec[1].toStdString(), ""), this, 1,{},0),player_count,
                 PlayerInGame(Player(name_vec[2].toStdString(), ""),this,2,{},0)
                , PlayerInGame(Player(name_vec[3].toStdString(), ""), this, 3,{},0));

        game_handeler = new GameHandeler(this, nullptr, 4, ui->Graphics, scene, ui->sticker_graphics, sticker_scene, 0
            , Player(name_vec[0].toStdString(), ""), Player(name_vec[1].toStdString(), ""), Player(name_vec[2].toStdString(), "")
                , Player(name_vec[3].toStdString(), ""));




	}
	else {
		this->client = client;
        int me;
        for(int i=0;i<name_vec.size();i++){
            if(name_vec[i].toStdString()==MainPlayer->GetUserName()){
                me=i;
                break;
            }
        }

        game_handeler = new GameHandeler(this, nullptr, 4, ui->Graphics, scene, ui->sticker_graphics, sticker_scene, me
            , Player(name_vec[0].toStdString(), ""), Player(name_vec[1].toStdString(), ""), Player(name_vec[2].toStdString(), "")
                , Player(name_vec[3].toStdString(), ""));




	}















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

