#include "gamehandeler.h"
#include <thread>
GameHandeler::GameHandeler()
{
}

GameHandeler::GameHandeler(int number_of_players,QGraphicsView* view,QGraphicsScene* scene,Player p1,Player p2,Player p3,Player p4){
    this->players[0] =new PlayerInGame(p1,0,{},0);
    this->players[1]=new PlayerInGame(p2,2, {},0);
    this->players[2]=new PlayerInGame(p3,1, {},0);
    this->players[3]=new PlayerInGame(p4,3, {},0);
    
    const int max_height = 900;
    const int max_width = 1100;

    players[0]->SetBasePos({ 0,max_height/2+400 });
    players[1]->SetBasePos({ 0 ,0 });
    players[2]->SetBasePos({ max_width / 2+200 ,max_height / 2  });
    players[3]->SetBasePos({ -max_width/2-100 ,max_height /2  });
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
        pirates=5;
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

void GameHandeler::TellTheFirst(QString username) {
    //this function just fools the players to think the random player is decided here but all we need is the name of the winner to map the largest number to
    int* numbers = new int[number_of_players];
    for (int i = 0; i < number_of_players;i++) {
        numbers[i] = rand() % 7 + 1;
    }

    int max_index = 0;
    for (int i = 0; i < number_of_players; i++) {
        if (numbers[i] > max_index) {
            max_index = i;
        }
    }
    int temp = numbers[0];
    numbers[0] = numbers[max_index];
    numbers[max_index] = temp;
    Card** cards = new Card*[number_of_players];
    for (int i = 0; i < number_of_players; i++) {

        cards[i] = new Card(Card::parrot, scene, view, numbers[i]);
        cards[i]->show();
        
    }
    int cnt = number_of_players-1;
    //sorting in order to make the winner the first
    std::vector<PlayerInGame*> players_temp;
    int index_of_winner=-1;
    for (int i = 0; i < number_of_players; i++) {
        players_temp.push_back( players[i]);
        if (players[i]->GetUserName().c_str() == username) {
            index_of_winner = i;
        }
    }
    PlayerInGame* saved_player = players_temp[0];
    players_temp[0] = players_temp[index_of_winner];
    players_temp[index_of_winner] = saved_player;
   

    for (int i = 0; i < number_of_players; i++) {
        
        cards[i]->PushTo(players_temp[i]->GetBasePos());
    }
   
}
void GameHandeler::Deal() {

    players[0]->NewCards({ Card(Card::map,scene,view,2),Card(Card::king,scene,view,3),Card(Card::queen,scene,view,2),Card(Card::queen,scene,view,2),Card(Card::queen,scene,view,2),Card(Card::queen,scene,view,2),Card(Card::queen,scene,view,2) });
    players[1]->NewCards({ Card(Card::map,scene,view,2),Card(Card::king,scene,view,3),Card(Card::queen,scene,view,2) });
    players[2]->NewCards({ Card(Card::map,scene,view,2),Card(Card::king,scene,view,3),Card(Card::queen,scene,view,2) });
    players[3]->NewCards({ Card(Card::map,scene,view,2),Card(Card::king,scene,view,3),Card(Card::queen,scene,view,2) });


    int rotation;
    for (int i = 0; i < number_of_players;i++) {
        players[i]->Deal();

    }
}











