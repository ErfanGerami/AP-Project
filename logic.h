#ifndef LOGIC_H
#define LOGIC_H

#include "playerInGame.h"
#include <vector>
class Logic
{
public:
    Logic::Logic(PlayerInGame p1,PlayerInGame p2,int number_of_players,PlayerInGame p3,PlayerInGame p4);
    void initializeNewRound();
    bool isValid(Card card);
    bool throwCard(Card card);
    QString getFirstPlayer();
    QString notifyAndGetThisRoundsWinner();//this will increament round_won in winner player and returns his\hers username




private:
    PlayerInGame* players[4];
    int number_of_players;
    vector<Card> cards_on_deck;
    int set;
    int round;
    int this_rounds_first;
    int whose_turn();
    //return value is -1 0 1
    int Greater(Card card1,Card card2);


};

#endif // LOGIC_H
