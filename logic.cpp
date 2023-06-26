#include "logic.h"

Logic::Logic(PlayerInGame p1,PlayerInGame p2,int number_of_players=2,PlayerInGame p3=PlayerInGame(),PlayerInGame p4=PlayerInGame())
{
    this->players[0]=new PlayerInGame(p1);
    this->players[1]=new PlayerInGame(p2);
    this->players[2]=new PlayerInGame(p3);
    this->players[3]=new PlayerInGame(p4);
    this->set=0;
    this->round=0;


}
QString Logic::getFirstPlayer(){return players[rand()%number_of_players]->GetUserName().c_str();}

bool Logic::isValid(Card card){

    if(round!=1){
        Card::CardType firsts_type=cards_on_deck[0].GetType();
        Card::CardType players_card=card.GetType();
         if(firsts_type!=players_card){
            if(players_card!=Card::queen&& players_card!=Card::king&& players_card!=Card::pirate
                    &&firsts_type!=Card::queen&& firsts_type!=Card::king&& firsts_type!=Card::pirate){
                if(players[whose_turn()]->haveType(firsts_type)){
                    return false;
                }



            }
        }
    }
    return true;




}


bool Logic::throwCard(Card card){
    if(!isValid(card))return false;
    players[round-1]->PushCard(card.GetType(),card.GetNumber());
    cards_on_deck.push_back(card);

    return true;

}
QString Logic::notifyAndGetThisRoundsWinner(){
    int index=0;
    for(int i=0;i<number_of_players;i++){

        if(Greater(cards_on_deck[index],cards_on_deck[i])==1){
            index=i;
        }
    }
    PlayerInGame* this_rounds_winner=players[(this_rounds_first+index)%number_of_players];
    this_rounds_winner->setRoundsWon(this_rounds_winner->getRoundsWon());
    return this_rounds_winner->GetUserName().c_str();


}

//lots of if s here :)
int Logic::Greater(Card card1,Card card2){
    Card::CardType type1=card1.GetType();
    Card::CardType type2=card2.GetType();
    int number1=card1.GetNumber();
    int number2=card2.GetNumber();

    auto IsRole=[](Card::CardType type)->bool{return(type==Card::queen||type==Card::king||type==Card::pirate);};
    if(IsRole(type1)&&!IsRole(type2))return -1;
    else if(IsRole(type2)&&!IsRole(type1))return 1;
    else if(IsRole(type2)&&IsRole(type1)){
        if(type1==Card::king){
            if(type2==Card::pirate){
                return -1;
            }
            if(type2==Card::queen){
                return 1;
            }
            return 0;

        }else if(type1==Card::queen){
            if(type2==Card::pirate){
                return 1;
            }
            if(type2==Card::king){
                return 1;
            }
            return 0;

        }else if(type1==Card::pirate){//there is just one choice for else but I put else if for readabality
            if(type2==Card::queen){
                return -1;
            }
            if(type2==Card::king){
                return 1;
            }
            return 0;

        }

    }else{



        if(type1==Card::flag&&type2!=Card::flag){
            return -1;

        }
        if(type1!=Card::flag&&type2==Card::flag){
            return 1;

        }
        if(type1==Card::flag&&type2==Card::flag){

            if(number1>number2)
                return -1;
            else if(number2>number1)
                return 1;
            else
                return 0;

        }
        else{
            if(type1==type2){
                if(number1>number2)
                    return -1;
                else if(number2>number1)
                    return 1;
                else
                    return 0;

            }else{
                if(number1==cards_on_deck[0].GetType())
                    return -1;
                else if(number2==cards_on_deck[0].GetType())
                    return 1;
                else
                    return 0;

            }
        }
    }
    return true;//operation never reaches here.


}
int Logic::whose_turn(){return (this_rounds_first+round)%number_of_players;}
void Logic::initializeNewRound(){
    round++;
    this_rounds_first++;
    this_rounds_first%=number_of_players;
    //deal the cards here later;

}

