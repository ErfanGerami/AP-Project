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


QDataStream &operator>> (QDataStream &in, DataPacket &obj) {
	in >> obj.your_points;
	in >> obj.server_name;
	in >> obj.player_count;

	for ( int i = 0; i < 4; i++ )
		in >> obj.player_name[i];

	for ( int i = 0; i < 4; i++ )
		in >> obj.player_bet[i];

	for ( int j = 0; j < 7; j++ )
		in >> obj.player_cards[j];

	for ( int i = 0; i < 4; i++ )
		in >> obj.player_won_round[i];

	for ( int i = 0; i < 4; i++ )
		in >> obj.player_Lost_round[i];

	for ( int i = 0; i < 4; i++ )
		in >> obj.player_used_timeout[i];

	for ( int i = 0; i < 4; i++ )
		in >> obj.player_dropped[i];

	for ( int i = 0; i < 4; i++ )
		in >> obj.player_abandoned[i];

	for ( int i = 0; i < 4; i++ )
		in >> obj.player_is_swapping_card[i];

	in >> obj.rounds_passed;

	in >> obj.current_round;

	in >> obj.is_game_in_timeout;

	return in;

}

QDataStream &operator<<(QDataStream &out, DataPacket &obj) {
	out << obj.your_points;

	out << obj.server_name;
	out << obj.player_count;

	for ( int i = 0; i < 4; i++ )
		out << obj.player_name[i];

	for ( int i = 0; i < 4; i++ )
		out << obj.player_bet[i];

	for ( int j = 0; j < 7; j++ )
		out << obj.player_cards[j];

	for ( int i = 0; i < 4; i++ )
		out << obj.player_won_round[i];

	for ( int i = 0; i < 4; i++ )
		out << obj.player_Lost_round[i];

	for ( int i = 0; i < 4; i++ )
		out << obj.player_used_timeout[i];

	for ( int i = 0; i < 4; i++ )
		out << obj.player_dropped[i];

	for ( int i = 0; i < 4; i++ )
		out << obj.player_abandoned[i];

	for ( int i = 0; i < 4; i++ )
		out << obj.player_is_swapping_card[i];

	out << obj.rounds_passed;

	out << obj.current_round;

	out << obj.is_game_in_timeout;

	return out;

}


template<class archive>
void DataPacket::serialize(archive &ar, const unsigned int version) {

	ar &your_points;
	ar &server_name;
	ar &player_count;

	for ( int i = 0; i < 4; i++ )
		ar &player_name[i];

	for ( int i = 0; i < 4; i++ )
		ar &player_bet[i];

	for ( int i = 0; i < 4; i++ )
		ar &player_won_round[i];

	for ( int i = 0; i < 4; i++ )
		ar &player_Lost_round[i];

	for ( int j = 0; j < 7; j++ )
		ar &player_cards[j];

	for ( int i = 0; i < 4; i++ )
		ar &player_used_timeout[i];

	for ( int i = 0; i < 4; i++ )
		ar &player_dropped[i];

	for ( int i = 0; i < 4; i++ )
		ar &player_abandoned[i];

	for ( int i = 0; i < 4; i++ )
		ar &player_is_swapping_card[i];

	ar &rounds_passed;

	ar &current_round;

	ar &is_game_in_timeout;

}

