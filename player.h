#ifndef PLAYER_H
#define PLAYER_H
#include "game.h"
#include <QString>


class Player {



private:

	QString username;
	unsigned long password_hash;
	int rank;
	int games_won;
	int games_loose;
	QString phone_number;
	QString address;
	QString email;
	Game prev_game;



public:
	Player() = default;


	Player(const QString &username, const QString &password, int rank, int games_won, int games_loose, const QString &phone_number, const QString &address, const QString &email, const Game &prev_game = Game());



	Player(const QString &username, const QString &password);

	Player(const Player &that);


	static unsigned long hash(const QString &password, const QString &username);


	QString get_username() const;

	bool is_password_correct(QString password);

	//QString Parse();


};

#endif // PLAYER_H
