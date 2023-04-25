#ifndef VOIDOFSTAFF_H
#define VOIDOFSTAFF_H

#include "Semester.h"
#include "year.h"
#include "Checker.h"
#include "VoidOfStudent.h"

bool Add_A_Semester(Year& ye, Semester& sem);
void AutoAddClasses(DLinkedList<Year>& listyear, int latestyear);
bool Add_A_Course(Semester& sem, Course& cou);
bool QInputStuInCourse(const string& filename,Course& cur_course);
bool UpdateStudentAccount(Student& stu, const string& folderpath);
bool UpdateDataStudent(Student& stu, const string& folderpath);
void UpdateCourseID(Course& CourseList, string newID);
void UpdateCourseName(Course& CourseList, string newCourseName);
void UpdateClassName(Course& CourseList, string newClassName);
void UpdateCourseTeacher(Course& CourseList, string newTeacher);
void UpdateCourseCredits_Num(Course& CourseList, int newCredits_Num);
void UpdateCourseMax_Students(Course& CourseList, int newMax_Students);
void UpdateDay_Of_Week(Course& CourseList, string newDay_Of_Week);
void UpdateSession(Course& CourseList, string newSession);
bool AddStudentToCourse(Course& CourseList, Student newStudent, bool& isinclass);
void RemoveStudent(DLinkedList <Student>& StudentList, Student DeleteStudent);
void DeleteCourse(DLinkedList <Course>& CourseList, Course DeleteCourse);
bool ExportToCSV(Course& cou, const string& filename);
bool ImpScoreCSV(const string folderpath, DLinkedList<Year> &ListYear, int IDYear, Course &CurCou, DLLNode<Score> *OldScore, DLinkedList<Score>& new_scorelist);
bool UpdateScoreFinal(DLLNode <Score> *newSco, string x);
bool UpdateScoreMidterm(DLLNode <Score> *newSco, string x);
bool UpdateScoreTotal(DLLNode <Score> *newSco, string x);
bool UpdateScoreOther(DLLNode <Score> *newSco, string x);
void CreateDefaultScore(Course& cur_cou, Student& cur_stu);
void PublicScoreboard(Course &CurCou, DLinkedList<Year> &ListYear);

#endif
