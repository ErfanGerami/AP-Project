#include "serverplayeringame.h"

ServerPlayerInGame::ServerPlayerInGame() {

}


void ServerPlayerInGame::NewCards(QVector<ServerCard *> cards) {
	this->cards = cards;
}
ServerPlayerInGame::ServerPlayerInGame(string user, string password):Player(user, password) {
	this->points = 0;
    this->rounds_won=0;

}
void ServerPlayerInGame::operator=(const ServerPlayerInGame &other) {
	this->points = 0;
    this->rounds_won=other.rounds_won;
	int place = other.place;
	QVector<ServerCard *> cards = other.cards;
	int rounds_won = other.rounds_won;
	int predicted_rounds = other.predicted_rounds;
	int points = other.points;
	this->username = other.username;
	this->password_hash = other.password_hash;
}
ServerPlayerInGame::ServerPlayerInGame(const ServerPlayerInGame &that) {
	(*this) = that;
}

void ServerPlayerInGame::SetRoundsPredicted(int predicted_round) { this->predicted_rounds = predicted_round; }
int ServerPlayerInGame::GetRoundsPredicted() { return this->predicted_rounds; }
int ServerPlayerInGame::getRoundsWon() { return rounds_won; }
void ServerPlayerInGame::setRoundsWon(int rounds_won) { this->rounds_won = rounds_won; }
void ServerPlayerInGame::SetPoints(int points) { this->points = points; }
int ServerPlayerInGame::GetPoints() { return this->points; }
int ServerPlayerInGame::GetPlace() { return this->place; }
QVector<ServerCard *> ServerPlayerInGame::get_cards() { return this->cards; }

ServerCard *ServerPlayerInGame::PushCard(ServerCard::CardType card_type, int number, bool was_unknow) {
	if ( was_unknow ) {

		ServerCard *card = cards.front();
		cards.pop_front();
		return card;
	}
	else {
		for ( auto itr = cards.begin(); itr != cards.end(); itr++ ) {
			if ( (*itr)->GetNumber() == number && (*itr)->GetType() == card_type ) {

				ServerCard *card = *itr;

				cards.erase(itr);
				return card;

			}

		}
	}
	return nullptr;

}
bool ServerPlayerInGame::haveType(ServerCard::CardType type) {
	for ( const auto &card : cards ) {
		if ( card->GetType() == type ) {
			return true;
		}
	}
	return false;
}
