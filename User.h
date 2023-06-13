#ifndef USER
#define USER

#include<iostream>
#include<QString>

class User {
protected:
	QString name;
	QString password;
	int rank;
	int games_won;
	int games_loose;
	QString phone_number;
	QString address;
	QString email;

public:

	User() = default;

	User(const QString &name, const QString &password, int rank, int games_won, int games_loose, const QString &phone_number, const QString &address, const QString &email);

	User(const User &that);


};


#endif // !USER