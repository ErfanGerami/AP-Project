#include "player.h"





Player::Player(const QString &name, const unsigned long &password, int rank, int games_won, int games_loose, const QString &phone_number, const QString &address, const QString &email, Game *prev_game)
	: User(name, password, rank, games_won, games_loose, phone_number, address, email), prev_game(prev_game) {}



Player::Player(const Player &that): User(that.name, that.password_hash, that.rank, that.games_won, that.games_loose, that.phone_number, that.address, that.email), prev_game(that.prev_game) {}



Player::Player(const FiledPlayer &filed_player): User(filed_player.name, filed_player.password_hash, filed_player.rank, filed_player.games_won, filed_player.games_loose, filed_player.phone_number, filed_player.address, filed_player.email) {
	if ( filed_player.prev_game.valid == true )
		this->prev_game = new Game(filed_player.prev_game);
	else
		this->prev_game = nullptr;
}

unsigned long Player::hash(QString password, QString username) {
	QString s = password + username;


	unsigned long h;
	unsigned const char *us;
	int MULTIPLIER = 37;
	us = (unsigned const char *)s.toStdString().c_str();
	int i = 255;
	h = 0;
	while ( *us != '\0' ) {
		h = h * MULTIPLIER + *us * i;
		us++;
		i = i * *us - i;
	}

	return h;
}


Player::Player(QString name, unsigned long password_hash):User(name, password_hash, 0, 0, 0, "", "", ""), prev_game(nullptr) {}

Player::~Player() { delete prev_game; }


//QString Player::Parse() {
//	if ( prev_game == nullptr ) {
//		return name + '/' + password + '/' + QString(rank) + '/' + QString(games_won) + '/' + QString(games_loose) + '/' + this->phone_number + '/' +
//			this->address + "null";
//	}
//	else {
//		return name + '/' + password + '/' + QString(rank) + '/' + QString(games_won) + '/' + QString(games_loose) + '/' + this->phone_number + '/' +
//			this->address + '/' + prev_game->Parse();
//
//	}
//
//}
//

