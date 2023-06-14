#ifndef GAME_H
#define GAME_H
#include <QString>

class Game {
public:
	Game() = default;
	Game(const QString &winner, const QString &time, int rounds_won, int coins_achieved, int predicted_rounds);
	Game(const Game &that);
	//QString Parse();


private:
	QString winner;
	QString time;
	int rounds_won;
	int coins_achieved;
	int predicted_rounds;


};

#endif // GAME_H
