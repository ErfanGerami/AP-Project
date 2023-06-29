#include "DataPacket.h"




QDataStream &operator>> (QDataStream &in, DataPacket &obj) {
	in >> obj.your_points;


	for ( int i = 0; i < 4; i++ )
		in >> obj.player_name[i];

	in >> obj.card_size;

	for ( int i = 0; i < 2; i++ )
		for ( int j = 0; j < 14; j++ )
			in >> obj.player_cards[i][j];



	return in;

}

QDataStream &operator<<(QDataStream &out, DataPacket &obj) {
	out << obj.your_points;


	for ( int i = 0; i < 4; i++ )
		out << obj.player_name[i];

	out << obj.card_size;

	for ( int i = 0; i < 2; i++ )
		for ( int j = 0; j < 14; j++ )
			out << obj.player_cards[i][j];


	return out;

}


template<class archive>
void DataPacket::serialize(archive &ar, const unsigned int version) {

	ar &your_points;


	for ( int i = 0; i < 4; i++ )
		ar &player_name[i];

	ar &card_size;

	for ( int i = 0; i < 2; i++ )
		for ( int j = 0; j < 14; j++ )
			ar &player_cards[i][j];


}

