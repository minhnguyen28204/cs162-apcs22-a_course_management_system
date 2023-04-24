#ifndef VOIDOFSTAFF_H
#define VOIDOFSTAFF_H

#include "Semester.h"
#include "year.h"
#include "Checker.h"

bool Add_A_Semester(Year& ye, Semester& sem);
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
bool AddStudentToCourse(Course& CourseList, Student newStudent);
void RemoveStudent(DLinkedList <Student>& StudentList, Student DeleteStudent);
void DeleteCourse(DLinkedList <Course>& CourseList, Course DeleteCourse);
bool ExportToCSV(Course& cou, const string& filename);
bool ImpScoreCSV(const string filepath, DLinkedList<Score>& sco_list);

#endif
