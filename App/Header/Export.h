#ifndef EXPORT_H
#define EXPORT_H

#include <string>
#include <fstream>
#include <filesystem>
#include "DoublyLinkedList.hpp"
#include "Class.h"
#include "Course.h"
#include "Year.h"
#include "Scoreboard.h"

void Save_Data(const string& folder_path, DLinkedList <Year>& year_list);
void Save_Years(const string& folder_path,DLinkedList <Year>& year_list);
void Save_Semesters(const string& yf_path, DLinkedList <Semester>& semester_list);
void Save_Classes(const string& yf_path, DLinkedList <Class>& class_list);
void Save_Students(const string& cf_name, DLinkedList <Student>& student_list);
void Save_Courses(const string& sf_path, DLinkedList <Course>& course_list);
void Save_Scoreboards(const string& course_path, Scoreboard& sco_board);



#endif