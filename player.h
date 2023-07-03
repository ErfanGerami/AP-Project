#ifndef PLAYER_H
#define PLAYER_H
#include "game.h"
#include <string>
using namespace std;

class Player {


protected:

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
    bool earned_coins;



public:

	Player() = default;


	Player(const string &username, const string &password, int rank, int games_won, int games_loose, const string &phone_number, const string &address, const string &email, const int coins, const Game &prev_game = Game());



	Player(const string &username, const string &password);

	Player(const Player &that);

	void change_password(string password);


	static unsigned long hash(const string &password, const string &username);



	bool is_password_correct(string password);


    bool GetEarnedCoins()const;
	int GetRank()const;
	int GettCoins()const;
	int GetGamesWon()const;
	int GetGamesLoose()const;
	string GetPhonNnumber()const;
	string GetAddress()const;
	string GetEmail()const;
	string GetUserName()const;
	Game GetPrevGame()const;
	unsigned long GetPassWord()const;

	void SetUsername(string username);

    void SetEarnedCoins(bool earned_coins);
	void SetPassword(string password);
	void SetPasswordAlreadyHashed(unsigned long password_hash);
	void SetRank(int rank);
	void SettCoins(int coins);
	void SetGamesWon(int game_won);
	void SetGamesLoose(int games_loose);
	void SetPhonNnumber(string phone_number);
	void SetAddress(string address);
	void SetEmail(string email);
	void SetPrevGame(Game prev_game);

	//string Parse();


};

#endif // PLAYER_H
