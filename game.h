#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;
class Game {
public:
	Game() = default;
	Game(const string &winner, const string &time, int rounds_won, int coins_achieved, int predicted_rounds);
	Game(const Game &that);
	//string Parse();


private:
	string winner;
	string time;
	int rounds_won;
	int coins_achieved;
	int predicted_rounds;


};

#endif // GAME_H
