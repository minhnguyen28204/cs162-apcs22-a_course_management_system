#include "DoublyLinkedList.hpp"
#include "year.h"
#include "Student.h"
#include "Class.h"
#include <string>
#include "Checker.h"
bool CreateNewYear(DLinkedList<Year> &ListYear, Year &NewYear);
bool AddClass(Year &CurYear, Class &CurClass);
bool AddStudent(Class &CurClass, Student &CurStudent);
bool QuickInputClass(const string& filename,Class &CurClass);
