#pragma once
#include <iostream>


class Code {
public:
	const static int undefined;
	const static int fromServer_Sent_YourCards;
	const static int fromServer_Sent_YourTurn;
	const static int fromClient_Sent_Predictions;
	const static int fromServer_Sent_FirstPlayer;
	const static int fromClient_Sent_PlayedCard;
	const static int fromServer_Sent_RoundWinner;
	const static int fromServer_Sent_YourScore;
	const static int fromServer_Sent_GameWinner;
	const static int fromServer_Sent_AnotherPlayerPlayedCard;
	const static int fromServer_Sent_PlayerNames;
	const static int fromServer_Sent_GameStarted;

	static int get_code(char *code);
	static char *set_code(char sender, int code);


};

