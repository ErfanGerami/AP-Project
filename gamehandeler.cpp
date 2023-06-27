#include "gamehandeler.h"
#include <thread>
GameHandeler::GameHandeler()
{
}
GameHandeler::GameHandeler(QWidget* parent,int number_of_players,QGraphicsView* view,QGraphicsScene* scene,int me,Player p1,Player p2,Player p3,Player p4){

    const int max_height = 1021;
    const int max_width = 1610;
    const const pair<int,int> positions[4]={{ 0,max_height/2-100 },{  0,-view->height()/2+150 },
                                            { max_width / 2-150 ,0  },{ -max_width/2+200 ,0  }};
    for(int i=me;i<this->number_of_players;i++){
        this->players[i%number_of_players]=new PlayerInGame(p2,i-me, {},0);
        players[i%number_of_players]->SetBasePos(positions[i]);
    }

    this->number_of_players=number_of_players;
    this->scene=scene;
    this->view=view;
    this->parent=parent;
    //just adding the cards


}

void GameHandeler::TellTheFirst(int index) {
    //this function just fools the players to think the random player is decided here but all we need is the name of the winner to map the largest number to
    int* numbers = new int[number_of_players];
    for (int i = 0; i < number_of_players;i++) {
        numbers[i] = rand() % 7 + 1;
    }
    //making the biggest go to the same index as the chosen player;
    int max_index = 0;
    for (int i = 0; i < number_of_players; i++) {
        if (numbers[i] > max_index) {
            max_index = i;
        }
    }
    int temp = numbers[index];
    numbers[index] = numbers[max_index];
    numbers[max_index] = temp;

    Card** cards = new Card*[number_of_players];
    for (int i = 0; i < number_of_players; i++) {

        cards[i] = new Card(Card::parrot, scene, view, numbers[i]);
        cards[i]->show();
        cards[i]->PushTo(players[i]->GetBasePos(),rand()%150);
        
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
void GameHandeler::collect(PlayerInGame* winner){

    for(auto card:cards_on_deck){

        card->PushTo(winner->GetCardsWonPos(),{60,100});

    }
}


void GameHandeler::StartRound(){
    for(int set=0;set<7;set++){
        round++;
        //get the cards and give it as an vector of Car class
        //---------------------------------------------------
        for(int i=0;i<number_of_players;i++){
            //get the cards and give it as an vector of Car class
            players[i]->NewCards({});//set the input

        }
        bool okay=false;
        int prediction;
        while(!okay)
            prediction=prediction=QInputDialog::getInt(parent,"Prediction","How many rounds your are going to win?",0,0,round*2,1,&okay);

        //this structure is wrong because we want to wait for the player to push button but it is the
        //backbone of what socket should be

        for(int i=0;i<number_of_players;i++){
            //wait for others to predict and read if someone throw cards

            Card::CardType type=-1;//set this
            int number=-1;         //set this
            int player=-1;         //set this
            players[player]->PushCard(1,number);
        }
        //get the winner
        int winner=-1;//set this
        collect(players[winner]);
    }











}








