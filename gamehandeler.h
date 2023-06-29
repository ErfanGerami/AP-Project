#ifndef GAMEHANDELER_H
#define GAMEHANDELER_H
#include "player.h"
#include "card.h"
#include "playerInGame.h"
#include <vector>
#include <QString>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <random>
#include <QPropertyAnimation>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QVector>
#include <QObject>
#include <QPushButton>
#include "SocketHandeling.h"
#include "Code.h"

class GameHandeler:public QObject {
	Q_OBJECT
public:
	GameHandeler();
	GameHandeler(QWidget *parent, SocketHandeling *client, int number_of_players, QGraphicsView *view, QGraphicsScene *scene, QGraphicsView *sticker_view, QGraphicsScene *sticker_scene, int me, Player p1, Player p2, Player p3 = Player(), Player p4 = Player());
	void TellTheFirst(int index);
	void Deal();
	void shuffle();
	void GameHandeler::collect(PlayerInGame *player);
	void StartRound();
	void AddStickers(QString name, int index);
	int GetMe();
	void SwitchCard(Card::CardType typpe, int number, Card::CardType type2, int number2);
	int CardVectorToArray(QVector<Card *> cards, int array[2][14]);
	QVector<Card *> CardArrayToVectorOf(int array[2][14], int size, QGraphicsView *view, QGraphicsScene *scene);

	void StartSet();
private:
	SocketHandeling *client;

	QWidget *parent;
	int number_of_players;
	int me;
	PlayerInGame *players[4];
	QVector<Card *> cards_on_deck;
	QGraphicsView *view;
	QGraphicsScene *scene;
	QVector<QString> remaning_stickers;
	//needed for clients game logic;
	int round = -1;//will be set to 0 when the game starts;
	QGraphicsView *sticker_view;
	QGraphicsScene *sticker_scene;
	bool isValid(Card card, int turn);
	void GetTheWinnerOfTheRound();
	int GetWhoseTurn();
	int turn = 0;
	int set = -1;
	int first_this_round;



signals:
	void GetOthersPushedCard_S();

private slots:
	void GetOthersPushedCard();
public slots:
	void PushCard();










};

#endif //
