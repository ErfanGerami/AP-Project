#ifndef SERVERPLAYERINGAME_H
#define SERVERPLAYERINGAME_H
#include "servercard.h"
#include "player.h"
#include <QVector>

class ServerPlayerInGame:public Player
{
public:
    ServerPlayerInGame();
    ServerPlayerInGame(string user,string password);
    ServerPlayerInGame(const ServerPlayerInGame &that);
    void NewCards(QVector<ServerCard *> cards);
    void operator=(const ServerPlayerInGame &other);
    void SetRoundsPredicted(int predicted_round);
    int GetRoundsPredicted();
    int getRoundsWon();
    void setRoundsWon(int rounds_won);
    void SetPoints(int points);
    int GetPoints();
    int GetPlace();
    QVector<ServerCard *> get_cards();
    bool haveType(ServerCard::CardType type);
    ServerCard *PushCard(ServerCard::CardType card_type, int number, bool was_unknow = true);


private:
    int place;
    QVector<ServerCard *> cards;
    int rounds_won;
    int predicted_rounds;
    int points;

};

#endif // SERVERPLAYERINGAME_H
