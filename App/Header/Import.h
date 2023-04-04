#ifndef IMPORT_H
#define IMPORT_H
#include "DoublyLinkedList.hpp"
#include <string>
#include <fstream>
#include "year.h"
#include "Semester.h"
#include "Course.h"
#include "Class.h"
using namespace std;


//import year
bool importData(const string& folderpath,DLinkedList<Year> &year_list );
bool importListyear(const string& folderpath, DLinkedList <Year> &year_list);
bool importListsemester(const string& folderpath, DLinkedList <Semester>&semester_list);
bool importListclass(const string& folderpath, DLinkedList <Class> &class_list);
bool importListcourse(const string& folderpath,DLinkedList <Course> &course_list);
bool importListstudent(const string& folderpath,DLinkedList <Student> &student_list);
bool importScoreboard(const string folderpath, Scoreboard &sco);
#endif