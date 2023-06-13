#include "FiledPlayer.h"



FiledPlayer::FiledPlayer(const QString &name, const unsigned long &password_hash, int rank, int games_won, int games_loose, const Game &prev_game, const QString &phone_number, const QString &address, const QString &email)
	:User(name, password_hash, rank, games_won, games_loose, phone_number, address, email), prev_game(prev_game) {}


FiledPlayer::FiledPlayer(const FiledPlayer &that):User(that.name, that.password_hash, that.rank, that.games_won, that.games_loose, that.phone_number, that.address, that.email), prev_game(that.prev_game) {}


FiledPlayer::FiledPlayer(const Player &player): User(player.name, player.password_hash, player.rank, player.games_won, player.games_loose, player.phone_number, player.address, player.email) {
	if ( player.prev_game == nullptr ) {
		this->prev_game.valid = false;
	}
	else
		this->prev_game = *player.prev_game;
}

//FiledPlayer::FiledPlayer(const Player *player): name(player->name), password(player->password), rank(player->rank), games_won(player->games_won), games_loose(player->games_loose), phone_number(player->phone_number), address(player->address), email(player->email) {
//	this->prev_game = *player->prev_game;
//}

QString FiledPlayer::get_username() const { return name; }

bool FiledPlayer::is_password_correct(unsigned long password_hash) { return this->password_hash == password_hash; }
