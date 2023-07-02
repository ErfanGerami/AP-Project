#include "servercard.h"

typedef int CardType;
const CardType ServerCard::unknown = -1;
const CardType ServerCard::treasure = 0;
const CardType ServerCard::map = 1;
const CardType ServerCard::parrot = 2;
const CardType ServerCard::flag = 3;
const CardType ServerCard::pirate = 4;
const CardType ServerCard::queen = 5;
const CardType ServerCard::king = 6;

ServerCard::ServerCard()
{

}
ServerCard::ServerCard(CardType type, int number){
    this->type=type;
    this->number=number;

}
ServerCard::ServerCard(const ServerCard &other){
    this->number=other.number;
    this->type=other.type;
}
void ServerCard::operator=(const ServerCard &other){
    this->number=other.number;
    this->type=other.type;

}
int ServerCard::GetNumber()const{return this->number;}
int ServerCard::GetType()const{return this->type;}
void ServerCard::SetNumber(int number){this->number=number;}
void ServerCard::SetType(CardType type){this->type=type;}
void ServerCard::ChangeCard(CardType type, int number){this->number=number;this->type=type;}
