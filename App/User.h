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
    DLinkedList<Course> View_Course_Default();
    DLinkedList<Course> View_Course(int &IDYear, int &IDSem);
};
void getUser(int &id, User &Who);
//need list of users
#endif
