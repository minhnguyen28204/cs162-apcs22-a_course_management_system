#ifndef VOIDOFSTAFF_H
#define VOIDOFSTAFF_H

#include "Semester.h"
#include "year.h"

bool Add_A_Semester(Year& ye, Semester& sem);
bool Add_A_Course(Semester& sem, Course& cou);
bool QInputStuInCourse(const string& filename,Course& cur_course);
bool ExportToCSV(Course& cou, const string& filename);
bool ImpScoreCSV(const string filepath, DLinkedList<Score>& sco_list);
bool UpdateScoreFinal(DLLNode <Score>& newSco, string x);
bool UpdateScoreMidterm(DLLNode <Score>& newSco, string x);
bool UpdateScoreTotal(DLLNode <Score>& newSco, string x);
bool UpdateScoreOther(DLLNode <Score>& newSco, string x);

#endif
