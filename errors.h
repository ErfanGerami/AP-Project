#ifndef ERRORS_H
#define ERRORS_H
#include <QString>

class Errors {
public:
	Errors() = default;
	Errors(int stat);
	int GetError();
	QString what();

	const static int file_openning_error;
	const static int player_not_found;
	const static int incorrect_password;
	const static int no_user_found_via_user_and_phone;
	const static int inputed_passwords_dont_match;
	const static int not_agreed_with_terms;
	const static int username_not_unique;
	const static int invalid_email;
	const static int invalid_input;
	const static int connection_lost;
	const static int cant_connect;
	const static int cant_communicate;
	const static int server_initiation_failed;
	const static int server_not_found;
	const static int invalid_server_number;
private:
	int stat;

};
#endif // ERRORS_H
