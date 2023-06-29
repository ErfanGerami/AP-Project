#include "Code.h"

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



int Code::get_code(char *code) {
	if ( code[0] == '0' && code[1] == '2' && code[2] == '0' )
		return fromServer_Sent_YourCards;

	if ( code[0] == '0' && code[1] == '0' && code[2] == '1' )
		return fromServer_Sent_YourTurn;

	if ( code[1] == '0' && code[2] == '2' )
		return fromClient_Sent_Predictions;

	if ( code[0] == '0' && code[1] == '0' && code[2] == '3' )
		return fromServer_Sent_FirstPlayer;

	if ( code[1] == '0' && code[2] == '4' )
		return fromClient_Sent_PlayedCard;

	if ( code[0] == '0' && code[1] == '0' && code[2] == '5' )
		return fromServer_Sent_RoundWinner;

	if ( code[0] == '0' && code[1] == '0' && code[2] == '6' )
		return fromServer_Sent_YourScore;

	if ( code[0] == '0' && code[1] == '0' && code[2] == '7' )
		return fromServer_Sent_GameWinner;

	if ( code[0] == '0' && code[1] == '0' && code[2] == '8' )
		return fromServer_Sent_AnotherPlayerPlayedCard;

	if ( code[0] == '0' && code[1] == '2' && code[2] == '9' )
		return fromServer_Sent_PlayerNames;

	if ( code[0] == '0' && code[1] == '2' && code[2] == 'a' )
		return fromServer_Sent_GameStarted;

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

	if ( code == fromServer_Sent_AnotherPlayerPlayedCard )
		c[2] = 'a';

	return c;
}