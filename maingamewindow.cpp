#include "maingamewindow.h"
#include "ui_maingamewindow.h"



MainGameWindow::MainGameWindow(SocketHandeling *connection, QVector<QString> name_vec, SocketHandeling *client, QWidget *parent):
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


	QLabel *arrows[4] = { ui->arrow0, ui->arrow2, ui->arrow1,
		ui->arrow3 };
	for ( int i = 0; i < 4; i++ ) {
		arrows[i]->hide();
	}
	QLabel *stars[4] = { ui->star_0, ui->star_1, ui->star_2, ui->star_3 };
	for ( int i = 0; i < 4; i++ ) {
		stars[i]->hide();
	}



	int me;

	if ( connection->am_i_the_server() ) {
		//server side
		server = connection;
		this->client = client;
		me = 0;


		//client->reading_data_socket();
		client->get_tcp_socket()->readAll();



		logic = new Logic(server, ServerPlayerInGame(name_vec[0].toStdString(), "")
			, ServerPlayerInGame(name_vec[1].toStdString(), ""), player_count,
			ServerPlayerInGame(name_vec[2].toStdString(), "")
			, ServerPlayerInGame(name_vec[3].toStdString(), ""));



		//t.start();

		//logic_thread = std::thread { &Logic::StartGame, logic };
		//logic->StartGame();
		logic->start();

	}
	else {
		//client side
		this->client = connection;
		for ( int i = 0; i < player_count; i++ ) {
			if ( name_vec[i].toStdString() == MainPlayer->GetUserName() ) {
				me = i;
				break;
			}
		}
	}

	game_handeler = new GameHandeler(this, ui->score, stars, arrows, this->client, player_count, ui->Graphics, scene, ui->sticker_graphics, sticker_scene, me
		, Player(name_vec[0].toStdString(), ""), Player(name_vec[1].toStdString(), ""), Player(name_vec[2].toStdString(), "")
		, Player(name_vec[3].toStdString(), ""));

	game_handeler->StartSet();
	this->me = me;
	for ( int i = me + 1; i < player_count + me; i++ ) {
		ui->comboBox->addItem(name_vec[i % player_count]);
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


void MainGameWindow::on_pushButton_7_clicked() {
	game_handeler->SwapCard(me + ui->comboBox->currentIndex());
}


void MainGameWindow::on_pushButton_8_clicked() {

}


void MainGameWindow::on_pause_clicked() {
	game_handeler->MyPause();
}

