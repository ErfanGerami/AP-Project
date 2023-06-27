#include "playerInGame.h"


void PlayerInGame::operator=(const PlayerInGame &that) {
	this->username = that.username;
	this->password_hash = that.password_hash;
	this->rank = that.rank;
	this->games_won = that.games_won;
	this->games_loose = that.games_loose;
	this->phone_number = that.phone_number;
	this->address = that.address;
	this->email = that.email;
	this->coins = that.coins;
	this->prev_game = that.prev_game;

	this->cards = that.cards;
	this->base_pos = that.base_pos;
	this->cards_won_pos = that.cards_won_pos;
	this->place = that.place;
	this->rounds_won = that.rounds_won;
	this->predicted_rounds = that.predicted_rounds;
	this->points = points;




}
PlayerInGame::PlayerInGame(const PlayerInGame &that) {
	(*this) = that;
}

PlayerInGame::PlayerInGame():Player() {
	this->cards = {};
	this->base_pos = { 0, 0 };
	this->place = -1;
	this->rounds_won = 0;
	this->predicted_rounds = 0;
	this->points = 0;

}
PlayerInGame::PlayerInGame(const string &username, const string &password, int rank, int games_won, int games_loose
	, const string &phone_number, const string &address, const string &email, const int coins
	, QVector<Card *> cards, std::pair<int, int> base_pos, int place, Game prev_game = Game(), int round_won = 0, int predicted_rounds = 0, int points = 0)

	: Player(username, password, rank, games_won, games_loose, phone_number
		, address, email, coins, prev_game) {
	this->cards = cards;
	this->base_pos = base_pos;
	this->place = place;
	this->predicted_rounds = predicted_rounds;
	this->points = points;
	CalculateWonCardPosition();



}
PlayerInGame::PlayerInGame(const Player &player, int place, QVector<Card *> cards, int rounds_won = 0): Player(player) {
	//fix thiss later;
	this->cards = cards;
	this->place = place;
	this->rounds_won = 0;
	this->points = 0;


}

void PlayerInGame::NewCards(QVector<Card *> cards) {
	this->cards = cards;

}

Card *PlayerInGame::PushCard(Card::CardType card_type, int number) {
	for ( auto itr = cards.begin(); itr != cards.end(); itr++ ) {
		if ( (*itr)->GetNumber() == number && (*itr)->GetType() == card_type ) {

			Card *card = new Card(**itr);

			cards.erase(itr);
			return card;

		}

	}
	return nullptr;
}

std::pair<int, int> PlayerInGame::GetBasePos() { return base_pos; }

void PlayerInGame::SetRoundsPredicted(int predicted_round) { this->predicted_rounds = predicted_round; }

int PlayerInGame::GetRoundsPredicted() { return this->predicted_rounds; }

void PlayerInGame::SetBasePos(std::pair<int, int> base_pos) { this->base_pos = base_pos; CalculateWonCardPosition(); }

void PlayerInGame::SetPoints(int points) { this->points = points; }

int PlayerInGame::GetPoints() { return points; }

int PlayerInGame::GetPlace() { return place; }

QVector<Card *> PlayerInGame::get_cards() { return cards; }

std::pair<int, int> PlayerInGame::GetCardsWonPos() { return cards_won_pos; }

void PlayerInGame::CalculateWonCardPosition() {

	cards_won_pos = base_pos;
	switch ( place ) {
		case 0:
			cards_won_pos = { 500, 350 };
			break;
		case 1:
			cards_won_pos = { 700, -350 };
			break;
		case 2:
			cards_won_pos = { -500, -350 };
			break;
		case 3:
			cards_won_pos = { -600, 350 };
			break;

	}
}


void PlayerInGame::Deal() {

	int rotation = 270 - (place + 1) * 90 - (cards.size() / 2 - 1) * Card::angle_between_cards - 10;
	auto position = base_pos;
	switch ( place ) {
		case 0:
			position.first -= Card::space_between_cards * (cards.size() / 2 - 1);
			break;

		case 1:
			position.second += Card::space_between_cards * (cards.size() / 2 - 1);
			break;
		case 2:
			position.first += Card::space_between_cards * (cards.size() / 2 - 1);
			break;
		case 3:
			position.second -= Card::space_between_cards * (cards.size() / 2 - 1);

			break;



	}


	std::sort(cards.begin(), cards.end(), [] (Card *c1, Card *c2) {return (c1->GetType() > c2->GetType()); });
	for ( auto &card : cards ) {

		card->show();

		card->PushTo(position, rotation);
		rotation += Card::angle_between_cards;
		switch ( place ) {
			case 0:
				position.first += Card::space_between_cards;
				break;

			case 1:
				position.second -= Card::space_between_cards;
				break;
			case 2:
				position.first -= Card::space_between_cards;
				break;
			case 3:
				position.second += Card::space_between_cards;
				break;



		}
	}



}
bool PlayerInGame::haveType(Card::CardType type) {
	for ( const auto &card : cards ) {
		if ( card->GetType() == type ) {
			return true;
		}
	}
	return false;
}
int PlayerInGame::getRoundsWon() { return this->rounds_won; }
void PlayerInGame::setRoundsWon(int rounds_won) { this->rounds_won = rounds_won; }

