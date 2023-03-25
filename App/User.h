#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

struct User
{
    int ID;
	string FirstName;
	string LastName;
	int Gender;
	string dob;
	long long Social_ID;
    void View_Profile();
};

#endif