#ifndef FILEHANDELING_H
#define FILEHANDELING_H

#include <fstream>
#include <QString>
#include "errors.h"
#include <vector>
#include "player.h"
class FileHandeling {
public:
	FileHandeling() = default;

	static Player *file_read(QString username, QString password);

	static void file_write(Player *player);

	static bool is_user_unique(QString username);

	static bool is_players_file_open();

	static void check_player_validity_forgotpass(QString username, QString phone_number);

	static void change_password(QString username, QString password);
    static void ChangePlayerEntirely(QString old_username, Player* new_player);
	//static std::vector<QString> read(QString path);
	//static void write(QString path, QString content);
	//static QString Encrypt(QString string);
	//static QString Decrypt(QString string);
	//static bool IsAPlayer(QString path);
	//static int key(int index);

private:
	static FILE *players;
};

#endif // FILEHANDELING_H
