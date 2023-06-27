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
        this->players[i%number_of_players]=new PlayerInGame(p2,i-me, {},0);
        players[i%number_of_players]->SetBasePos(positions[i%number_of_players]);
    }



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

    Card* card= new Card(Card::map,scene,view,2);
    players[0]->NewCards({card});
      // players[1]->NewCards({ Card(Card::map,scene,view,2),Card(Card::king,scene,view,3),Card(Card::queen,scene,view,2) });
      // players[2]->NewCards({ Card(Card::map,scene,view,2),Card(Card::king,scene,view,3),Card(Card::queen,scene,view,2) });
      // players[3]->NewCards({ Card(Card::map,scene,view,2),Card(Card::king,scene,view,3),Card(Card::queen,scene,view,2) });

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
    //get players

    for(int set=0;set<7;set++){
        round++;

        QVector<Card*> given_cards;

        for(int i=0;i<number_of_players;i++){
            //for eall cards in
                Card::CardType type=-1;//set this
                int number=-1;//set this
                given_cards.push_back(new Card(type,number));
            //get the cards and give it as an vector of Car class

            players[i]->NewCards(given_cards);//set the input
            //---------------------------------------------------


        }
        bool okay=false;
        int prediction;
        while(!okay)
            prediction=QInputDialog::getInt(parent,"Prediction","How many rounds your are going to win?",0,0,round*2,1,&okay);

            //send prediction
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


