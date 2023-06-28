#include "logic.h"

Logic::Logic(SocketHandeling *server, PlayerInGame p1, PlayerInGame p2, int number_of_players = 2, PlayerInGame p3 = PlayerInGame(), PlayerInGame p4 = PlayerInGame()) {
	this->players[0] = new PlayerInGame(p1);
	this->players[1] = new PlayerInGame(p2);
	this->players[2] = new PlayerInGame(p3);
	this->players[3] = new PlayerInGame(p4);
	this->set = 0;
	this->round = 0;


}

int Logic::getFirstPlayer() { return rand() % number_of_players; }
bool Logic::isValid(Card card, int turn) {

	if ( turn != 0 ) {
		Card::CardType firsts_type = cards_on_deck[0].GetType();
		Card::CardType players_card = card.GetType();
		if ( firsts_type != players_card ) {
			if ( players_card != Card::queen && players_card != Card::king && players_card != Card::pirate
				&& firsts_type != Card::queen && firsts_type != Card::king && firsts_type != Card::pirate ) {
				if ( players[whose_turn(turn)]->haveType(firsts_type) ) {
					return false;
				}



			}
		}
	}
	return true;

}


bool Logic::throwCard(Card card, int turn) {
	if ( !isValid(card, turn) )return false;
	players[round - 1]->PushCard(card.GetType(), card.GetNumber());
	cards_on_deck.push_back(card);

	return true;

}


int Logic::notifyAndGetThisRoundsWinner() {
	int index = 0;
	for ( int i = 0; i < number_of_players; i++ ) {

		if ( Greater(cards_on_deck[index], cards_on_deck[i]) == 1 ) {
			index = i;
		}
	}
	PlayerInGame *this_rounds_winner = players[(this_rounds_first + index) % number_of_players];
	this_rounds_winner->setRoundsWon(this_rounds_winner->getRoundsWon() + 1);
	return index;

}

//lots of if s here :]
int Logic::Greater(Card card1, Card card2) {
	Card::CardType type1 = card1.GetType();
	Card::CardType type2 = card2.GetType();
	int number1 = card1.GetNumber();
	int number2 = card2.GetNumber();

	auto IsRole = [] (Card::CardType type)->bool {return(type == Card::queen || type == Card::king || type == Card::pirate); };
	if ( IsRole(type1) && !IsRole(type2) )return -1;
	else if ( IsRole(type2) && !IsRole(type1) )return 1;
	else if ( IsRole(type2) && IsRole(type1) ) {
		if ( type1 == Card::king ) {
			if ( type2 == Card::pirate ) {
				return -1;
			}
			if ( type2 == Card::queen ) {
				return 1;
			}
			return 0;

		}
		else if ( type1 == Card::queen ) {
			if ( type2 == Card::pirate ) {
				return 1;
			}
			if ( type2 == Card::king ) {
				return 1;
			}
			return 0;

		}
		else if ( type1 == Card::pirate ) {//there is just one choice for else but I put else if for readabality
			if ( type2 == Card::queen ) {
				return -1;
			}
			if ( type2 == Card::king ) {
				return 1;
			}
			return 0;

		}

	}
	else {



		if ( type1 == Card::flag && type2 != Card::flag ) {
			return -1;

		}
		if ( type1 != Card::flag && type2 == Card::flag ) {
			return 1;

		}
		if ( type1 == Card::flag && type2 == Card::flag ) {

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
				if ( number1 == cards_on_deck[0].GetType() )
					return -1;
				else if ( number2 == cards_on_deck[0].GetType() )
					return 1;
				else
					return 0;

			}
		}
	}
	return true;//operation never reaches here.


}


int Logic::whose_turn(int turn) { return (this_rounds_first + turn) % number_of_players; }


void Logic::initializeNewSet() {
	set++;
	this_rounds_first++;
	this_rounds_first %= number_of_players;

	shuffle();
	DealCard();
	//notify clients of their cards(you can get cards using players[i]->GetCards() a vector  of cards ;
	// 
	// 
	//notify the client that it is his turn;

	char *code = Code::set_code('0', Code::fromServer_Sent_FirstPlayer);//this is "your turn" code
	DataPacket dummy;
	server->send_data(code, &dummy, this_rounds_first);
	//-----------------
	//????????????????????????????????????????????????????????????????????????????????????????
	//notify clients of their cards(you can get cards using players[i]->GetCards()  a vector  of cards ;


	char *code1 = Code::set_code('0', Code::fromServer_Sent_YourCards);
	for ( int i = 0; i < number_of_players; i++ ) {

		DataPacket data;
		data.player_cards;
		auto cards = players[i]->get_cards();

		for ( int j = 0; j < 7; j++ )
			data.player_cards[j] = cards[j]->GetNumber();

		server->send_data(code1, &data, i);
	}



}


void Logic::FillAllCards() {
	for ( int i = 0; i < number_of_players * 4; i++ ) {
		Card card1(Card::treasure, i);
		all_cards.push_back(card1);
		Card card2(Card::map, i);
		all_cards.push_back(card2);
		Card card3(Card::flag, i);
		all_cards.push_back(card3);
		Card card4(Card::parrot, i);
		all_cards.push_back(card4);
	}
	int pirates = number_of_players / 2 * 4;
	int kings = number_of_players / 2 * 3;
	int queens = number_of_players / 2 * 3;
	if ( number_of_players == 3 ) {
		pirates = 5;
		kings = 4;
		queens = 4;

	}
	for ( int i = 0; i < pirates; i++ ) {
		Card card(Card::pirate, -1);

		all_cards.push_back(card);

	}
	for ( int i = 0; i < kings; i++ ) {
		Card card(Card::queen, -1);

		all_cards.push_back(card);

	}
	for ( int i = 0; i < queens; i++ ) {
		Card card(Card::king, -1);

		all_cards.push_back(card);

	}
}
void Logic::StartGame() {
	DataPacket dummy;

	FillAllCards();
	for ( int set_number = 0; set_number < 7; set_number++ ) {
		shuffle();
		initializeNewSet();
		for ( int round_number = 0; round_number < set; round_number++ ) {
			int rounds_score = 0;



			for ( int i = 0; i < number_of_players; i++ ) {
				//get the predicted_rounds here for each player
				QVector<QPair<char *, DataPacket *>> data_vector = server->read_data_as_server();

				char *code2;
				code2 = data_vector[i].first;

				int prediction;
				if ( Code::get_code(code2) == Code::fromClient_Sent_Predictions )
					prediction = code2[3] - '0';//set this
				else {
					//handle it
				}


				//-----------------

				players[i]->SetRoundsPredicted(prediction);
			}
			this_rounds_first = getFirstPlayer();

			//notify clients of the first player(the parrot animation thing in gamehandeling should be played)
			char *code3 = Code::set_code('0', Code::fromServer_Sent_FirstPlayer);
			code3[3] = this_rounds_first;

			server->send_data(code3, &dummy);
			//--------------

			for ( int i = 0; i < number_of_players; i++ ) {
				Card::CardType type;
				int number;
				//Wait For the i-th player to move here and set the type and number(if it is role card set to -1)
				QVector<QPair<char *, DataPacket *>> data_vector = server->read_data_as_server();

				char *code4;
				code4 = data_vector[i].first;
				if ( Code::get_code(code4) == Code::fromClient_Sent_PlayedCard ) {

					Card::CardType type = code4[3] - '0';//set this
					int number = (type > 3) ? (code4[4] - '0') : (-1);//set this
				}
				//-----------------

				//informing all:
				char *code5 = Code::set_code(Code::fromServer_Sent_AnotherPlayerPlayedCard);
				code5[3] = type + '0';
				code5[4] = number + '0';
				for ( int j = 0; j < 4; j++ ) {
					if ( i == j )break;
					server->send_data(code5, &dummy, j);
				}
				//-------------------
				cards_on_deck.push_back(Card(type, number));


				if ( type == Card::king )rounds_score += 15;
				else if ( type == Card::queen )rounds_score += 20;
				else if ( type == Card::pirate )rounds_score += 10;
			}
			int winner_index = notifyAndGetThisRoundsWinner();
			players[winner_index]->SetPoints(players[winner_index]->GetPoints() + rounds_score);
			this_rounds_first = winner_index;
			//notify the round winner here;send winner_index
			char *code6 = Code::set_code(Code::fromServer_Sent_RoundWinner);
			code6[3] = winner_index;
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
				if ( players[i]->getRoundsWon() == players[i]->GetRoundsPredicted() == 0 ) {
					players[i]->SetPoints(players[i]->GetPoints() + players[i]->GetRoundsPredicted() * 10);
				}
				else {
					players[i]->SetPoints(players[i]->GetPoints() -
						abs(players[i]->GetRoundsPredicted() - players[i]->getRoundsWon()) * 10);
				}

			}


		}
		//notify the player their score here  players[i]->GetPoints();
		char *code7 = Code::set_code(Code::fromServer_Sent_YourScore);
		DataPacket data_packet;
		for ( int j = 0; j < 4; j++ ) {
			data_packet.your_points = players[j]->GetPoints();

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

	char *code8 = Code::set_code(Code::fromServer_Sent_GameWinner);
	code8[3] = winner;
	server->send_data(code8, &dummy);


}

void Logic::DealCard() {
	int index = 0;
	for ( int i = 0; i < number_of_players; i++ ) {
		QVector<Card> vec;
		for ( int i = index; i < index + round * 2; i++ ) {
			vec.push_back(all_cards[i]);
		}
		index += 2 * round;


	}
}

void Logic::shuffle() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(all_cards.begin(), all_cards.end(), gen);

}
void Logic::SwapCard(int player_index1, int player_index2, Card::CardType type1, Card::CardType type2, int num1, int num2) {
	auto players1_cards = players[player_index1]->get_cards();
	auto players2_cards = players[player_index2]->get_cards();
	for ( Card *card : players1_cards ) {
		if ( card->GetType() == type1, card->GetNumber() == num1 ) {
			card->ChangeCard(type2, num2);





		}
	}

	for ( Card *card : players2_cards ) {
		if ( card->GetType() == type2, card->GetNumber() == num2 ) {
			card->ChangeCard(type1, num2);





		}
	}
}



