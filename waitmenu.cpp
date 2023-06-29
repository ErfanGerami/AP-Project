#include "waitmenu.h"
#include "ui_waitmenu.h"
#include "channel.h"

WaitMenu::WaitMenu(SocketHandeling *connection, SocketHandeling *client, QWidget *parent):
	QDialog(parent),
	ui(new Ui::WaitMenu) {
	ui->setupUi(this);
    setFixedSize(size());

	am_i_server = connection->am_i_the_server();
	if ( am_i_server ) {
		server = connection;
		this->client = client;

		connect(server, SIGNAL(newplayer(QString)), this, SLOT(new_player(QString)));
	}
	else {
		client = connection;

	}


	this->scene = new QGraphicsScene(ui->graphicsView);



	/*for ( int i = 0; i < 150; i++ ) {
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
		anim3->setStartValue(QRect(proxy->x(), proxy->y(), proxy->boundingRect().width(), proxy->boundingRect().heigh()));
		int size = (rand() % 30 + 10); anim3->setEndValue(QRect(rand() % (ui->graphicsView->width() - 100), rand() %(ui->graphicsView->height() - 100), size, size));
		anim3->start(); });

		anim->start();
	}

	ui->graphicsView->setScene(scene);
	ui->graphicsView->show();
	*/
}

void WaitMenu::new_player(QString name) {
	ui->listWidget->addItem(name);
}

WaitMenu::~WaitMenu() {
	delete ui;
}
