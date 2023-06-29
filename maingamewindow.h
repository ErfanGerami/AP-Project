#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QDialog>
#include "gamehandeler.h"
#include <QVector>
#include <QLabel>
#include <QVBoxLayout>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include "SocketHandeling.h"

namespace Ui {
	class MainGameWindow;
}

class MainGameWindow: public QDialog {
	Q_OBJECT

public:
	explicit MainGameWindow(SocketHandeling *connection, SocketHandeling *client = nullptr, QWidget *parent = nullptr);
	~MainGameWindow();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_5_clicked();

	void on_pushButton_6_clicked();

private:
	Ui::MainGameWindow *ui;
	GameHandeler *game_handeler;
	QGraphicsScene *scene;
	QGraphicsScene *sticker_scene;
	int player_count;
	SocketHandeling *server;
	SocketHandeling *client;

};

#endif // MAINGAMEWINDOW_H
