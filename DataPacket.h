#ifndef DATAPACKET
#define DATAPACKET

#include <QString>
#include <QDataStream>
#include <QByteArray>


class DataPacket {
private:
public:
	int your_points = 0;
	QString player_name[4];
	int card_size;
	int player_cards[2][14];





	DataPacket() = default;


	/*DataPacket(QString server_name, int player_count, QString plauer_name[4], int player_bet[4], int player_cards[4][7], int player_won_round[4] = { 0 }, int player_Lost_round[4] = { 0 }, int player_used_timeout[4] = { 0 }, bool player_dropped[4] = { false }, bool player_abandoned[4] = { false }, bool player_is_swapping_card[4] = { false }, int rounds_passed = 0, int current_round = 0, bool is_game_in_timeout = false);*/



	friend QDataStream &operator>>(QDataStream &in, DataPacket &obj);

	friend QDataStream &operator<<(QDataStream &out, DataPacket &obj);

	template<class archive>
	void serialize(archive &ar, const unsigned int version);

};


#endif // !DATAPACKET