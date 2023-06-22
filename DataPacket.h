#ifndef DATAPACKET
#define DATAPACKET

#include <QString>
#include <QDataStream>
#include <QByteArray>


class DataPacket {
private:
	//host will always be number 0 and others'll get numbered in order


	QString Message;
	int command_code;/*
	0: refresh the game from below ateributes
	1:
	*/


	QString server_name;
	QString player_count;
	QString player_name[4];
	int player_bet[4];
	int player_won_round[4];
	int player_Lost_round[4];
	int player_cards[4][7];
	int player_used_timeout[4];
	bool player_dropped[4];
	bool player_abandoned[4];
	bool player_is_swapping_card[4];
	int rounds_passed;
	int current_round;
	bool is_game_in_timeout;




public:


};


#endif // !DATAPACKET