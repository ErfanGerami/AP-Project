#include "mainmenu.h"
#include "ui_mainmenu.h"

extern Player *MainPlayer;
extern QString ServerName;

MainMenu::MainMenu(QWidget *parent):
	QDialog(parent),
	ui(new Ui::MainMenu) {

	ui->setupUi(this);
	setFixedSize(size());
	ui->name->setText(QString(MainPlayer->GetUserName().c_str()));
	if ( MainPlayer->GetPrevGame().GetIsPlayed() ) {
		ui->no_games1->hide();
		ui->no_games2->hide();
		ui->score_show->setText(QString::number(MainPlayer->GetPrevGame().GetScore()));
		ui->winner_show->setText(QString(MainPlayer->GetPrevGame().GetWinner().c_str()));
		ui->time_show->setText(QString(MainPlayer->GetPrevGame().GetTime().c_str()));
		ui->won->setText(QString::number(MainPlayer->GetGamesWon()));
		ui->lost->setText(QString::number(MainPlayer->GetGamesLoose()));
		ui->coin->setText(QString::number(MainPlayer->GettCoins()));
		ui->coin_pic->move(ui->coin_pic->x() + QString::number(MainPlayer->GettCoins()).length() * 15, ui->coin_pic->y());
	}
	else {
		ui->time->hide();
		ui->time_show->hide();
		ui->prev->hide();
		ui->score->hide();
		ui->score_show->hide();
		ui->winner->hide();
		ui->winner_show->hide();
		ui->line_4->hide();
		ui->line_10->hide();
		ui->line_9->hide();
		ui->line_7->hide();
		ui->line_1->hide();
		ui->won->setText("0");
		ui->lost->setText("0");
		ui->won->setText("1000");
	}





}

MainMenu::~MainMenu() {
	delete ui;

}

void MainMenu::on_create_server_clicked() {
	try {

		SocketHandeling *server = new SocketHandeling();

		server->server_run(ui->server_name->text(), QString::fromStdString(MainPlayer->GetUserName()), ui->player_count->text().toInt());

		if ( server->is_server_connected() ) {
			//show next window

			client = new SocketHandeling();
			client->client_run(QHostAddress("127.0.0.1"), server->get_name());
			wait_menu = new WaitMenu(server, client, this);
			this->hide();
			wait_menu->show();
		}
		else {
			QMessageBox::critical(this, "error", "failed to create server");
		}
	}
	catch ( Errors err ) {
		QMessageBox::critical(this, "error", err.what());
	}
}

void MainMenu::on_join_server_clicked() {


	try {

		client = new SocketHandeling();
		//
		client->client_run_fast_connect(QString::fromStdString(MainPlayer->GetUserName()));
		wait_menu = new WaitMenu(client, this);
		//
		wait_menu->show();
		this->hide();
		//GetServersInformation *m = new GetServersInformation(client, QString::fromStdString(MainPlayer->GetUserName()), this);
		//m->show();
		//wait_menu->show();

	}
	catch ( Errors err ) {
		QMessageBox::critical(this, "error", err.what());
	}

}

void MainMenu::server_joining_finished(bool is_connected) {
	if ( is_connected ) {
		//show next window
		//wait_menu = new WaitMenu(client, this);

		this->hide();

	}
	else {
		QMessageBox::critical(this, "error", "failed to connect to server");
	}

}



void MainMenu::on_change_info_clicked() {
	ChangeInfo *change_win = new ChangeInfo(this);
	this->hide();
	change_win->show();

}


void MainMenu::show_me() {
	this->show();
	ui->name->setText(QString(MainPlayer->GetUserName().c_str()));
	if ( MainPlayer->GetPrevGame().GetIsPlayed() ) {
		ui->no_games1->hide();
		ui->no_games2->hide();
		ui->score_show->setText(QString::number(MainPlayer->GetPrevGame().GetScore()));
		ui->winner_show->setText(QString(MainPlayer->GetPrevGame().GetWinner().c_str()));
		ui->time_show->setText(QString(MainPlayer->GetPrevGame().GetTime().c_str()));
		ui->won->setText(QString::number(MainPlayer->GetGamesWon()));
		ui->lost->setText(QString::number(MainPlayer->GetGamesLoose()));
		ui->coin->setText(QString::number(MainPlayer->GettCoins()));
		ui->coin_pic->move(ui->coin_pic->x() + QString::number(MainPlayer->GettCoins()).length() * 15, ui->coin_pic->y());
	}
	else {
		ui->time->hide();
		ui->time_show->hide();
		ui->prev->hide();
		ui->score->hide();
		ui->score_show->hide();
		ui->winner->hide();
		ui->winner_show->hide();
		ui->line_4->hide();
		ui->line_10->hide();
		ui->line_9->hide();
		ui->line_7->hide();
		ui->line_1->hide();
		ui->won->setText("0");
		ui->lost->setText("0");
		ui->won->setText("1000");
	}

}

