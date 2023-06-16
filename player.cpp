#include "player.h"





Player::Player(const string &username, const string &password, int rank, int games_won, int games_loose, const string &phone_number, const string &address, const string &email,int coins, const Game &prev_game)
    :username(username), password_hash(hash(password, username)), rank(rank), games_won(games_won), games_loose(games_loose), phone_number(phone_number), address(address), email(email), coins(coins),prev_game(prev_game) {}





Player::Player(const Player &that): username(that.username), password_hash(that.password_hash), rank(that.rank), games_won(that.games_won), games_loose(that.games_loose), phone_number(that.phone_number), address(that.address), email(that.email), coins(that.coins),prev_game(that.prev_game) {}


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



bool Player::is_password_correct(string password) {
	return hash(password, this->username) == password_hash;
}
unsigned long Player::GetPassWord()const{return this->password_hash;};
string Player::GetUserName()const{return this->username;};
int Player::GetRank()const{return rank;}
int Player::GetGamesWon()const{return games_won;}
int Player::GetGamesLoose()const{return games_loose;}
string Player::GetPhonNnumber()const{return phone_number;};
string Player::GetAddress()const{return address;}
string Player::GetEmail()const{return email;}
int Player::GettCoins()const{return coins;}
Game Player::GetPrevGame()const{return prev_game;};

void Player::SetRank(int rank){this->rank=rank;}
void Player::SettCoins(int coins){this->coins=coins;}
void Player::SetGamesWon(int games_won){this->games_won=games_won;}
void Player::SetGamesLoose(int games_loose){this->games_loose=games_loose;}
void Player::SetPhonNnumber(string phone_numer){this->phone_number=phone_number;}
void Player::SetAddress(string address){this->address=address;}
void Player::SetEmail(string email){this->email=email;}
void Player::SetPrevGame(Game prev_game){this->prev_game=prev_game;}
void Player::SetPassword(string password){this->password_hash = hash(password, this->username);}
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

