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

class GameHandeler:public QObject
{
    Q_OBJECT
public:
    GameHandeler();
    GameHandeler(int number_of_players,QGraphicsView*view,QGraphicsScene* scene,Player p1,Player p2,Player p3=Player(),Player p4=Player());
    void TellTheFirst(QString username);
    void Deal();
private:
    int number_of_players;
    PlayerInGame* players[4];
    vector<Card*> cards;
    QGraphicsView*view;
    QGraphicsScene* scene;

signals:
    //void Animation();




};

#endif //
