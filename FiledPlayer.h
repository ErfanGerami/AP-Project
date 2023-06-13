#ifndef FILEDPLAYER
#define FILEDPLAYER



#include "game.h"
#include "player.h"
#include "User.h"
#include <QString>




class FiledPlayer:
	protected User {
	friend class Player;
private:

	Game prev_game;


public:

	FiledPlayer() = default;

	FiledPlayer(const QString &name, const unsigned long &password, int rank, int games_won, int games_loose, const Game &prev_game, const QString &phone_number, const QString &address, const QString &email);

	FiledPlayer(const FiledPlayer &that);

	FiledPlayer(const Player &player);

	//FiledPlayer(const Player *player);

	QString get_username() const;

	bool is_password_correct(unsigned long password);

};


#endif // !FILEDPLAYER