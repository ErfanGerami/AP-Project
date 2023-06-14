#ifndef PLAYER_H
#define PLAYER_H
#include "game.h"
#include <string>
using namespace std;

class Player {



private:

	string username;
	unsigned long password_hash;
	int rank;
	int games_won;
	int games_loose;
    int coins;
	string phone_number;
	string address;
	string email;
	Game prev_game;



public:
	Player() = default;


    Player(const string &username, const string &password, int rank, int games_won, int games_loose, const string &phone_number, const string &address, const string &email,const int coins, const Game &prev_game = Game());



	Player(const string &username, const string &password);

	Player(const Player &that);


	static unsigned long hash(const string &password, const string &username);


	string get_username() const;

	bool is_password_correct(string password);



    int GetRank();
    int GettCoins();
    int GetGamesWon();
    int GetGamesLoose();
    string GetPhonNnumber();
    string GetAddress();
    string GetEmail();
    Game GetPrevGame();

	//string Parse();


};

#endif // PLAYER_H
