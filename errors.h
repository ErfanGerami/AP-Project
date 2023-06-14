#ifndef ERRORS_H
#define ERRORS_H
#include <QString>

class Errors {
public:
	Errors() = default;
	Errors(int stat);
	int GetError();
	QString what();
	static int file_openning_error;
	static int player_not_found;
	static int incorrect_password;
	static int no_user_found_via_user_and_phone;
	static int inputed_passwords_dont_match;

private:
	int stat;

};
#endif // ERRORS_H
