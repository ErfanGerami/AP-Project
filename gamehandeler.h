#ifndef GAMEHANDELER_H
#define GAMEHANDELER_H
#include "player.h"
#include "card.h"
#include <vector>

class GameHandeler
{
public:
    GameHandeler();
    GameHandeler(int number_of_players,QGraphicsView*view,QGraphicsScene* scene,Player* p1,Player* p2,Player* p3=nullptr,Player* p4=nullptr);

private:
    int number_of_players;
    Player* players[4];
    vector<Card*> cards;
    QGraphicsView*view;
    QGraphicsScene* scene;

};

#endif //
