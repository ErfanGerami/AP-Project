#include "filehandeling.h"


FILE *FileHandeling::players = fopen("players.bin", "rb+");//open file for read and write without deleting it's content



/*
int FileHandeling::key(int index) {
	//key:x^2+2x+2
	return (index * index + 2 * index + 2) % 26;
}

bool FileHandeling::IsAPlayer(QString path) {
	std::ifstream file(path.toStdString(), std::ios::in);
	bool is_there = file.is_open();
	if ( is_there )
		file.close();
	return is_there;

}

QString FileHandeling::Encrypt(QString str) {
	std::string str_temp = str.toStdString();
	std::string encrypted_string = "";
	for ( int i = 0; i < str.length(); i++ ) {
		if ( str_temp[i] != '/' ) {
			if ( str_temp[i] >= 'a' )
				encrypted_string += (str_temp[i] - 'a' + FileHandeling::key(i)) % 26 + 'a';
			else
				encrypted_string += (str_temp[i] - 'A' + FileHandeling::key(i)) % 26 + 'A';
		}
		else {
			encrypted_string += '/';
		}
	}
	return QString(encrypted_string.c_str());
}

QString FileHandeling::Decrypt(QString str) {
	std::string str_temp = str.toStdString();
	std::string decrypted_string = "";
	char temp;
	for ( int i = 0; i < str.length(); i++ ) {
		if ( str_temp[i] != '/' ) {
			if ( str_temp[i] >= 'a' ) {
				temp = (str_temp[i] - 'a' - FileHandeling::key(i));
				if ( temp < 0 )
					temp += 26;

				decrypted_string += temp + 'a';
			}
			else {
				temp = (str_temp[i] - 'A' - FileHandeling::key(i));
				if ( temp < 0 )
					temp += 26;

				decrypted_string += temp + 'A';
			}
		}
		else {
			decrypted_string += '/';
		}
	}
	return QString(decrypted_string.c_str());

}

std::vector<QString> FileHandeling::read(QString path) {

	std::ifstream file(path.toStdString());
	if ( !file.is_open() )throw Errors(Errors::file_openning_error);
	char c = ' ';
	QString string = "";
	std::vector<QString> result;
	while ( true ) {
		while ( true ) {
			file >> c;
			if ( c == '/' )
				break;
			if ( file.eof() ) {
				file.close();
				return result;
			}
			string += c;

		}

		result.push_back(Decrypt(string));
		string = "";
		c = ' ';


	}
	file.close();
	return result;




}

void FileHandeling::write(QString path, QString content) {
	std::ofstream file(path.toStdString());
	if ( !file.is_open() )throw Errors(Errors::file_openning_error);
	file << content.toStdString();
	file.close();

}
*/

bool FileHandeling::is_user_unique(QString username) {
	players = fopen("players.bin", "rb+");
	fseek(players, 0, SEEK_SET);
	Player *temp = new Player();
	while ( fgetc(players) != EOF ) {
		fseek(players, -1, SEEK_CUR);
		fread(temp, sizeof(Player), 1, players);
		if ( temp->get_username() == username.toStdString() ) {
			return false;
		}
	}

	return true;

}


bool FileHandeling::is_players_file_open() {
	return players != NULL;
}


void FileHandeling::file_write(Player *new_player) {

	fseek(players, 0, SEEK_END);

	fwrite(new_player, sizeof(Player), 1, players);

}

//
Player *FileHandeling::file_read(QString username, QString password) {
	fclose(players);
	players = fopen("players.bin", "ab+");
	fseek(players, 0, SEEK_SET);

	Player *temp_player = new Player();
	bool not_found = true;

	while ( fgetc(players) != EOF ) {//try to find a player with the given username
		fseek(players, -1, SEEK_CUR);
		fread(temp_player, sizeof(Player), 1, players);
		if ( temp_player->get_username() == username.toStdString() ) {
			not_found = false;
			break;
		}
	}

	fclose(players);
	players = fopen("players.bin", "rb+");

	if ( not_found ) throw Errors(Errors::player_not_found);
	if ( !temp_player->is_password_correct(password.toStdString()) ) throw Errors(Errors::incorrect_password);

	return new Player(*temp_player);


}


