#ifndef LOGIC_H
#define LOGIC_H

#include "servercard.h"
#include "serverplayeringame.h"
#include <vector>
#include <random>
#include "SocketHandeling.h"

#include <QThread>

class Logic:public QThread {
public:
	Logic(SocketHandeling *server, ServerPlayerInGame p1, ServerPlayerInGame p2, int number_of_players, ServerPlayerInGame p3, ServerPlayerInGame p4);
	void StartGame();



private:
	void initializeNewSet();
	bool throwCard(ServerCard card, int turn);
	int getFirstPlayer();
	int notifyAndGetThisRoundsWinner();//this will increament round_won in winner player and returns his\hers username

	void shuffle();
	void DealCard();//note that it is depending on right round to count the number of cards;
	void SwapCard(int player_index1, int player_index2, ServerCard::CardType type1, ServerCard::CardType type2, int num1, int num2);
	int CardVectorToArray(QVector<ServerCard *> cards, int array[2][14]);//give the array as the second parameter//returns size;
	QVector<ServerCard *> CardArrayToVectorOf(int array[2][14], int size);

	void handle(char *code, int who);
	void run() override;

	SocketHandeling *server;
	ServerPlayerInGame *players[4];
	int number_of_players;
	QVector<ServerCard> cards_on_deck;
	QVector<ServerCard> all_cards;
	int set;
	int round;
	int this_rounds_first;
	int whose_turn(int turn);
	//return value is -1 0 1
	int Greater(ServerCard card1, ServerCard card2);
	void FillAllCards();


};

#endif // LOGIC_H
