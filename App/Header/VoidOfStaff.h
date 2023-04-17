#ifndef VOIDOFSTAFF_H
#define VOIDOFSTAFF_H

#include "Semester.h"
#include "year.h"

bool Add_A_Semester(Year& ye, Semester& sem);
bool Add_A_Course(Semester& sem, Course& cou);
bool QInputStuInCourse(const string& filename,Course& cur_course);
bool ExportToCSV(Course& cou, const string& filename);
bool ImpScoreCSV(const string folderpath, DLinkedList<Year> &ListYear, int IDYear, Course &CurCou, DLLNode<Score> *OldScore, DLinkedList<Score>& new_scorelist);

#endif
