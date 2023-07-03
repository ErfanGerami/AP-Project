#include "waitmenu.h"
#include "ui_waitmenu.h"
#include "channel.h"

WaitMenu::WaitMenu(SocketHandeling *connection, SocketHandeling *client_, QWidget *parent):
	QDialog(parent),
	ui(new Ui::WaitMenu) {
	ui->setupUi(this);
	setFixedSize(size());

	am_i_server = connection->am_i_the_server();

	server = connection;
	client = client_;
	player_count = server->get_player_count();
	connect(server, SIGNAL(newplayer(QString)), this, SLOT(new_player(QString)));




	this->scene = new QGraphicsScene(ui->graphicsView);



	for ( int i = 0; i < 100; i++ ) {
		QLabel *label = new QLabel;
		QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget;
		proxy->setWidget(label);
		proxy->setPos(rand() % (ui->graphicsView->width() - 100), rand() % (ui->graphicsView->height() - 100));
		int size = rand() % 30 + 10;
		proxy->resize(size, size);

		scene->addItem(proxy);
		QPropertyAnimation *anim = new QPropertyAnimation(proxy, "rotation");
		anim->setDuration(rand() % 1500 + 500);
		anim->setStartValue(proxy->rotation());
		anim->setEndValue(rand() % 360); anim->start();
		anim->setDuration(1000);

		QPropertyAnimation *anim2 = new QPropertyAnimation(proxy, "rotation");

		QPropertyAnimation *anim3 = new QPropertyAnimation(proxy, "geometry");

		label->setStyleSheet("background-color:rgba(" + QString::number(rand() % 255) +
			"," + QString::number(rand() % 255)
			+ "," + QString::number(rand() % 255)
			+ "," + QString::number(rand() % 100 + 155) + ");");

		connect(anim, &QPropertyAnimation::finished, [this, anim2, proxy] {anim2->setDuration(rand() % 1500 + 500);
		anim2->setStartValue(proxy->rotation());
		anim2->setEndValue(rand() % 360);
		anim2->start(); });
		connect(anim3, &QPropertyAnimation::finished, [this, anim, proxy] {anim->setDuration(rand() % 1500 + 500);
		anim->setStartValue(proxy->rotation());
		anim->setEndValue(rand() % 360); anim->start(); });
		connect(anim2, &QPropertyAnimation::finished, [this, anim3, proxy] {anim3->setDuration(rand() % 1500 + 500);
		anim3->setStartValue(QRect(proxy->x(), proxy->y(), proxy->boundingRect().width(), proxy->boundingRect().height()));
		int size = (rand() % 30 + 10); anim3->setEndValue(QRect(rand() % (ui->graphicsView->width() - 100), rand() % (ui->graphicsView->height() - 100), size, size));
		anim3->start(); });

		anim->start();
	}

	ui->graphicsView->setScene(scene);
	ui->graphicsView->show();

}

WaitMenu::WaitMenu(SocketHandeling *client_, QWidget *parent):
	QDialog(parent),
	ui(new Ui::WaitMenu) {
	ui->setupUi(this);
	setFixedSize(size());

	client = client_;
	bool s = connect(client->get_tcp_socket(), SIGNAL(readyRead()), this, SLOT(new_player_socket()));
	Q_ASSERT(s);

	this->scene = new QGraphicsScene(ui->graphicsView);



	for ( int i = 0; i < 100; i++ ) {
		QLabel *label = new QLabel;
		QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget;
		proxy->setWidget(label);
		proxy->setPos(rand() % (ui->graphicsView->width() - 100), rand() % (ui->graphicsView->height() - 100));
		int size = rand() % 30 + 10;
		proxy->resize(size, size);

		scene->addItem(proxy);
		QPropertyAnimation *anim = new QPropertyAnimation(proxy, "rotation");
		anim->setDuration(rand() % 1500 + 500);
		anim->setStartValue(proxy->rotation());
		anim->setEndValue(rand() % 360); anim->start();
		anim->setDuration(1000);

		QPropertyAnimation *anim2 = new QPropertyAnimation(proxy, "rotation");

		QPropertyAnimation *anim3 = new QPropertyAnimation(proxy, "geometry");

		label->setStyleSheet("background-color:rgba(" + QString::number(rand() % 255) +
			"," + QString::number(rand() % 255)
			+ "," + QString::number(rand() % 255)
			+ "," + QString::number(rand() % 100 + 155) + ");");

		connect(anim, &QPropertyAnimation::finished, [this, anim2, proxy] {anim2->setDuration(rand() % 1500 + 500);
		anim2->setStartValue(proxy->rotation());
		anim2->setEndValue(rand() % 360);
		anim2->start(); });
		connect(anim3, &QPropertyAnimation::finished, [this, anim, proxy] {anim->setDuration(rand() % 1500 + 500);
		anim->setStartValue(proxy->rotation());
		anim->setEndValue(rand() % 360); anim->start(); });
		connect(anim2, &QPropertyAnimation::finished, [this, anim3, proxy] {anim3->setDuration(rand() % 1500 + 500);
		anim3->setStartValue(QRect(proxy->x(), proxy->y(), proxy->boundingRect().width(), proxy->boundingRect().height()));
		int size = (rand() % 30 + 10); anim3->setEndValue(QRect(rand() % (ui->graphicsView->width() - 100), rand() % (ui->graphicsView->height() - 100), size, size));
		anim3->start(); });

		anim->start();
	}

	ui->graphicsView->setScene(scene);
	ui->graphicsView->show();
}

void WaitMenu::new_player(QString name) {
	ui->listWidget->addItem(name);
	player_joined++;


	name_vec.push_back(name);


	DataPacket data_packet;
	int ctr = 0;

	for ( auto i : name_vec ) {
		data_packet.player_name[ctr] = i;
		ctr++;
	}

	if ( player_joined == player_count ) {

		char *code = Code::set_code('0', Code::fromServer_Sent_GameStarted);
		code[3] = player_count + '0';

		server->send_data(code, &data_packet);
		client->get_tcp_socket()->readAll();

		MainGameWindow *main_game_window = new MainGameWindow(server, name_vec, client);

		disconnect(server, SIGNAL(newplayer(QString)), this, SLOT(new_player(QString)));
		main_game_window->show();
		this->hide();
		return;
	}
	if ( player_joined != 1 ) {

		char *code = Code::set_code('0', Code::fromServer_Sent_PlayerNames);

		server->send_data(code, &data_packet);
	}


}


void WaitMenu::new_player_socket() {
	QPair<char *, DataPacket *> pair = client->reading_data_socket(true);
	DataPacket *data = pair.second;
	if ( Code::get_code(pair.first) == Code::fromServer_Sent_PlayerNames ) {

		ui->listWidget->clear();
		for ( int i = 0; i < 4; i++ )
			if ( data->player_name[i].size() > 0 )
				ui->listWidget->addItem(data->player_name[i]);
	}
	else if ( Code::get_code(pair.first) == Code::fromServer_Sent_GameStarted ) {
		client->get_tcp_socket()->readAll();
		QVector<QString> name_vec;
		int player_count = pair.first[3] - '0';
		for ( int i = 0; i < player_count; i++ )
			name_vec.push_back(data->player_name[i]);

		disconnect(client->get_tcp_socket(), SIGNAL(readyRead()), this, SLOT(new_player_socket()));

		MainGameWindow *main_game_window = new MainGameWindow(client, name_vec);
		main_game_window->show();
		this->hide();
	}
	else {
		//....
	}
}





WaitMenu::~WaitMenu() {
	delete ui;
}
