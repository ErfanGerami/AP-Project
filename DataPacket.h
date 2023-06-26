#ifndef DATAPACKET
#define DATAPACKET

#include <QString>
#include <QDataStream>
#include <QByteArray>


class DataPacket {
private:


	QString server_name;
	int player_count;
	QString player_name[4];
	int player_bet[4];
	int player_cards[4][7];
	int player_won_round[4] = { 0 };
	int player_Lost_round[4] = { 0 };
	int player_used_timeout[4] = { 0 };
	bool player_dropped[4] = { false };
	bool player_abandoned[4] = { false };
	bool player_is_swapping_card[4] = { false };
	int rounds_passed = 0;
	int current_round = 0;
	bool is_game_in_timeout = false;




public:
	DataPacket() = default;

	DataPacket(QString server_name, int player_count, QString plauer_name[4], int player_bet[4], int player_cards[4][7]);

	/*DataPacket(QString server_name, int player_count, QString plauer_name[4], int player_bet[4], int player_cards[4][7], int player_won_round[4] = { 0 }, int player_Lost_round[4] = { 0 }, int player_used_timeout[4] = { 0 }, bool player_dropped[4] = { false }, bool player_abandoned[4] = { false }, bool player_is_swapping_card[4] = { false }, int rounds_passed = 0, int current_round = 0, bool is_game_in_timeout = false);*/


	friend QDataStream &operator>>(QDataStream &in, DataPacket &obj) {
		in >> obj.server_name;
		in >> obj.player_count;

		for ( int i = 0; i < 4; i++ )
			in >> obj.player_name[i];

		for ( int i = 0; i < 4; i++ )
			in >> obj.player_bet[i];

		for ( int i = 0; i < 4; i++ )
			for ( int j = 0; j < 7; j++ )
				in >> obj.player_cards[i][j];

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

	friend QDataStream &operator<<(QDataStream &out, DataPacket &obj) {


		out << obj.server_name;
		out << obj.player_count;

		for ( int i = 0; i < 4; i++ )
			out << obj.player_name[i];

		for ( int i = 0; i < 4; i++ )
			out << obj.player_bet[i];

		for ( int i = 0; i < 4; i++ )
			for ( int j = 0; j < 7; j++ )
				out << obj.player_cards[i][j];

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
	void serialize(archive &ar, const unsigned int version) {


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

		for ( int i = 0; i < 4; i++ )
			for ( int j = 0; j < 7; j++ )
				ar &player_cards[i][j];

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





};


#endif // !DATAPACKET