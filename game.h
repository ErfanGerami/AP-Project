#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <QString>
using namespace std;
class Game {
public:
	Game() = default;

	Game(const string &winner, const string &time, int rounds_won, int coins_achieved, int predicted_rounds, int score, int is_played);
	Game(const Game &that);
	//string Parse();

	string GetWinner();
	string GetTime();
	int GetRoundsWon();
	int GetCoinsAchieved();
	int GetPredictedRounds();
	int GetScore();
	bool GetIsPlayed();
private:
	string winner;
	string time;
	int rounds_won;
	int coins_achieved;
	int predicted_rounds;
	int score;
	bool is_played;


};

#endif // GAME_H
