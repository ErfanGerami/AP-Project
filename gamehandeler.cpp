#include "gamehandeler.h"
#include <thread>
GameHandeler::GameHandeler()
{
}
GameHandeler::GameHandeler(QWidget* parent,int number_of_players,QGraphicsView* view,QGraphicsScene* scene,QGraphicsView* sticker_view,QGraphicsScene* sticker_scene,int me,Player p1,Player p2,Player p3,Player p4){
    this->number_of_players=number_of_players;
    this->sticker_scene=sticker_scene;
    this->sticker_view=sticker_view;
    this->scene=scene;
    this->view=view;
    this->parent=parent;
    this->me=me;
    const int max_height = 1021;
    const int max_width = 1610;
    const const pair<int,int> positions[4]={{ 0,max_height/2-100 },{  0,-view->height()/2+150 },
                                            { max_width / 2-150 ,0  },{ -max_width/2+200 ,0  }};
    for(int i=me;i<number_of_players;i++){
        this->players[i%number_of_players]=new PlayerInGame(p2,this,i-me, {},0);
        players[i%number_of_players]->SetBasePos(positions[i%number_of_players]);

    }



    //just adding the cards


}

void GameHandeler::TellTheFirst(int index) {
	//this function just fools the players to think the random player is decided here but all we need is the name of the winner to map the largest number to
	int *numbers = new int[number_of_players];
	for ( int i = 0; i < number_of_players; i++ ) {
		numbers[i] = rand() % 7 + 1;
	}
	//making the biggest go to the same index as the chosen player;
	int max_index = 0;
	for ( int i = 0; i < number_of_players; i++ ) {
		if ( numbers[i] > max_index ) {
			max_index = i;
		}
	}
	int temp = numbers[index];
	numbers[index] = numbers[max_index];
	numbers[max_index] = temp;

	Card **cards = new Card * [number_of_players];
	for ( int i = 0; i < number_of_players; i++ ) {

        cards[i] = new Card(this,Card::parrot, scene, view, numbers[i]);
		cards[i]->show();
		cards[i]->PushTo(players[i]->GetBasePos(), rand() % 150);

	}

}
void GameHandeler::Deal() {

    Card* card= new Card(this,Card::map,scene,view,2);
    players[0]->NewCards({card});
      // players[1]->NewCards({ Card(Card::map,scene,view,2),Card(Card::king,scene,view,3),Card(Card::queen,scene,view,2) });
      // players[2]->NewCards({ Card(Card::map,scene,view,2),Card(Card::king,scene,view,3),Card(Card::queen,scene,view,2) });
      // players[3]->NewCards({ Card(Card::map,scene,view,2),Card(Card::king,scene,view,3),Card(Card::queen,scene,view,2) });

	int rotation;
	for ( int i = 0; i < number_of_players; i++ ) {
		players[i]->Deal();

	}
}
void GameHandeler::collect(PlayerInGame *winner) {

	for ( auto card : cards_on_deck ) {

		card->PushTo(winner->GetCardsWonPos(), { 60, 100 });

	}
}



void GameHandeler::AddStickers(QString name,int player_index){
    if(player_index==me){
        remaning_stickers.push_back(name);
    }
    static int pos_y=-350;
    QLabel* label=new QLabel;
    QLabel* label_name=new QLabel(players[player_index]->GetUserName().c_str());
    label->setStyleSheet("border-image:url(:/images/images/"+name+".png);background:transparent");
    label->resize(61,61);
    label_name->resize(61,20);
    QGraphicsProxyWidget* proxy2 = sticker_scene->addWidget(label_name);
    //proxy2->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    proxy2->setPos(0,pos_y);

    QGraphicsProxyWidget* proxy = sticker_scene->addWidget(label);
    //proxy->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    proxy->setPos(0,pos_y+20);


    pos_y+=81;
    proxy->show();
    proxy2->show();





}

int GameHandeler::GetMe(){return me;};
int GameHandeler::GetWhoseTurn(){return (turn+first_this_round)%number_of_players;}
void GameHandeler::GetOthersPushedCard(){
    if(me==turn){
        //just pass
    }else{
        //get the pushe card here
        int player_index=0;  //set this
        Card::CardType type; //set this
        int number=-1;       //set this
        Card* card=players[GetWhoseTurn()]->PushCard(type,number,true);
        card->ChangeCard(type,number);
        card->PushCard();
        cards_on_deck.push_back(card);
        turn++;
        if(turn==number_of_players){

        }


    }
}
bool GameHandeler::isValid(Card card, int turn) {

    if ( turn != 0 ) {
        Card::CardType firsts_type = cards_on_deck[0]->GetType();
        Card::CardType players_card = card.GetType();
        if ( firsts_type != players_card ) {
            if ( players_card != Card::queen && players_card != Card::king && players_card != Card::pirate
                && firsts_type != Card::queen && firsts_type != Card::king && firsts_type != Card::pirate ) {
                if ( players[me]->haveType(firsts_type) ) {
                    return false;
                }



            }
        }
    }
    return true;

}
void GameHandeler::StartRound(){




    round++;
    turn=0;




//    for(int set=0;set<7;set++){
//        round++;

//        QVector<Card*> given_cards;

//        for(int i=0;i<number_of_players;i++){
//            //for eall cards in
//                Card::CardType type=-1;//set this
//                int number=-1;//set this
//                //given_cards.push_back(new Card(this,));
//            //get the cards and give it as an vector of Car class

//            players[i]->NewCards(given_cards);//set the input
//            //---------------------------------------------------


//        }
//        bool okay=false;
//        int prediction;
//        while(!okay)
//            prediction=QInputDialog::getInt(parent,"Prediction","How many rounds your are going to win?",0,0,round*2,1,&okay);

//            //send prediction
//        //this structure is wrong because we want to wait for the player to push button but it is the
//        //backbone of what socket should be

//        for(int i=0;i<number_of_players;i++){
//            //wait for others to predict and read if someone throw cards
//            Card::CardType type=-1;//set this
//            int number=-1;         //set this
//            int player=-1;         //set this
//            players[player]->PushCard(1,number);
//        }
//        //get the winner
//        int winner=-1;//set this
//        collect(players[winner]);
//    }




}
void GameHandeler::StartSet(){
    //get who is first
    first_this_round=0;//set this
    //------------------------



    for(int i=0;i<number_of_players;i++){
        if(i==me){
            //Get the cards here set it like in the logic but just set players[me]
            //remember that you should initialize using this format
            //new Card(this,type,scene,view,number)
            //or just initialize like the server and remind me to make it right later :) :)
            QVector<Card*> cards;//set this
            players[i]->NewCards(cards);

            //wait for server to send data that wants the prediction
            bool okay;
            while(!okay)
                int prediction=QInputDialog::getInt(parent,"Prediction","How many rounds your are going to win?",0,0,round*2,1,&okay);
            //notify the prediction to others;


        }else{
            QVector<Card*> cards;
            for(int i=0;i<set*2;i++){
                cards.push_back(new Card(this,Card::unknown,scene,view));


            }
            players[i]->NewCards(cards);
        }
    }
    //connect the socket when sends data that someone pushed card to GetOthersPushedCard



}

void GameHandeler::PushCard(){
    if(GetWhoseTurn()==me){
        Card::CardType type;
        int number;
        //inform the client
        auto cards=players[me]->get_cards();
        QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
        for(int i=0;i<cards.size();i++){
            if(cards[i]->GetButton()==clickedButton){
                type=cards[i]->GetType();
                number=cards[i]->GetNumber();
                if(isValid(Card(type,number),turn)){
                    players[i]->PushCard(type,number,false);
                }
                turn++;
                if(turn==number_of_players){
                    GetTheWinnerOfTheRound();


                }
                //notify the server of what card is pushed here
                //---------------------------------------------




            }
        }
    }else{
        //just do nothing;
    }


}
void GameHandeler::GetTheWinnerOfTheRound(){
    //get the player that has won the round;
    int player_index=0;
    //-----------------------------------

    collect(players[player_index]);
    if(round==set)
    StartRound();


}




