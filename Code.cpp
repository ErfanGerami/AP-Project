#include "Code.h"
#include <qdebug.h>

const  int Code::undefined = -1;
const int Code::fromServer_Sent_YourCards = 0;
const int Code::fromServer_Sent_YourTurn = 1;
const int Code::fromClient_Sent_Predictions = 2;
const int Code::fromServer_Sent_FirstPlayer = 3;
const int Code::fromClient_Sent_PlayedCard = 4;
const int Code::fromServer_Sent_RoundWinner = 5;
const int Code::fromServer_Sent_YourScore = 6;
const int Code::fromServer_Sent_GameWinner = 7;
const int Code::fromServer_Sent_AnotherPlayerPlayedCard = 8;
const int Code::fromServer_Sent_PlayerNames = 9;
const int Code::fromServer_Sent_GameStarted = 10;
const int Code::Sent_Pause = 11;
const int Code::Requested_SwapCard = 12;
const int Code::Accepted_SwapCard = 13;
const int Code::Denied_SwapCard = 14;

int Code::get_code(char *code) {
	qDebug() << "recived code:";
	qDebug() << QString(code[0]) + QString(code[1]) + QString(code[2]) + QString(code[3]) + QString(code[4]);


	if ( code[1] == '2' && code[2] == '0' )
		return fromServer_Sent_YourCards;

	if ( code[1] == '0' && code[2] == '1' )
		return fromServer_Sent_YourTurn;

	if ( code[1] == '0' && code[2] == '2' )
		return fromClient_Sent_Predictions;

	if ( code[1] == '0' && code[2] == '3' )
		return fromServer_Sent_FirstPlayer;

	if ( code[1] == '0' && code[2] == '4' )
		return fromClient_Sent_PlayedCard;

	if ( code[1] == '0' && code[2] == '5' )
		return fromServer_Sent_RoundWinner;

	if ( code[1] == '0' && code[2] == '6' )
		return fromServer_Sent_YourScore;

	if ( code[1] == '0' && code[2] == '7' )
		return fromServer_Sent_GameWinner;

	if ( code[1] == '0' && code[2] == '8' )
		return fromServer_Sent_AnotherPlayerPlayedCard;

	if ( code[1] == '2' && code[2] == '9' )
		return fromServer_Sent_PlayerNames;

	if ( code[1] == '2' && code[2] == 'a' )
		return fromServer_Sent_GameStarted;

	if ( code[1] == '0' && code[2] == 'b' )
		return Sent_Pause;

	if ( code[1] == '0' && code[2] == 'c' )
		return Requested_SwapCard;

	if ( code[1] == '0' && code[2] == 'd' )
		return Accepted_SwapCard;

	if ( code[1] == '0' && code[2] == 'e' )
		return Denied_SwapCard;

	return undefined;
}

char *Code::set_code(char sender, int code) {
	char *c = new char[6];
	c[0] = sender;
	c[1] = '0';
	c[3] = c[4] = '0';


	if ( code == fromServer_Sent_YourCards ) {
		c[1] = '2';
		c[2] = '0';
	}

	if ( code == fromServer_Sent_YourTurn )
		c[2] = '1';


	if ( code == fromClient_Sent_Predictions )
		c[2] = '2';


	if ( code == fromServer_Sent_FirstPlayer )
		c[2] = '3';


	if ( code == fromClient_Sent_PlayedCard )
		c[2] = '4';


	if ( code == fromServer_Sent_RoundWinner )
		c[2] = '5';


	if ( code == fromServer_Sent_YourScore )
		c[2] = '6';


	if ( code == fromServer_Sent_GameWinner )
		c[2] = '7';


	if ( code == fromServer_Sent_AnotherPlayerPlayedCard )
		c[2] = '8';

	if ( code == fromServer_Sent_PlayerNames ) {
		c[1] = '2';
		c[2] = '9';
	}

	if ( code == fromServer_Sent_GameStarted ) {
		c[1] = '2';
		c[2] = 'a';
	}

	if ( code == Sent_Pause ) {
		c[2] = 'b';
	}

	if ( code == Requested_SwapCard ) {
		c[2] = 'c';
	}

	if ( code == Accepted_SwapCard ) {
		c[2] = 'd';
	}

	if ( code == Denied_SwapCard ) {
		c[2] = 'e';
	}

	qDebug() << "created code:";
	qDebug() << QString(c[0]) + QString(c[1]) + QString(c[2]) + QString(c[3]) + QString(c[4]);

	return c;
}