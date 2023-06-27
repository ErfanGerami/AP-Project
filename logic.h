#ifndef LOGIC_H
#define LOGIC_H

#include "playerInGame.h"
#include <vector>
#include <random>
#include "SocketHandeling.h"

class Logic {
public:
	Logic::Logic(SocketHandeling *server, PlayerInGame p1, PlayerInGame p2, int number_of_players, PlayerInGame p3, PlayerInGame p4);
	void initializeNewSet();
	bool isValid(Card card, int turn);
	bool throwCard(Card card, int turn);
	int getFirstPlayer();
	int notifyAndGetThisRoundsWinner();//this will increament round_won in winner player and returns his\hers username

	void StartGame();
	void shuffle();
	void DealCard();//note that it is depending on right round to count the number of cards;







private:
	SocketHandeling *server;
	PlayerInGame *players[4];
	int number_of_players;
	QVector<Card> cards_on_deck;
	QVector<Card> all_cards;
	int set;
	int round;
	int this_rounds_first;
	int whose_turn(int turn);
	//return value is -1 0 1
	int Greater(Card card1, Card card2);
	void FillAllCards();


};

#endif // LOGIC_H
