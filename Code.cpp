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

	return undefined;
}

char *Code::set_code(char sender, int code) {
	char *c = new char[6];
	c[0] = sender;
	c[1] = '0';
	c[4] = c[5] = '0';


	if ( code == fromServer_Sent_YourCards ) {
		c[1] = '2';
		c[3] = '0';
	}

	if ( code == fromServer_Sent_YourTurn )
		c[3] = '1';


	if ( code == fromClient_Sent_Predictions )
		c[3] = '2';


	if ( code == fromServer_Sent_FirstPlayer )
		c[3] = '3';


	if ( code == fromClient_Sent_PlayedCard )
		c[3] = '4';


	if ( code == fromServer_Sent_RoundWinner )
		c[3] = '5';


	if ( code == fromServer_Sent_YourScore )
		c[3] = '6';


	if ( code == fromServer_Sent_GameWinner )
		c[3] = '7';


	if ( code == fromServer_Sent_AnotherPlayerPlayedCard )
		c[3] = '8';


	return c;
}