#include "gamehandeler.h"
#include <thread>
#include <qtcpsocket.h>
//-1 round_first
//0 get cards
//1001 to 1004 get players card pushed
//1 predict

GameHandeler::GameHandeler() {}
GameHandeler::GameHandeler(QWidget *parent, QPushButton *pause_btn, QLabel *score_label, QLabel *stars[4], QLabel *arrows[4], SocketHandeling *client, int number_of_players, QGraphicsView *view, QGraphicsScene *scene, QGraphicsView *sticker_view, QGraphicsScene *sticker_scene, int me, Player p1, Player p2, Player p3, Player p4) {
	connect(this, &GameHandeler::my_unpause, this, &GameHandeler::MyUnpause);
	connect(this, SIGNAL(show_main_menu()), parent, SIGNAL(ShowMainMenu()));


	pause_media = new QMediaPlayer();
	//playlist = new QMediaPlaylist();


	for ( int i = 0; i < 4; i++ ) {
		this->stars[i] = stars[i];
	}
	for ( int i = 0; i < 4; i++ ) {
		this->arrows[i] = arrows[i];
	}
	this->pause_btn = pause_btn;
	this->number_of_players = number_of_players;
	this->sticker_scene = sticker_scene;
	this->sticker_view = sticker_view;
	this->scene = scene;
	this->view = view;
	this->parent = parent;
	this->me = me;
	this->client = client;
	this->score_label = score_label;
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



	for ( int i = 0; i < number_of_players; i++ ) {
		QLabel *label = new QLabel(players[(i)]->GetUserName().c_str());
		label->setStyleSheet("font-size:40px;color:red;background:transparent");
		QGraphicsProxyWidget *proxy = scene->addWidget(label);

		switch ( players[i]->GetPlace() ) {
			case 0:
				proxy->setPos(max_width / 2, max_height - 75);
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
	cards_on_deck = {};
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

int GameHandeler::GetWhoseTurn() {

	return (turn + first_this_round) % number_of_players;
}

void GameHandeler::GetOthersPushedCard(Card::CardType type, int number) {


	if ( me == GetWhoseTurn() ) {
		//just pass



	}
	else {

		Card *card = players[GetWhoseTurn()]->PushCard(type, number, true);
		turn++;
		card->ChangeCard(type, number);
		card->PushCard();
		card->SetDisabled(true);
		cards_on_deck.push_back(card);
		PlaceArrow();
		if ( GetWhoseTurn() == me ) {
			start_point = QDateTime::currentDateTime();
			QObject::connect(&timer, &QTimer::timeout, this, &GameHandeler::PushCard);
			timer.start(time_for_pushing_card);
			//20seconds to push

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

void GameHandeler::StartRound() {

	round++;
	turn = 0;

}

void GameHandeler::StartSet() {
	set++;
	round = 0;
	turn = 0;



	//just pushing unknown to the other players
	for ( int i = 0; i < number_of_players; i++ ) {
		if ( i != me ) {
			QVector<Card *> cards;
			for ( int i = 0; i < set * 2; i++ ) {
				cards.push_back(new Card(this, Card::unknown, scene, view));
				cards[i]->SetDisabled(true);


			}
			players[i]->NewCards(cards);
		}

	}

	QPair<char *, DataPacket *>pair = client->reading_data_socket();

	while ( true )
		if ( Code::get_code(pair.first) == Code::fromServer_Sent_FirstPlayer ) {
			first_this_round = pair.first[3] - '0';//set this
			break;
		}
		else {
			if ( Code::get_code(pair.first) == Code::fromServer_Sent_PlayerNames ||
				Code::get_code(pair.first) == Code::fromServer_Sent_GameStarted ) {
				pair = client->reading_data_socket();
			}
			else {

			}
		}
	//freeing data
	if ( pair.first != nullptr ) delete[] pair.first;
	if ( pair.second != nullptr ) delete pair.second;
	//--

	if ( first_this_round == me ) {
		start_point = QDateTime::currentDateTime();
		QObject::connect(&timer, &QTimer::timeout, this, &GameHandeler::PushCard);
		timer.start(time_for_pushing_card);
		//20seconds to push

	}
	PlaceArrow();
	QPropertyAnimation *anim = TellTheFirst(first_this_round);

	connect(anim, &QPropertyAnimation::finished, [this] () {_sleep(1000); GetMyCards();
	curr_state = 2;
	connect(client, SIGNAL(main_game_read()), this, SLOT(Read())); });

	//connect(anim, &QPropertyAnimation::finished, [this] () {});

	//----------------------------------


}

void GameHandeler::SwapCard(int player_index) {
	if ( GetWhoseTurn() == me && !is_pause && players[me]->get_cards().size() != 0 && !is_swaping ) {
		is_swaping = true;
		//notify the targeted index player if he wants to swap
		char *code = Code::set_code(me + '0', Code::Requested_SwapCard);
		code[0] = me + '0';
		code[1] = player_index + '0';
		int size = players[me]->get_cards().size();
		int cards_index = rand() % size;

		Card *card = players[me]->get_cards()[cards_index];
		code[3] = card->GetType() + '0';
		code[4] = card->GetNumber() + '0';
		swap_candidate.first = card->GetType();
		swap_candidate.second = card->GetNumber();
		DataPacket dummy;
		client->send_data(code, &dummy);

	}
}

void GameHandeler::handle(QPair<char *, DataPacket *>pair) {
	char *code = pair.first;

	if ( Code::get_code(code) == Code::Sent_Pause ) {

		if ( !is_pause ) {
			QMediaPlaylist *playlist = new QMediaPlaylist();
			playlist->addMedia(QUrl("qrc:/sounds/sounds/SkullKingPause.mp3"));
			playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

			pause_media->setPlaylist(playlist);
			pause_media->play();


			is_pause = true;
			pause_btn->setStyleSheet("font-size:30px;background-color:red");
		}

	}
	else if ( Code::get_code(code) == Code::Requested_SwapCard ) {
		is_swaping = true;

		int index_of_the_requested_player = code[0] - '0';

		QMessageBox::StandardButton response;
		if ( players[me]->get_cards().size() != 0 ) {

			response = QMessageBox::question(nullptr, "Swap Request"
				, "would you swapa a card with " + QString(players[index_of_the_requested_player]->GetUserName().c_str())
				, QMessageBox::Yes | QMessageBox::No);
		}
		else {
			response = QMessageBox::No;
		}
		if ( response == QMessageBox::Yes ) {

			char *new_code = Code::set_code(me + '0', Code::Accepted_SwapCard);
			new_code[0] = me + '0';
			new_code[1] = index_of_the_requested_player + '0';
			int size = players[me]->get_cards().size();
			int cards_index = rand() % size;


			Card *card = players[me]->get_cards()[cards_index];
			new_code[3] = card->GetType() + '0';
			new_code[4] = card->GetNumber() + '0';
			DataPacket dummy;
			client->send_data(new_code, &dummy);

			Card::CardType type = code[3] - '0';
			int number = code[4] - '0';

			SwitchCardShow(card->GetType(), card->GetNumber(), type, number);
		}
		else {
			char *code = Code::set_code(me + '0', Code::Denied_SwapCard);
			code[1] = index_of_the_requested_player + '0';
			DataPacket dummy;
			client->send_data(code, &dummy);
		}
		is_swaping = false;
	}
	else if ( Code::get_code(code) == Code::Accepted_SwapCard ) {
		Card::CardType type = code[3] - '0';
		int number = code[4] - '0';
		SwitchCardShow(swap_candidate.first, swap_candidate.second, type, type);
		is_swaping = false;

	}
	else if ( Code::get_code(code) == Code::Denied_SwapCard ) {
		//denied lol
		is_swaping = false;

	}
	else if ( Code::get_code(code) == Code::Sent_UnPause ) {
		if ( !my_pause && is_pause ) {
			QMediaPlaylist *playlist = new QMediaPlaylist();
			playlist->addMedia(QUrl("qrc:/sounds/sounds/SkullKingUnpause.mp3"));
			playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

			pause_media->setPlaylist(playlist);
			pause_media->play();


			is_pause = false;
			pause_btn->setStyleSheet("font-size:30px;");

		}
	}


	if ( pair.first != nullptr ) delete[] pair.first;
	if ( pair.second != nullptr ) delete pair.second;
}

void GameHandeler::Read() {
	QPair<char *, DataPacket *> pair = client->reading_data_socket();

	if ( curr_state == 2 ) {



		Card::CardType type;
		int number;


		char *code = pair.first;


		if ( Code::get_code(code) == Code::fromServer_Sent_AnotherPlayerPlayedCard ) {
			type = code[3] - '0';
			number = code[4] - '0';

		}
		else {
			//check if the code is pause do this
			handle(pair);

			return;
		}



		GetOthersPushedCard(type, number);
		if ( turn == number_of_players ) {

			curr_state = 3;

		}
		//it could be our urn but int htat case we are just writing to the server and the cur__state should not defer
	}
	else if ( curr_state == 3 ) {

		//get the player that has won the round;
		int player_index;



		if ( Code::get_code(pair.first) == Code::fromServer_Sent_RoundWinner ) {
			player_index = pair.first[3] - '0';

		}
		else {
			handle(pair);

			return;
		}

		//-----------------------------------
		GetTheWinnerOfTheRound(player_index);

		if ( round == set * 2 - 1 ) {
			if ( round == 13 )
				curr_state = 5;
			else
				curr_state = 4;
		}
		else {
			StartRound();
			curr_state = 2;
		}



		//it could be our turn but in that case we are just writing to the server and the cur_state should not defer
	}
	else if ( curr_state == 4 ) {
		//reading score
		disconnect(client, SIGNAL(main_game_read()), this, SLOT(Read()));



		int points;


		if ( Code::get_code(pair.first) == Code::fromServer_Sent_YourScore ) {

			points = pair.second->your_points;
			score_label->setText(QString::number(points));

		}
		else {
			handle(pair);

			return;
		}




		StartSet();

	}
	else if ( curr_state == 5 ) {
		disconnect(client, SIGNAL(main_game_read()), this, SLOT(Read()));

		int Game_Winner;


		if ( Code::get_code(pair.first) == Code::fromServer_Sent_GameWinner ) {

			Game_Winner = pair.first[3];

		}
		else {
			//handle(pair);

			return;
		}

		QString message;
		if ( Game_Winner == me ) {
			QSound::play(":/sounds/sounds/SkullKingWin.mp3");
			MainPlayer->SettCoins(MainPlayer->GettCoins() + number_of_players * 50);
			MainPlayer->SetGamesWon(MainPlayer->GetGamesWon() + 1);
			message = "Congrats you've won.";
		}
		else {
			QSound::play(":/sounds/sounds/SkullKingLoose.mp3");
			MainPlayer->SetGamesLoose(MainPlayer->GetGamesLoose() + 1);
			message = "Sorry you've lost.";

		}

		MainPlayer->SetPrevGame(Game(players[Game_Winner]->GetUserName().c_str(),
			QDateTime::currentDateTime().toString("MM/dd/yyyy hh:mm:ss").toStdString().c_str()
			, 0, 0, 0, players[me]->GetPoints(), true));
		MainPlayer->SetEarnedCoins(true);
		FileHandeling::ChangePlayerEntirely(MainPlayer->GetUserName().c_str(), MainPlayer);
		QMessageBox::information(parent, "Game Stat", message);
		emit show_main_menu();

	}

}

void GameHandeler::GetMyCards() {
	//Get the cards here set it like in the logic but just set players[me]
	//remember that you should initialize using this format
	//new Card(this,type,scene,view,number)
	//or just initialize like the server and remind me to make it right later :) :)
	QVector<Card *> cards;//set this
	QPair<char *, DataPacket *>pair = client->reading_data_socket();
	char *code = pair.first;
	DataPacket *data = pair.second;
	if ( Code::get_code(code) == Code::fromServer_Sent_YourCards ) {

		players[me]->NewCards(CardArrayToVectorOf(data->player_cards, data->card_size, view, scene));

	}
	else {
		//handle

	}
	//------------------------------
	if ( pair.first != nullptr ) delete[] pair.first;
	if ( pair.second != nullptr ) delete pair.second;

	//wait for server to send data that wants the prediction
	QPropertyAnimation *last_anim = Deal();
	connect(last_anim, &QPropertyAnimation::finished, this, &GameHandeler::Predict);


}




void GameHandeler::Predict() {

	bool okay = false;
	int prediction;
	while ( !okay )
		prediction = QInputDialog::getInt(parent, "Prediction", "How many rounds your are going to win?", 0, 0, set * 2, 1, &okay);
	//notify the prediction to others;
	char *code1 = Code::set_code(me + '0', Code::fromClient_Sent_Predictions);
	code1[3] = '0' + prediction;
	DataPacket dummy;
	client->send_data(code1, &dummy);
	//--------------------




}


void GameHandeler::PlaceArrow() {
	for ( int i = 0; i < 4; i++ ) {
		this->arrows[i]->hide();

	}
	this->arrows[players[GetWhoseTurn()]->GetPlace()]->show();

}

void GameHandeler::PushCard() {

	if ( GetWhoseTurn() == me && !is_pause ) {
		QObject::disconnect(&timer, &QTimer::timeout, this, &GameHandeler::PushCard);
		timer.stop();

		Card::CardType type;
		int number;
		//inform the client
		auto cards = players[me]->get_cards();
		QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
		Card *card;
		bool valid = true;
		if ( clickedButton == nullptr ) {
			for ( int i = 0; i < cards.size(); i++ ) {
				if ( isValid(*(cards[i]), turn) ) {

					card = players[me]->PushCard(cards[i]->GetType(), cards[i]->GetNumber(), false);


				}

			}


		}
		else {
			for ( int i = 0; i < cards.size(); i++ ) {
				if ( cards[i]->GetButton() == clickedButton ) {
					type = cards[i]->GetType();
					number = cards[i]->GetNumber();
					if ( isValid(Card(type, number), turn) ) {
						card = players[me]->PushCard(type, number, false);



					}
					else {
						QApplication::beep();
						valid = false;
					}
					break;
				}
			}

		}

		if ( valid ) {
			turn++;
			cards_on_deck.push_back(card);
			card->PushCard();
			card->SetDisabled(true);
			PlaceArrow();
			//notify the server of what card is pushed here
			char *code = Code::set_code(me + '0', Code::fromClient_Sent_PlayedCard);
			code[3] = type + '0';
			code[4] = number + '0';
			DataPacket dummy;
			client->send_data(code, &dummy);
			//---------------------------------------------

			if ( turn == number_of_players ) {

				curr_state = 3;

			}
		}


	}
	else {
		//just do nothing;
	}
	if ( this_turn_pause )
		this_turn_pause = false;
}

void GameHandeler::GetTheWinnerOfTheRound(int player_index) {
	turn = 0;
	//we could use the this_round_first as the previous winnet if it is not first round but I avoided it to prevent furthur complications;;

	for ( int i = 0; i < number_of_players; i++ ) {
		stars[i]->hide();
	}
	first_this_round = player_index;
	stars[players[player_index]->GetPlace()]->show();
	PlaceArrow();
	collect(players[player_index]);




}

void GameHandeler::SwitchCardShow(Card::CardType type, int number, Card::CardType type2, int number2) {
	auto cards = players[me]->get_cards();
	for ( Card *card : cards ) {
		if ( card->GetType() == type, card->GetNumber() == number ) {
			int width = card->GetButton()->width();
			//QPropertyAnimation *anim = card->PushTo({ card->GetProxy()->x(), card->GetProxy()->y() }, { 0, card->GetButton()->height() }, card->GetProxy()->rotation());


			//connect(anim, &QPropertyAnimation::finished, [this, width, card, type, number, type2, number2] () {card->ChangeCard(type2, number2); card->PushTo({ card->GetProxy()->pos().x(), card->GetProxy()->pos().y() }, { width, card->GetButton()->height() }, card->GetProxy()->rotation()); });
			card->ChangeCard(type2, number2);
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






void GameHandeler::MyPause() {
	if ( !is_pause && (GetWhoseTurn() == me) && (my_pause_count < 2) && !this_turn_pause ) {
		//QSound::play(":/sounds/sounds/SkullKingPause.mp3");
		QMediaPlaylist *playlist = new QMediaPlaylist();
		playlist->addMedia(QUrl("qrc:/sounds/sounds/SkullKingPause.mp3"));
		playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

		pause_media->setPlaylist(playlist);
		pause_media->play();



		my_pause_count++;
		is_pause = true;
		my_pause = true;
		this_turn_pause = true;
		//notify the server and the other clients of the pause
		//remember to check code in server in order to check if the cards are played or it is paused
		char *code = Code::set_code(me + '0', Code::Sent_Pause);
		DataPacket dummy;
		client->send_data(code, &dummy);
		//--------------------------------------

		time_elapsed_since_start = start_point.msecsTo((QDateTime::currentDateTime()));

		pause_btn->setStyleSheet("font-size:30px;background-color:red");
		disconnect(pause_btn, &QPushButton::clicked, this, &GameHandeler::MyPause);
		connect(pause_btn, &QPushButton::clicked, this, &GameHandeler::MyUnpause);



		my_pause_qtimer.start(20000);
		connect(&my_pause_qtimer, &QTimer::timeout, this, &GameHandeler::MyUnpause);
	}


}

void GameHandeler::MyUnpause() {
	if ( is_pause && my_pause ) {
		//QSound::play(":/sounds/sounds/SkullKingUnpause.mp3");
		QMediaPlaylist *playlist = new QMediaPlaylist();
		playlist->addMedia(QUrl("qrc:/sounds/sounds/SkullKingUnpause.mp3"));
		playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

		pause_media->setPlaylist(playlist);
		pause_media->play();



		disconnect(&my_pause_qtimer, &QTimer::timeout, this, &GameHandeler::MyUnpause);
		my_pause_qtimer.stop();



		is_pause = false;
		my_pause = false;

		pause_btn->setStyleSheet("font-size:30px;");
		timer.start(time_for_pushing_card - time_elapsed_since_start);



		//---------
		char *code2 = Code::set_code(me + '0', Code::Sent_UnPause);
		DataPacket dummy2;
		client->send_data(code2, &dummy2);
		//---------

		disconnect(pause_btn, &QPushButton::clicked, this, &GameHandeler::MyUnpause);
		connect(pause_btn, &QPushButton::clicked, this, &GameHandeler::MyPause);

	}
}

