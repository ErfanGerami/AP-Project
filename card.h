#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QLabel>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QParallelAnimationGroup>
#include <utility>
#include <QPixmap>
#include <QDebug>

class Card:public QWidget {
public:	
	typedef int CardType;

	const static CardType treasure;
	const static CardType map;
	const static CardType parrot;
	const static CardType flag;
	const static CardType pirate;
	const static CardType queen;
	const static CardType king;
	const static CardType unknown;

	const int dest_x = -100;
	const int dest_y = -100;
    const int width = 120;
	const int height = 200;


	Card();
    Card(CardType type,QGraphicsScene *scene, QGraphicsView *view, int number=-1,int x=0, int y=0, int rotation=0);
	Card(const Card& other);
	void operator=(const Card& other);

    int GetNumber();
	int GetType();
	void SetNumber(int number);
	void SetType(CardType type);
	QPushButton *GetButton();
	void PushCard();
	void PushTo(std::pair<int, int> pos);
	void PushTo(std::pair<int, int> pos, int rotation);
    void SetUpButton();

	void show();
	void hide();








private:
	int number;
	CardType type;
	QPushButton *button;
	QGraphicsProxyWidget *proxy;
	QGraphicsScene *scene;


	QGraphicsView *view;


};

#endif // CARD_H
