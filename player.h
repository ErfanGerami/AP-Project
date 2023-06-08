#ifndef PLAYER_H
#define PLAYER_H
#include "game.h"
#include <QString>
class Player
{
public:
    Player();
    Player(  QString name,QString password,int rank,int games_won,int games_loose,Game* prev_game);
    Player(  QString name,QString password);
    QString Parse();

private:
    QString name;
    QString password;
    int rank;
    int games_won;
    int games_loose;
    Game* prev_game;


};

#endif // PLAYER_H
