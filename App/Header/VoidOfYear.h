#include "DoublyLinkedList.hpp"
#include "year.h"
#include "Student.h"
#include "Class.h"
#include <string>
bool CreateNewYear(DLinkedList<Year> &ListYear, Year &NewYear);
bool AddClass(Year &CurYear, Class &CurClass);
bool AddStudent(Class &CurClass, Student &CurStudent);
bool UpdateStudentAccount(Student& stu, const string& folderpath);
bool QuickInputClass(const string& filename,Class &CurClass, const string& folderpath);

