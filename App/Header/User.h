#ifndef USER_H
#define USER_H

#include <string>
#include "DoublyLinkedList.hpp"
using namespace std;

struct User
{
    string ID;
	string FirstName;
	string LastName;
	int Gender;
	string dob;
	string Social_ID;
    bool IsStudent;
	inline int operator == (const User& other) {
		return (ID == other.ID);
	}
	inline int operator > (const User& other) {
		return (ID > other.ID);
	}
};
#endif
