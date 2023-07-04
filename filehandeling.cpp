#include "filehandeling.h"


FILE *FileHandeling::players = fopen("players.bin", "rb+");//open file for read and write without deleting it's content



bool FileHandeling::is_user_unique(QString username) {

	fseek(players, 0, SEEK_SET);
	Player *temp = new Player();
	while ( fgetc(players) != EOF ) {
		fseek(players, -1, SEEK_CUR);
		fread(temp, sizeof(Player), 1, players);
		if ( temp->GetUserName() == username.toStdString() )
			return false;

	}

	return true;

}


bool FileHandeling::is_players_file_open() {
	return players != NULL;
}

void FileHandeling::check_player_validity_forgotpass(QString username, QString phone_number) {

	fseek(players, 0, SEEK_SET);

	Player *temp = new Player();

	while ( fgetc(players) != EOF ) {
		fseek(players, -1, SEEK_CUR);
		fread(temp, sizeof(Player), 1, players);
		if ( temp->GetUserName() == username.toStdString() && temp->GetUserName() == phone_number.toStdString() )
			return;

	}

	throw Errors(Errors::no_user_found_via_user_and_phone);
}

void FileHandeling::change_password(QString username, QString password) {

	fseek(players, 0, SEEK_SET);

	Player *temp_player = new Player();


	while ( fgetc(players) != EOF ) {//try to find a player with the given username
		fseek(players, -1, SEEK_CUR);
		fread(temp_player, sizeof(Player), 1, players);
		if ( temp_player->GetUserName() == username.toStdString() )
			break;
	}

	temp_player->change_password(password.toStdString());

	fseek(players, -long long(sizeof(Player)), SEEK_CUR);

	fwrite(temp_player, sizeof(Player), 1, players);




}
void FileHandeling::ChangePlayerEntirely(QString old_username, Player *new_player) {

	fseek(players, 0, SEEK_SET);

	Player *temp_player = new Player();


	while ( fgetc(players) != EOF ) {//try to find a player with the given username
		fseek(players, -1, SEEK_CUR);
		fread(temp_player, sizeof(Player), 1, players);
		if ( temp_player->GetUserName() == old_username.toStdString() )
			break;
	}


	fseek(players, -long long(sizeof(Player)), SEEK_CUR);

	fwrite(new_player, sizeof(Player), 1, players);




}



void FileHandeling::file_write(Player *new_player) {

	fseek(players, 0, SEEK_END);

	fwrite(new_player, sizeof(Player), 1, players);

}

//
Player *FileHandeling::file_read(QString username, QString password) {

	fseek(players, 0, SEEK_SET);

	Player *temp_player = new Player();
	bool not_found = true;

	while ( fgetc(players) != EOF ) {//try to find a player with the given username
		fseek(players, -1, SEEK_CUR);
		fread(temp_player, sizeof(Player), 1, players);
		if ( temp_player->GetUserName() == username.toStdString() ) {
			not_found = false;
			break;
		}
	}



	if ( not_found ) throw Errors(Errors::player_not_found);
	if ( !temp_player->is_password_correct(password.toStdString()) ) throw Errors(Errors::incorrect_password);

	return new Player(*temp_player);


}


