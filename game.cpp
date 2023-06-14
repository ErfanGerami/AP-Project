#include "game.h"



//QString Game::Parse() {
//	return winner + '/' + time;
//
//}


Game::Game(const QString &winner, const QString &time, int rounds_won, int coins_achieved, int predicted_rounds,int score ,bool is_played)
    : winner(winner), time(time), rounds_won(rounds_won), coins_achieved(coins_achieved), predicted_rounds(predicted_rounds)
    ,score(score),is_played(is_played) {}

Game::Game(const Game &that): winner(that.winner), time(that.time), rounds_won(that.rounds_won),
    coins_achieved(that.coins_achieved), predicted_rounds(that.predicted_rounds),score(that.score),is_played(that.is_played)

    {}
QString Game::GetWinner(){return winner;}
QString Game::GetTime(){return time;};
int Game::GetRoundsWon(){return rounds_won;};
int Game::GetCoinsAchieved(){return coins_achieved;}
int Game::GetPredictedRounds(){return predicted_rounds;};
int Game::GetScore(){return score;};
bool Game::GetIsPlayed(){return is_played;}


