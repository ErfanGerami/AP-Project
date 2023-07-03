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
#include <QLabel>
#include <QInputDialog>
#include <QVector>
#include <QObject>
#include <QPushButton>
#include "SocketHandeling.h"
#include "Code.h"
#include <thread>

#include <QTimer>

class GameHandeler:public QObject {
	Q_OBJECT
public:
	GameHandeler();
	GameHandeler(QWidget *parent, QLabel *score_label, QLabel *stars[4], QLabel *arrows[4], SocketHandeling *client, int number_of_players, QGraphicsView *view, QGraphicsScene *scene, QGraphicsView *sticker_view, QGraphicsScene *sticker_scene, int me, Player p1, Player p2, Player p3 = Player(), Player p4 = Player());
	QPropertyAnimation *TellTheFirst(int index);
	QPropertyAnimation *Deal();
	void collect(PlayerInGame *player);
	void StartRound();
	void AddStickers(QString name, int index);
	int GetMe();
	void SwitchCardShow(Card::CardType typpe, int number, Card::CardType type2, int number2);
	int CardVectorToArray(QVector<Card *> cards, int array[2][14]);
	QVector<Card *> CardArrayToVectorOf(int array[2][14], int size, QGraphicsView *view, QGraphicsScene *scene);
	Card *turn_card[4];
	void SwapCard(int player_index);


	void StartSet();


	void OthersPause(int who_paused);
	void MyPause();



	SocketHandeling *client;
	void PlaceArrow();

private:
	std::pair<Card::CardType, int> swap_candidate;
	std::pair<bool, int> swap_card_stat = { false, -1 };
	std::pair<bool, int> swap_card_answer_stat = { false, -1 };

	bool is_pause = false;
	QLabel *stars[4];
	QLabel *arrows[4];
	int curr_state;
	QLabel *score_label;
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
	int GetWhoseTurn();
	int turn = 0;
	int set = 0;
	int first_this_round;




signals:
	void GetOthersPushedCard_S();
    void others_pause_ended();


public slots:
	void GetTheWinnerOfTheRound(int player_index);
	void GetOthersPushedCard(Card::CardType type, int number);
	void GetMyCards();
	void Predict();
	void Read();

	void PushCard();


};

#endif //
