#include "User.h"


User::User(const QString &name, const unsigned long &password_hash, int rank, int games_won, int games_loose, const QString &phone_number, const QString &address, const QString &email)
	: name(name), password_hash(password_hash), rank(rank), games_won(games_won), games_loose(games_loose), phone_number(phone_number), address(address), email(email) {}


User::User(const User &that): name(that.name), password_hash(that.password_hash), rank(that.rank), games_won(that.games_won), games_loose(that.games_loose), phone_number(that.phone_number), address(that.address), email(that.email) {}
