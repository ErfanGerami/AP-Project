#ifndef GAME_H
#define GAME_H
#include <QString>

class Game {
public:
	Game() = default;
    Game(const QString &winner, const QString &time, int rounds_won, int coins_achieved, int predicted_rounds,int score,bool is_played);
	Game(const Game &that);
	//QString Parse();

    QString GetWinner();
    QString GetTime();
    int GetRoundsWon();
    int GetCoinsAchieved();
    int GetPredictedRounds();
    int GetScore();
    bool GetIsPlayed();
private:
	QString winner;
	QString time;
	int rounds_won;
	int coins_achieved;
	int predicted_rounds;
    int score;
    bool is_played;


};

#endif // GAME_H
