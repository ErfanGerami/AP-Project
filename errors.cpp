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
			//case 3:


		default: return "error";

	}
}
int Errors::file_openning_error = 0;
int Errors::player_not_found = 1;
int Errors::incorrect_password = 2;