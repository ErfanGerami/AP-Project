#pragma once
#include <vector>
#include <string>
#include <utility>
#include "card.h"

#include "player.h"
#include "game.h"
#include <algorithm>
#include <QObject>
#include<QVector>
class PlayerInGame:public Player {
public:

	bool haveType(Card::CardType type);
	PlayerInGame();
	PlayerInGame(const PlayerInGame &that);

	PlayerInGame(const string &username, const string &password, int rank, int games_won, int games_loose
		, const string &phone_number, const string &address, const string &email, const int coins
		, QVector<Card *> cards, std::pair<int, int> base_pos, int place, Game prev_game, int round_won
		, int predicted_rounds, int points);

	PlayerInGame(const Player &player, int place, QVector<Card *> cards, int rounds_won);

	void NewCards(QVector<Card *> cards);
	std::pair<int, int> GetBasePos();
	std::pair<int, int> GetCardsWonPos();
	void SetBasePos(std::pair<int, int> base_pos);

	void CalculateWonCardPosition();
	void Deal();
	Card *PushCard(Card::CardType card_type, int number);
	void operator=(const PlayerInGame &other);
	void DeleteCard(Card::CardType card_type, int number);

	void SetRoundsPredicted(int predicted_round);
	int GetRoundsPredicted();
	int getRoundsWon();
	void setRoundsWon(int rounds_won);
	void SetPoints(int points);
	int GetPoints();
	int GetPlace();
	QVector<Card *> get_cards();
public slots:

private:
	int place;
	QVector<Card *> cards;
	std::pair<int, int> base_pos;
	std::pair<int, int> cards_won_pos;
	const int distance_to_cards_won = 200;
	int rounds_won;
	int predicted_rounds;
	int points;





};
