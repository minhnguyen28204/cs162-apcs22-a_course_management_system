#ifndef EXPORT_H
#define EXPORT_H

#include <string>
#include "DoublyLinkedList.hpp"
#include "Class.h"
#include "Course.h"
#include "Year.h"
#include "Scoreboard.h"
#include <direct.h>
#include <sys/stat.h>
#include <fstream>
using namespace std;

bool Save_Data(const string& folder_path, DLinkedList <Year>& year_list);
bool Save_Years(const string& folder_path,DLinkedList <Year>& year_list);
bool Save_Semesters(const string& yf_path, DLinkedList <Semester>& semester_list);
bool Save_Classes(const string& yf_path, DLinkedList <Class>& class_list);
bool Save_Students(const string& cf_name, DLinkedList <Student>& student_list);
bool Save_Courses(const string& sf_path, DLinkedList <Course>& course_list);
bool Save_Scoreboards(const string& course_path, DLinkedList<Score>& sco_list);



#endif