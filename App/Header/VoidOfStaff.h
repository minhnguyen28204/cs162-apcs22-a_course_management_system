#ifndef VOIDOFSTAFF_H
#define VOIDOFSTAFF_H

#include "Semester.h"
#include "year.h"

bool Add_A_Semester(Year& ye, Semester& sem);
bool Add_A_Course(Semester& sem, Course& cou);
bool QInputStuInCourse(const string& filename,Course& cur_course);
bool UpdateStudentAccount(Student& stu, const string& folderpath);
bool ScoreCSV(const string folderpath, DLinkedList<Score>& sco_list);
bool UpdateDataStudent(Student& stu, const string& folderpath);

#endif