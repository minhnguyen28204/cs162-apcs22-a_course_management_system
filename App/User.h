#ifndef USER_H
#define USER_H

#include <string>
#include "DoublyLinkedList.hpp"
#include "Course.h"
using namespace std;

struct User
{
    int ID;
	string FirstName;
	string LastName;
	int Gender;
	string dob;
	long long Social_ID;
	inline int operator == (const User &other){
        return (ID == other.ID);
	}
};
#endif
