#ifndef PLAYER_H
#define PLAYER_H
#include "game.h"
#include "FiledPlayer.h"
#include <QString>
#include "User.h"
class Player:
	protected User {

	friend class FiledPlayer;

private:

	Game *prev_game;



public:
	Player() = default;

	Player(QString name, QString password);
	//QString Parse();

	Player(const QString &name, const QString &password, int rank, int games_won, int games_loose, const QString &phone_number, const QString &address, const QString &email, Game *prev_game);

	Player(const Player &that);

	Player(const FiledPlayer &filedplayer);

	~Player();



};

#endif // PLAYER_H
