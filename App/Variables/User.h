#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

struct Date
{
    int year;
    int day;
    int month;
};

struct User
{
    int ID;
	string FirstName;
	string LastName;
	int Gender;
	Date dob;
	long long Social_ID;
    void View_Profile();
};

#endif