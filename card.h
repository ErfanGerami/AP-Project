#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QLabel>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QParallelAnimationGroup>
#include <QSound>


class Card:public QWidget {
public:
	const static int treasure;
	const static int map;
	const static int parrot;
	const static int flag;
	const static int pirate;
	const static int queen;
	const static int king;
	const static int unknown;

	const int dest_x = -100;
	const int dest_y = -100;
	const int width = 100;
	const int height = 200;


	Card();
	Card(int type, int number, int x, int y, int rotation, QGraphicsScene *scene, QGraphicsView *view);
	int GetNumber();
	int GetType();
	QPushButton *GetButton();
	void PushCard();
	void show();
	void hide();








private:
	int number;
	int type;
	QPushButton *button;
	QGraphicsProxyWidget *proxy;
	QGraphicsScene *scene;


	QGraphicsView *view;


};

#endif // CARD_H
