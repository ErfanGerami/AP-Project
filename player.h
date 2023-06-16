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

	void change_password(string password);


	static unsigned long hash(const string &password, const string &username);



	bool is_password_correct(string password);



    int GetRank()const;
    int GettCoins()const ;
    int GetGamesWon()const;
    int GetGamesLoose()const;
    string GetPhonNnumber()const;
    string GetAddress()const;
    string GetEmail()const;
    string GetUserName()const;
    Game GetPrevGame()const;
    unsigned long GetPassWord()const;

    void SetPassword(string password);
    void SetRank(int rank);
    void SettCoins(int coins);
    void SetGamesWon(int game_won);
    void SetGamesLoose(int games_loose);
    void SetPhonNnumber(string phone_numer);
    void SetAddress(string address);
    void SetEmail(string email);
    void SetPrevGame(Game prev_game);

	//string Parse();


};

#endif // PLAYER_H
