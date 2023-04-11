#include "DoublyLinkedList.hpp"
#include "year.h"
#include "Student.h"
#include "Class.h"
#include <string>
bool CreateNewYear(DLinkedList<Year> &ListYear, Year &NewYear);
bool AddClass(Year &CurYear, Class &CurClass);
bool AddStudent(Class &CurClass, Student &CurStudent);
bool QuickInputClass(const std::string& folderpath,Class &CurClass);

