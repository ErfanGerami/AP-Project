#include "game.h"

Game::Game()
{

}
Game::Game(QString winner,QString time){
    this->winner=winner;
    this->time=time;
}
QString Game::Parse(){
    return winner+'/'+time;

}
