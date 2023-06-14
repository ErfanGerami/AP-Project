#include "player.h"





Player::Player(const string &username, const string &password, int rank, int games_won, int games_loose, const string &phone_number, const string &address, const string &email, const Game &prev_game)
	:username(username), password_hash(hash(password, username)), rank(rank), games_won(games_won), games_loose(games_loose), phone_number(phone_number), address(address), email(email), prev_game(prev_game) {}





Player::Player(const Player &that): username(that.username), password_hash(that.password_hash), rank(that.rank), games_won(that.games_won), games_loose(that.games_loose), phone_number(that.phone_number), address(that.address), email(that.email), prev_game(that.prev_game) {}


void Player::change_password(string password) { this->password_hash = hash(password, this->username); }




unsigned long Player::hash(const string &password, const string &username) {
	string s = password + username;

	std::string str = s/*.toStdString()*/;
	unsigned long h;

	int MULTIPLIER = 37;
	int c = 0;
	int i = 255;
	h = 0;
	while ( str.size() != c ) {
		h = h * MULTIPLIER + str[c] * i;
		c++;
		i = i * str[c] - i;
	}

	return h;
}


Player::Player(const string &username, const string &password):username(username), password_hash(hash(password, username)), rank(0), games_won(0), games_loose(0), phone_number(""), address(""), email(""), prev_game() {}


string Player::get_username() const { return username; }



string Player::get_phone_number() const { return phone_number; }

bool Player::is_password_correct(string password) {
	return hash(password, this->username) == password_hash;
}


//string Player::Parse() {
//	if ( prev_game == nullptr ) {
//		return name + '/' + password + '/' + string(rank) + '/' + string(games_won) + '/' + string(games_loose) + '/' + this->phone_number + '/' +
//			this->address + "null";
//	}
//	else {
//		return name + '/' + password + '/' + string(rank) + '/' + string(games_won) + '/' + string(games_loose) + '/' + this->phone_number + '/' +
//			this->address + '/' + prev_game->Parse();
//
//	}
//
//}
//

