#ifndef SAFE_H
#define SAFE_H

#include <string>
#include <fstream>
#include "DoublyLinkedList.hpp"
#include "Class.h"
#include "Course.h"
#include "Year.h"
using namespace std;

void Save_Classes(string filename, DLinkedList <Class>& classes_list);
void Save_Courses(string filename, DLinkedList <Course>& courses_list);
void Save_Years(string filename, DLinkedList <Year>& year_list);
void Save_Semesters(string filename, DLinkedList <Semester>& semester_list);

#endif