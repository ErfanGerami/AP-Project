#include "gamehandeler.h"

GameHandeler::GameHandeler()
{


}
GameHandeler::GameHandeler(int number_of_players,QGraphicsView*view,QGraphicsScene* scene,Player* p1,Player* p2,Player* p3,Player* p4){
    this->players[0]=p1;
    this->players[1]=p2;
    this->players[2]=p3;
    this->players[3]=p4;
    this->number_of_players=number_of_players;
    this->scene=scene;
    this->view=view;
    //just adding the cards
    for(int i=0;i<number_of_players*4;i++){
        Card* card1=new Card(Card::treasure,scene,view,i);
        cards.push_back(card1);
        Card* card2=new Card(Card::map,scene,view,i);
        cards.push_back(card2);
        Card* card3=new Card(Card::flag,scene,view,i);
        cards.push_back(card3);
        Card* card4=new Card(Card::parrot,scene,view,i);
        cards.push_back(card4);
    }
    int pirates=number_of_players/2*4;
    int kings=number_of_players/2*3;
    int queens=number_of_players/2*3;
    if(number_of_players==3){
        pirates=6;
        kings=4;
        queens=4;

    }
    for(int i=0;i<pirates;i++){
        Card* card=new Card(Card::pirate,scene,view);

        cards.push_back(card);

    }
    for(int i=0;i<kings;i++){
        Card* card=new Card(Card::queen,scene,view);

        cards.push_back(card);

    }
    for(int i=0;i<queens;i++){
        Card* card=new Card(Card::king,scene,view);

        cards.push_back(card);

    }

}


