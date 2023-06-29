#ifndef CARD_H
#define CARD_H

/////
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

class Card:protected QWidget {
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

    const int dest_x = rand()%200-50+1600;
    const int dest_y = rand()%200-50+1000;

	static int angle_between_cards;
	static int space_between_cards;
    static int id;

	Card();
    Card::Card(CardType type, int number);//a constructor when we use it withoutshowing;
    Card(QObject* parent,CardType type, QGraphicsScene *scene, QGraphicsView *view, int number = -1, int x = 0, int y = 0, int rotation = 0);
	Card(const Card &other);
	void operator=(const Card &other);

	int GetNumber()const;
	int GetType()const;
	void SetNumber(int number);
	void SetType(CardType type);
	QPushButton *GetButton();
    void PushCard();
    QPropertyAnimation* PushTo(std::pair<int, int> pos);
    QPropertyAnimation* PushTo(std::pair<int, int> pos, int rotation);
    QPropertyAnimation* PushTo(std::pair<int, int> pos, std::pair<int, int> size, int rotation = 0);
	void SetUpButton();
    void ChangeCard(Card::CardType type,int number);

	void show();
	void hide();
    QGraphicsProxyWidget* GetProxy();








private:
	int width = 120;
	int height = 200;
	int number;
	CardType type;
	QPushButton *button;
	QGraphicsProxyWidget *proxy;
	QGraphicsScene *scene;

    QObject* parent;
	QGraphicsView *view;


};

#endif // CARD_H
