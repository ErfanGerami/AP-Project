#include "errors.h"


const int Errors::file_openning_error = 0;
const int Errors::player_not_found = 1;
const int Errors::incorrect_password = 2;
const int Errors::no_user_found_via_user_and_phone = 3;
const int Errors::inputed_passwords_dont_match = 4;
const int Errors::not_agreed_with_terms = 5;
const int Errors::username_not_unique = 6;
const int Errors::invalid_email = 7;
const int Errors::invalid_input=8;


Errors::Errors(int stat) {
	this->stat = stat;
}


int Errors::GetError() { return stat; }


QString Errors::what() {
	switch ( stat ) {
        case file_openning_error: return "file didn't open correctly";
        case player_not_found:	return "the credentials you are using are invalid";
        case incorrect_password:	return "the credentials you are using are invalid";
        case no_user_found_via_user_and_phone: return "player wasn't found";
        case inputed_passwords_dont_match: return "inputed passwords dont match";
        case not_agreed_with_terms: return "You should agree to the terms first";
        case username_not_unique: return "A player with that username already exists";
        case invalid_email: return "email address is not valid";
        case invalid_input:return "invalid input has been given";

		default: return "error";

	}
}
