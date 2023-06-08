#include "player.h"

Player::Player()
{

}

Player::Player( QString name,QString password,int rank,int games_won,int games_loose,Game* prev_game){
    this->name=name;
    this->password=password;
    this->rank=rank;
    this->games_won=games_won;
    this->games_loose=games_loose;

    this->prev_game=prev_game;

}
Player::Player( QString name,QString password){
    this->name=name;
    this->password=password;
    this->rank=0;
    this->games_won=0;
    this->games_loose=0;
    this->prev_game=nullptr;
}
QString Player::Parse(){
    return name+'/'+password+'/'+QString(rank)+'/'+QString(games_won)+'/'+QString(games_loose)+'/'+prev_game->Parse();
}
