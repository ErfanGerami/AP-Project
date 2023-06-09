#include "player.h"

Player::Player()
{
    this->name="";
    this->password="";
    this->rank=0;
    this->games_won=0;
    this->games_loose=0;
    this->prev_game=nullptr;
    this->phone_number="";
    this->address="";
    this->email="";
}

Player::Player( QString name,QString password,int rank,int games_won,int games_loose,QString phone_number,QString address,QString email,Game* prev_game){
    this->name=name;
    this->password=password;
    this->rank=rank;
    this->games_won=games_won;
    this->games_loose=games_loose;

    this->prev_game=prev_game;
    this->phone_number=phone_number;
    this->address=address;
    this->email=email;
}
Player::Player( QString name,QString password){
    this->name=name;
    this->password=password;
    this->rank=0;
    this->games_won=0;
    this->games_loose=0;
    this->prev_game=nullptr;
    this->phone_number="";
    this->address="";
    this->email="";
}
QString Player::Parse(){
    if(prev_game==nullptr){
        return name+'/'+password+'/'+QString(rank)+'/'+QString(games_won)+'/'+QString(games_loose)+'/'+this->phone_number+'/'+
                this->address+"null";
    }else{
        return name+'/'+password+'/'+QString(rank)+'/'+QString(games_won)+'/'+QString(games_loose)+'/'+this->phone_number+'/'+
                this->address+'/'+prev_game->Parse();

    }

}
