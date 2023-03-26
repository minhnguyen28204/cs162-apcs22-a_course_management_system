#ifndef VOID_OF_USER_H
#define VOID_OF_USER_H
#include "User.h"
#include "Year.h"
DLinkedList<Course> View_Course_Default(User &CurUser, DLinkedList<Year> &ListYear);
DLinkedList<Course> View_Course(User &CurUser, int IDYear, int IDSem, DLinkedList<Year> &ListYear);
void getUser(int &id, User &Who, DLinkedList<User>& ListUser);
//need list of users

#endif // VOID_OF_USER_H
