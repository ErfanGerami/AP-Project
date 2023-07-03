
#include "logic.h"
void Logic::run() {
	StartGame();

}

Logic::Logic(SocketHandeling *server, ServerPlayerInGame p1, ServerPlayerInGame p2, int number_of_players = 2, ServerPlayerInGame p3 = ServerPlayerInGame(), ServerPlayerInGame p4 = ServerPlayerInGame()) {
	this->players[0] = new ServerPlayerInGame(p1);
	this->players[1] = new ServerPlayerInGame(p2);
	this->players[2] = new ServerPlayerInGame(p3);
	this->players[3] = new ServerPlayerInGame(p4);
	this->set = 0;
	this->round = 0;
	this->server = server;
	this->number_of_players = number_of_players;
}

int Logic::getFirstPlayer() { return rand() % number_of_players; }


bool Logic::throwCard(ServerCard card, int turn) {

	players[round - 1]->PushCard(card.GetType(), card.GetNumber());
	cards_on_deck.push_back(card);

	return true;

}


int Logic::notifyAndGetThisRoundsWinner() {
	int index = 0;
	for ( int i = 1; i < number_of_players; i++ ) {

		if ( Greater(cards_on_deck[index], cards_on_deck[i]) == 1 ) {
			index = i;
		}
	}
	ServerPlayerInGame *this_rounds_winner = players[(this_rounds_first + index) % number_of_players];
	this_rounds_winner->setRoundsWon(this_rounds_winner->getRoundsWon() + 1);
	return (this_rounds_first + index) % number_of_players;

}

//lots of if s here :]
int Logic::Greater(ServerCard card1, ServerCard card2) {
	ServerCard::CardType type1 = card1.GetType();
	ServerCard::CardType type2 = card2.GetType();
	int number1 = card1.GetNumber();
	int number2 = card2.GetNumber();

	auto IsRole = [] (ServerCard::CardType type)->bool {return(type == ServerCard::queen || type == ServerCard::king || type == ServerCard::pirate); };
	if ( IsRole(type1) && !IsRole(type2) )return -1;
	else if ( IsRole(type2) && !IsRole(type1) )return 1;
	else if ( IsRole(type2) && IsRole(type1) ) {
		if ( type1 == ServerCard::king ) {
			if ( type2 == ServerCard::pirate ) {
				return -1;
			}
			if ( type2 == ServerCard::queen ) {
				return 1;
			}
			return 0;

		}
		else if ( type1 == ServerCard::queen ) {
			if ( type2 == ServerCard::pirate ) {
				return 1;
			}
			if ( type2 == ServerCard::king ) {
				return 1;
			}
			return 0;

		}
		else if ( type1 == ServerCard::pirate ) {//there is just one choice for else but I put else if for readabality
			if ( type2 == ServerCard::queen ) {
				return -1;
			}
			if ( type2 == ServerCard::king ) {
				return 1;
			}
			return 0;

		}

	}
	else {



		if ( type1 == ServerCard::flag && type2 != ServerCard::flag ) {
			return -1;

		}
		if ( type1 != ServerCard::flag && type2 == ServerCard::flag ) {
			return 1;

		}
		if ( type1 == ServerCard::flag && type2 == ServerCard::flag ) {

			if ( number1 > number2 )
				return -1;
			else if ( number2 > number1 )
				return 1;
			else
				return 0;

		}
		else {
			if ( type1 == type2 ) {
				if ( number1 > number2 )
					return -1;
				else if ( number2 > number1 )
					return 1;
				else
					return 0;

			}
			else {
				return -1;

			}
		}
	}
	return true;//operation never reaches here.


}


int Logic::whose_turn(int turn) { return (this_rounds_first + turn) % number_of_players; }


void Logic::initializeNewSet() {
	set++;
	this_rounds_first = getFirstPlayer();

	shuffle();
	DealCard();



	DataPacket dummy;
	char *code = Code::set_code('0', Code::fromServer_Sent_FirstPlayer);
	code[3] = this_rounds_first + '0';

	for ( int i = 0; i < number_of_players; i++ )
		server->send_data(code, &dummy, i);




	char *code1 = Code::set_code('0', Code::fromServer_Sent_YourCards);
	for ( int i = 0; i < number_of_players; i++ ) {

		DataPacket data;

		auto cards = players[i]->get_cards();
		int card_arr[2][14] = { -2 };
		int size = CardVectorToArray(cards, card_arr);


		for ( int i = 0; i < 2; i++ )
			for ( int j = 0; j < 14; j++ )
				data.player_cards[i][j] = card_arr[i][j];
		data.card_size = size;

		server->send_data(code1, &data, i);
	}



}


void Logic::FillAllCards() {
	int number_of_ordainary_cards = 8;
	if ( number_of_players == 4 ) {
		number_of_ordainary_cards = 11;
	}
	for ( int i = 1; i < number_of_ordainary_cards + 1; i++ ) {
		ServerCard card1(ServerCard::treasure, i);
		all_cards.push_back(card1);
		ServerCard card2(ServerCard::map, i);
		all_cards.push_back(card2);
		ServerCard card3(ServerCard::flag, i);
		all_cards.push_back(card3);
		ServerCard card4(ServerCard::parrot, i);
		all_cards.push_back(card4);
	}
	int pirates = 4;
	int kings = number_of_ordainary_cards == 4 ? 4 : 3;
	int queens = number_of_ordainary_cards == 4 ? 4 : 3;

	for ( int i = 0; i < pirates; i++ ) {
		ServerCard card(ServerCard::pirate, -1);
		all_cards.push_back(card);

	}
	for ( int i = 0; i < kings; i++ ) {
		ServerCard card(ServerCard::queen, -1);
		all_cards.push_back(card);

	}
	for ( int i = 0; i < queens; i++ ) {
		ServerCard card(ServerCard::king, -1);

		all_cards.push_back(card);

	}
}

void Logic::handle(char *code, int who) {
	DataPacket dummy;
	if ( Code::get_code(code) == Code::Sent_Pause ) {
		for ( int i = 0; i < number_of_players; i++ )
			if ( i != who )
				server->send_data(code, &dummy);


		QVector<QPair<char *, DataPacket *>> pair_vec = server->read_data_as_server(who);
		char *new_code = pair_vec[who].first;
		for ( int i = 0; i < number_of_players; i++ )
			if ( i != who )
				server->send_data(new_code, &dummy);

	}
	else if ( Code::get_code(code) == Code::Requested_SwapCard ) {
		server->send_data(code, &dummy, code[1] - '0');
	}
	else if ( Code::get_code(code) == Code::Accepted_SwapCard ) {
		server->send_data(code, &dummy, code[1] - '0');

	}
	else if ( Code::get_code(code) == Code::Denied_SwapCard ) {
		server->send_data(code, &dummy, code[1] - '0');
	}
}

void Logic::StartGame() {

	DataPacket dummy;

	FillAllCards();
	for ( int set_number = 0; set_number < 7; set_number++ ) {
		shuffle();
		initializeNewSet();


		//get the predicted_rounds here for each player

		QVector<QPair<char *, DataPacket *>> data_vector = server->read_data_as_server();

		char *code2;
		for ( int i = 0; i < number_of_players; i++ ) {
			code2 = data_vector[i].first;

			int prediction;

			while ( true )
				if ( Code::get_code(code2) == Code::fromClient_Sent_Predictions ) {
					prediction = code2[3] - '0';//set this
					break;
				}
				else {
					handle(code2, i);
					QVector<QPair<char *, DataPacket *>> new_data_vector = server->read_data_as_server(i);

					delete[] data_vector[i].first;
					delete data_vector[i].second;

					data_vector[i] = new_data_vector[i];

					delete[] code2;

					code2 = data_vector[i].first;

					for ( auto i : new_data_vector ) {
						delete[] i.first;
						delete i.second;
					}
				}


			//-----------------

			players[i]->SetRoundsPredicted(prediction);
		}
		//feeing data
		for ( auto i : data_vector ) {
			delete[] i.first;
			delete i.second;
		}
		//

		for ( int round_number = 0; round_number < set * 2; round_number++ ) {
			int rounds_score = 0;
			cards_on_deck = {};



			for ( int i = this_rounds_first; i < number_of_players + this_rounds_first; i++ ) {
				int turn = i % number_of_players;
				ServerCard::CardType type;
				int number;

				//Wait For the i-th player to move here and set the type and number(if it is role card set to -1)
				QVector<QPair<char *, DataPacket *>> data_vector2 = server->read_data_as_server(turn);

				char *code4;
				code4 = data_vector2[turn].first;
				while ( true )
					if ( Code::get_code(code4) == Code::fromClient_Sent_PlayedCard ) {

						type = code4[3] - '0';//set this

						number = (type <= 3) ? (code4[4] - '0') : (-1);//set this
						break;
					}
					else {
						handle(code4, turn);
						QVector<QPair<char *, DataPacket *>> new_data_vector2 = server->read_data_as_server(turn);
						delete[] data_vector[turn].first;
						delete data_vector[turn].second;

						data_vector2[turn] = new_data_vector2[turn];

						delete[] code4;

						code4 = data_vector2[turn].first;

						for ( auto i : new_data_vector2 ) {
							delete[] i.first;
							delete i.second;
						}
					}
				//freeing data
				for ( auto i : data_vector2 ) {
					delete[] i.first;
					delete i.second;
				}
				//-----------------
				cards_on_deck.push_back(ServerCard(type, number));

				//informing all:
				char *code5 = Code::set_code('0', Code::fromServer_Sent_AnotherPlayerPlayedCard);
				code5[3] = type + '0';
				code5[4] = number + '0';
				for ( int jj = 0; jj < number_of_players; jj++ ) {
					if ( turn != jj )
						server->send_data(code5, &dummy, jj);
				}
				//-------------------



				if ( type == ServerCard::king )rounds_score += 15;
				else if ( type == ServerCard::queen )rounds_score += 20;
				else if ( type == ServerCard::pirate )rounds_score += 10;
			}
			int winner_index = notifyAndGetThisRoundsWinner();
			players[winner_index]->SetPoints(players[winner_index]->GetPoints() + rounds_score);
			this_rounds_first = winner_index;
			qDebug() << "--------winner: " << this_rounds_first;
			//notify the round winner here;send winner_index
			char *code6 = Code::set_code('0', Code::fromServer_Sent_RoundWinner);
			code6[3] = this_rounds_first + '0';
			server->send_data(code6, &dummy);
			//-----------------



		}//end of round

		for ( int i = 0; i < number_of_players; i++ ) {
			if ( players[i]->GetRoundsPredicted() == 0 ) {
				if ( players[i]->getRoundsWon() == 0 ) {
					players[i]->SetPoints(players[i]->GetPoints() + set * 10);
				}
				else {
					players[i]->SetPoints(players[i]->GetPoints() - set * 10);

				}
			}
			else {
				if ( players[i]->getRoundsWon() == players[i]->GetRoundsPredicted() ) {
					players[i]->SetPoints(players[i]->GetPoints() + players[i]->GetRoundsPredicted() * 10);
				}
				else {
					players[i]->SetPoints(players[i]->GetPoints() -
						abs(players[i]->GetRoundsPredicted() - players[i]->getRoundsWon()) * 10);
				}

			}


		}
		//notify the player their score here  players[i]->GetPoints();
		char *code7 = Code::set_code('0', Code::fromServer_Sent_YourScore);
		DataPacket data_packet;
		for ( int j = 0; j < number_of_players; j++ ) {
			int points = players[j]->GetPoints();

			data_packet.your_points = points;

			server->send_data(code7, &data_packet, j);
		}
		//-----------------



	}//end of set

	int winner = 0;
	for ( int i = 1; i < number_of_players; i++ ) {
		if ( players[i]->GetPoints() > players[winner]->GetPoints() )
			winner = i;

	}
	//notify all that who won and that they should give up their money :)

	char *code8 = Code::set_code('0', Code::fromServer_Sent_GameWinner);
	code8[3] = winner + '0';
	server->send_data(code8, &dummy);


}

void Logic::DealCard() {
	int index = 0;
	for ( int i = 0; i < number_of_players; i++ ) {
		QVector<ServerCard *> vec;
		for ( int i = index; i < index + set * 2; i++ ) {
			vec.push_back(&all_cards[i]);
		}
		index += 2 * set;

		players[i]->NewCards(vec);
	}
}

void Logic::shuffle() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(all_cards.begin(), all_cards.end(), gen);

}
void Logic::SwapCard(int player_index1, int player_index2, ServerCard::CardType type1, ServerCard::CardType type2, int num1, int num2) {
	auto players1_cards = players[player_index1]->get_cards();
	auto players2_cards = players[player_index2]->get_cards();
	for ( ServerCard *card : players1_cards ) {
		if ( card->GetType() == type1, card->GetNumber() == num1 ) {
			card->ChangeCard(type2, num2);





		}
	}

	for ( ServerCard *card : players2_cards ) {
		if ( card->GetType() == type2, card->GetNumber() == num2 ) {
			card->ChangeCard(type1, num2);





		}
	}
}



int Logic::CardVectorToArray(QVector<ServerCard *> cards, int array[2][14]) {

	for ( int i = 0; i < cards.size(); i++ ) {
		array[0][i] = cards[i]->GetType();
		array[1][i] = cards[i]->GetNumber();
	}
	return cards.size();

}
QVector<ServerCard *> Logic::CardArrayToVectorOf(int array[2][14], int size) {
	QVector<ServerCard *> cards;
	for ( int i = 0; i < size; i++ ) {
		cards.push_back(new ServerCard(array[0][i], array[1][i]));

	}
	return cards;


}



