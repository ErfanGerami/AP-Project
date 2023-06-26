#include "DataPacket.h"



DataPacket::DataPacket(QString server_name, int player_count, QString plauer_name[4], int player_bet[4], int player_cards[4][7]) {

	this->server_name = server_name;
	this->player_count = player_count;

	for ( int i = 0; i < 4; i++ )
		this->player_name[i] = plauer_name[i];

	for ( int i = 0; i < 4; i++ )
		this->player_bet[i] = player_bet[i];

	for ( int i = 0; i < 4; i++ )
		for ( int j = 0; j < 7; j++ )
			this->player_cards[i][j] = player_cards[i][j];
}
