#ifndef IMPORT_H
#define IMPORT_H
#include "DoublyLinkedList.hpp"
#include <string>
#include <fstream>
#include "year.h"
#include <Semester.h>
#include <Course.h>
#include <Class.h>
using namespace std;


//import year
void importYear(string filename, DLinkedList <Year> &year_list);
void importSemester(string filename, DLinkedList <Semester> &semester_list);
void importCourse(String filename, DLinkedList <Semester> &courses_list);
void importClass(string filename, DLinkedList <Class> &classes_list);

#endif