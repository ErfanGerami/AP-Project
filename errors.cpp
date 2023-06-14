#include "errors.h"



Errors::Errors(int stat) {
	this->stat = stat;
}


int Errors::GetError() { return stat; }


QString Errors::what() {
	switch ( stat ) {
		case 0: return "file didn't open correctly";
		case 1:	return "the credentials you are using are invalid";
		case 2:	return "the credentials you are using are invalid";
		case 3: return "player wasn't found";
		case 4: return "inputed passwords dont match";
		case 5: return "You should agree to the terms first";
		case 6: return "A player with that username already exists";
		case 7: return "email address is not valid";


		default: return "error";

	}
}
int Errors::file_openning_error = 0;
int Errors::player_not_found = 1;
int Errors::incorrect_password = 2;
int Errors::no_user_found_via_user_and_phone = 3;
int Errors::inputed_passwords_dont_match = 4;
int Errors::not_agreed_with_terms = 5;
int Errors::username_not_unique = 6;
int Errors::invalid_email = 7;