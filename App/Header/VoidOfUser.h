#ifndef VOID_OF_USER_H
#define VOID_OF_USER_H
#include "User.h"
#include "Year.h"
DLinkedList<Course> View_Course_Default(Student &CurUser, DLinkedList<Year> &ListYear);
void View_Course(User& CurUser, int IDYear, int IDSem, DLinkedList<Year>& ListYear, DLinkedList<Course> &ListCourse);
//need list of users

#endif // VOID_OF_USER_H
