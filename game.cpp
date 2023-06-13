#include "game.h"



//QString Game::Parse() {
//	return winner + '/' + time;
//
//}


Game::Game(const QString &winner, const QString &time, int rounds_won, int coins_achieved, int predicted_rounds)
	: winner(winner), time(time), rounds_won(rounds_won), coins_achieved(coins_achieved), predicted_rounds(predicted_rounds), valid(true) {}

Game::Game(const Game &that): winner(that.winner), time(that.time), rounds_won(that.rounds_won), coins_achieved(that.coins_achieved), predicted_rounds(that.predicted_rounds) {}


