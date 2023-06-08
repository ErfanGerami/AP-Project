#ifndef GAME_H
#define GAME_H
#include <QString>

class Game
{
public:
    Game();
    Game(QString winner,QString time);
    QString Parse();
private:
    QString winner;
    QString time;

};

#endif // GAME_H
