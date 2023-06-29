#include "DataPacket.h"




QDataStream &operator>> (QDataStream &in, DataPacket &obj) {
	in >> obj.your_points;


	for ( int i = 0; i < 4; i++ )
		in >> obj.player_name[i];



	for ( int j = 0; j < 7; j++ )
		in >> obj.player_cards[j];



	return in;

}

QDataStream &operator<<(QDataStream &out, DataPacket &obj) {
	out << obj.your_points;


	for ( int i = 0; i < 4; i++ )
		out << obj.player_name[i];



	for ( int j = 0; j < 7; j++ )
		out << obj.player_cards[j];


	return out;

}


template<class archive>
void DataPacket::serialize(archive &ar, const unsigned int version) {

	ar &your_points;


	for ( int i = 0; i < 4; i++ )
		ar &player_name[i];



	for ( int j = 0; j < 7; j++ )
		ar &player_cards[j];



}

