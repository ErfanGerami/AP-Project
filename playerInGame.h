#pragma once
#include <vector>
#include <string>
#include <utility>
#include "card.h"

#include "player.h"
#include "game.h"
#include <algorithm>
#include <QObject>
class PlayerInGame:public Player
{
public:

    bool haveType(Card::CardType type);
    PlayerInGame();
    PlayerInGame(const PlayerInGame& that);

	PlayerInGame(const string& username, const string& password, int rank, int games_won, int games_loose
		, const string& phone_number, const string& address, const string& email, const int coins
        , vector<Card> cards, std::pair<int, int> base_pos,int place,  Game prev_game,int round_won );

    PlayerInGame(const Player& player,int place, vector<Card> cards,int rounds_won);

	void NewCards(std::vector<Card> cards);
	std::pair<int, int> GetBasePos();
	void SetBasePos(std::pair<int, int> base_pos);
	void Deal();
	void PushCard(Card::CardType card_type, int number);
    void operator=(const PlayerInGame& other);
    void DeleteCard(Card::CardType card_type, int number);

    int getRoundsWon();
    void setRoundsWon(int rounds_won);

public slots:

private:
	int place;
	std::vector<Card> cards;
	std::pair<int, int> base_pos;
    int rounds_won;

	

};
