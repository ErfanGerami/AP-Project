#include "gamehandeler.h"
#include <thread>
#include <qtcpsocket.h>
GameHandeler::GameHandeler() {}
GameHandeler::GameHandeler(QWidget *parent, SocketHandeling *client, int number_of_players, QGraphicsView *view, QGraphicsScene *scene, QGraphicsView *sticker_view, QGraphicsScene *sticker_scene, int me, Player p1, Player p2, Player p3, Player p4) {
	this->number_of_players = number_of_players;
	this->sticker_scene = sticker_scene;
	this->sticker_view = sticker_view;
	this->scene = scene;
	this->view = view;
	this->parent = parent;
	this->me = me;
	this->client = client;
	const int max_height = 1021;
	const int max_width = 1610;
	const pair<int, int> positions[4] = { { max_width / 2, max_height - 100 }, { max_width / 2, 100 },
		{ max_width - 100, max_height / 2 }, { 100, max_height / 2 } };

	this->players[0] = new PlayerInGame(p1, this, 0, {}, 0);
	this->players[1] = new PlayerInGame(p2, this, 0, {}, 0);
	this->players[2] = new PlayerInGame(p3, this, 0, {}, 0);
	this->players[3] = new PlayerInGame(p4, this, 0, {}, 0);

	for ( int i = me; i < number_of_players + me; i++ ) {
		players[i % number_of_players]->SetPlace(i - me);
		players[i % number_of_players]->SetBasePos(positions[(i - me)]);

	}

	//qDebug() << players[0]->GetBasePos().first << players[0]->GetBasePos().second;
	//qDebug() << players[1]->GetBasePos().first << players[1]->GetBasePos().second;



	for ( int i = 0; i < number_of_players; i++ ) {
		QLabel *label = new QLabel(players[(i)]->GetUserName().c_str());
		label->setStyleSheet("font-size:40px;color:red;background:transparent");
		QGraphicsProxyWidget *proxy = scene->addWidget(label);

		switch ( players[i]->GetPlace() ) {
			case 0:
				proxy->setPos(max_width / 2, max_height);
				break;
			case 1:
				proxy->setPos(max_width / 2, 50);

				break;
			case 2:
				proxy->setPos(max_width - 75, max_height / 2);
				proxy->setRotation(270);
				break;
			case 3:
				proxy->setPos(100, max_height / 2);
				proxy->setRotation(90);
				break;

		}
		proxy->show();

	}

	//just adding the cards

}

QPropertyAnimation *GameHandeler::TellTheFirst(int index) {
	//th just is functionfools the players to think the random player is decided here but all we need is the name of the winner to map the largest number to
	int *numbers = new int[number_of_players];
	for ( int i = 0; i < number_of_players; i++ ) {
		numbers[i] = rand() % 7 + 1;
	}
	//making the biggest go to the same index as the chosen player;
	int max_index = 0;
	for ( int i = 0; i < number_of_players; i++ ) {
		if ( numbers[i] > numbers[max_index] ) {
			max_index = i;
		}
	}
	int temp = numbers[index];
	numbers[index] = numbers[max_index];
	numbers[max_index] = temp;


	for ( int i = 0; i < number_of_players; i++ ) {

		turn_card[i] = new Card(this, Card::parrot, scene, view, numbers[i]);
		turn_card[i]->show();
		if ( i == number_of_players - 1 )return turn_card[i]->PushTo(players[i]->GetBasePos(), rand() % 90);
		else turn_card[i]->PushTo(players[i]->GetBasePos(), rand() % 90);


	}

}

QPropertyAnimation *GameHandeler::Deal() {

	//Card *card = new Card(this, Card::parrot, scene, view, 2);
	//players[0]->NewCards({ new Card(this, Card::parrot, scene, view, 2), new Card(this, Card::parrot, scene, view, 2) });
	//players[1]->NewCards({ new Card(this, Card::map, scene, view, 2), new Card(this, Card::king, scene, view, 3), new Card(this, Card::queen, scene, view, 2) });
	//players[2]->NewCards({ new Card(this, Card::map, scene, view, 2), new Card(this, Card::king, scene, view, 3), new Card(this, Card::queen, scene, view, 2) });
	//players[3]->NewCards({ new Card(this, Card::map, scene, view, 2), new Card(this, Card::king, scene, view, 3), new Card(this, Card::queen, scene, view, 2) });
	_sleep(1000);
	for ( int i = 0; i < number_of_players; i++ ) {
		turn_card[i]->hide();
	}

	QPropertyAnimation *last_animation;
	int rotation;
	for ( int i = 0; i < number_of_players; i++ ) {
		last_animation = players[i]->Deal();

	}
	return last_animation;
}

void GameHandeler::collect(PlayerInGame *winner) {

	for ( auto card : cards_on_deck ) {

		card->PushTo(winner->GetCardsWonPos(), { 60, 100 });

	}
}



void GameHandeler::AddStickers(QString name, int player_index) {
	if ( player_index == me ) {
		remaning_stickers.push_back(name);
	}
	static int pos_y = -350;
	QLabel *label = new QLabel;
	QLabel *label_name = new QLabel(players[player_index]->GetUserName().c_str());
	label->setStyleSheet("border-image:url(:/images/images/" + name + ".png);background:transparent");
	label->resize(61, 61);
	label_name->resize(61, 20);
	QGraphicsProxyWidget *proxy2 = sticker_scene->addWidget(label_name);
	//proxy2->setFlag(QGraphicsItem::ItemIgnoresTransformations);
	proxy2->setPos(0, pos_y);

	QGraphicsProxyWidget *proxy = sticker_scene->addWidget(label);
	//proxy->setFlag(QGraphicsItem::ItemIgnoresTransformations);
	proxy->setPos(0, pos_y + 20);


	pos_y += 81;
	proxy->show();
	proxy2->show();

}

int GameHandeler::GetMe() { return me; };

int GameHandeler::GetWhoseTurn() { qDebug() << turn + first_this_round; return (turn + first_this_round) % number_of_players; }

void GameHandeler::GetOthersPushedCard() {

	disconnect(client->get_tcp_socket(), SIGNAL(readyRead()), this, SLOT(GetOthersPushedCard()));
	disconnect(client->get_tcp_socket(), SIGNAL(bytesAvailable()), this, SLOT(GetOthersPushedCard()));

	if ( me == turn ) {
		//just pass
	}
	else {


		//get the pushe card here
		int player_index;  //set this // no
		Card::CardType type; //set this
		int number;       //set this

		QPair<char *, DataPacket *>pair = client->reading_data_socket(false);
		char *code = pair.first;
		if ( Code::get_code(code) == Code::fromServer_Sent_AnotherPlayerPlayedCard ) {
			type = code[3] - '0';
			number = code[4] - '0';
		}
		else {
			//handle
		}

		//------------


		Card *card = players[GetWhoseTurn()]->PushCard(type, number, true);
		card->ChangeCard(type, number);
		card->PushCard();
		cards_on_deck.push_back(card);
		turn++;
		if ( turn == number_of_players ) {

		}


	}


	if ( turn == number_of_players )
		connect(client->get_tcp_socket(), SIGNAL(readyRead()), this, SLOT(GetTheWinnerOfTheRound()));
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
void GameHandeler::StartRound() {

	round++;
	turn = 0;

	//for ( int set = 0; set < 7; set++ ) {
	//	DataPacket dummy;

	//	round++;

	//	QVector<Card *> given_cards;

	//	//for ( int i = 0; i < number_of_players; i++ ) {
	//		//for all cards in
	//	Card::CardType type = -1;//set this
	//	int number = -1;//set this
	//	//given_cards.push_back(new Card(this,));
	//	//get the cards and give it as a vector of Card class
	//	QPair<char *, DataPacket *>pair = client->reading_data_socket();
	//	char *code = pair.first;
	//	DataPacket *data = pair.second;
	//	if ( Code::get_code(code) == Code::fromServer_Sent_YourCards ) {
	//		for ( int i = 0; i < 7; i++ )
	//			given_cards.push_back(new Card(i, data->player_cards[i]));
	//	}
	//	else {
	//		//handle
	//	}
	//	//---------------------------------------------------
	//	players[me]->NewCards(given_cards);//set the input
	//	//---------------------------------------------------


	////}
	//	bool okay = false;
	//	int prediction;
	//	while ( !okay )
	//		prediction = QInputDialog::getInt(parent, "Prediction", "How many rounds your are going towin?", 0, 0, round * 2, 1, &okay);

	//	//send prediction
	//	char *code1 = Code::set_code(me, Code::fromClient_Sent_Predictions);
	//	client->send_data(code1, &dummy);
	//	//-------------------

	////this structure is wrong because we want to wait for the player to push button but it is the
	////backbone of what socket should be

	//	for ( int i = 0; i < number_of_players; i++ ) {
	//		//wait for others to predict and read if someone throw cards
	//		Card::CardType type = -1;//set this
	//		int number = -1;         //set this
	//		int player = -1;         //set this
	//		players[player]->PushCard(1, number);
	//	}
	//	//get the winner
	//	int winner = -1;//set this
	//	QPair<char *, DataPacket *>pair1 = client->reading_data_socket();
	//	if ( Code::get_code(pair1.first) == Code::fromServer_Sent_RoundWinner )
	//		winner = pair1.first[4];
	//	else {
	//		//handle
	//	}
	//	collect(players[winner]);
	//}




}
void GameHandeler::StartSet() {
	set++;


	//get who is first
	QPair<char *, DataPacket *>pair = client->reading_data_socket(false);

	if ( Code::get_code(pair.first) == Code::fromServer_Sent_FirstPlayer ) {
		first_this_round = pair.first[3] - '0';//set this

	}
	else {
		//handle
	}
	//------------------------

	for ( int i = 0; i < number_of_players; i++ ) {
		if ( i != me ) {
			QVector<Card *> cards;
			for ( int i = 0; i < set * 2; i++ ) {
				cards.push_back(new Card(this, Card::unknown, scene, view));


			}
			players[i]->NewCards(cards);
		}

	}
	QPropertyAnimation *anim = TellTheFirst(first_this_round);
	connect(anim, &QPropertyAnimation::finished, this, &GameHandeler::GetMyCards);

}

void GameHandeler::GetMyCards() {
	//Get the cards here set it like in the logic but just set players[me]
	//remember that you should initialize using this format
	//new Card(this,type,scene,view,number)
	//or just initialize like the server and remind me to make it right later :) :)
	QVector<Card *> cards;//set this
	QPair<char *, DataPacket *>pair = client->reading_data_socket(false);
	char *code = pair.first;
	DataPacket *data = pair.second;
	if ( Code::get_code(code) == Code::fromServer_Sent_YourCards ) {

		players[me]->NewCards(CardArrayToVectorOf(data->player_cards, data->card_size, view, scene));

	}
	else {
		//handle
	}
	//------------------------------


	//wait for server to send data that wants the prediction
	QPropertyAnimation *last_anim = Deal();
	connect(last_anim, &QPropertyAnimation::finished, this, &GameHandeler::Predict);


}


void GameHandeler::Predict() {
	bool okay = false;////////////////////////////////////////////////check\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
	int prediction;
	while ( !okay )
		prediction = QInputDialog::getInt(parent, "Prediction", "How many rounds your are going to win?", 0, 0, max(round * 2, 1), 1, &okay);
	//notify the prediction to others;
	char *code1 = Code::set_code(me + '0', Code::fromClient_Sent_Predictions);
	code1[3] = '0' + prediction;
	DataPacket dummy;
	client->send_data(code1, &dummy);
	//--------------------
	//connect the socket when sends data that someone pushed card to GetOthersPushedCard
	//GetOthersPushedCard();
	connect(client->get_tcp_socket(), SIGNAL(readyRead()), this, SLOT(GetOthersPushedCard()));

}


void GameHandeler::PushCard() {
	if ( GetWhoseTurn() == me ) {
		Card::CardType type;
		int number;
		//inform the client
		auto cards = players[me]->get_cards();
		QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
		for ( int i = 0; i < cards.size(); i++ ) {
			if ( cards[i]->GetButton() == clickedButton ) {
				type = cards[i]->GetType();
				number = cards[i]->GetNumber();
				if ( isValid(Card(type, number), turn) ) {
					players[i]->PushCard(type, number, false)->PushCard();

				}

				/*if ( turn == number_of_players ) {
					GetTheWinnerOfTheRound();


				}*/
				//notify the server of what card is pushed here
				char *code = Code::set_code(me, Code::fromClient_Sent_PlayedCard);
				code[3] = type - '0';
				code[4] = number - '0';
				DataPacket dummy;
				client->send_data(code, &dummy);
				//---------------------------------------------




			}
		}
	}
	else {
		//just do nothing;
	}

	if ( ++turn == number_of_players )
		connect(client->get_tcp_socket(), SIGNAL(readyRead()), this, SLOT(GetTheWinnerOfTheRound()));
	else {
		connect(client->get_tcp_socket(), SIGNAL(readyRead()), this, SLOT(GetOthersPushedCard()));
		connect(client->get_tcp_socket(), SIGNAL(bytesAvailable()), this, SLOT(GetOthersPushedCard()));
		emit client->get_tcp_socket()->readyRead();
	}

}

void GameHandeler::GetTheWinnerOfTheRound() {
	//get the player that has won the round;
	int player_index;
	QPair<char *, DataPacket *> pair = client->reading_data_socket(false);
	if ( Code::get_code(pair.first) == Code::fromServer_Sent_RoundWinner )
		player_index = pair.first[3] - '0';

	//-----------------------------------

	collect(players[player_index]);
	if ( round == set )
		StartRound();

	disconnect(client->get_tcp_socket(), SIGNAL(readyRead()), this, SLOT(GetTheWinnerOfTheRound()));

}

void GameHandeler::SwitchCard(Card::CardType type, int number, Card::CardType type2, int number2) {
	auto cards = players[me]->get_cards();
	for ( Card *card : cards ) {
		if ( card->GetType() == type, card->GetNumber() == number ) {
			int width = card->GetButton()->width();
			QPropertyAnimation *anim = card->PushTo({ card->GetProxy()->x(), card->GetProxy()->y() }, { 0, card->GetButton()->height() }, card->GetProxy()->rotation());


			connect(anim, &QPropertyAnimation::finished, [this, width, card, type, number, type2, number2] () {card->ChangeCard(type2, number2); card->PushTo({ card->GetProxy()->pos().x(), card->GetProxy()->pos().y() }, { width, card->GetButton()->height() }, card->GetProxy()->rotation()); });
			return;
		}
	}
}

int GameHandeler::CardVectorToArray(QVector<Card *> cards, int array[2][14]) {

	for ( int i = 0; i < cards.size(); i++ ) {
		array[0][i] = cards[i]->GetType();
		array[1][i] = cards[i]->GetNumber();
	}
	return cards.size();

}
QVector<Card *> GameHandeler::CardArrayToVectorOf(int array[2][14], int size, QGraphicsView *view, QGraphicsScene *scene) {
	QVector<Card *> cards;
	for ( int i = 0; i < size; i++ ) {
		cards.push_back(new Card(this, array[0][i], scene, view, array[1][i]));

	}
	return cards;


}

