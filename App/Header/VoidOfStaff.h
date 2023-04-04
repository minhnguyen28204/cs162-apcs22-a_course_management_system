#include "Course.h"
#include "Student.h"
#include "DoublyLinkedList.hpp"
void UpdateCourseID(Course& CourseList, string newID);
void UpdateCourseName(Course& CourseList, string newName);
void UpdateCourseTeacher(Course& CourseList, string newTeacher);
void UpdateCourseCredits_Num(Course& CourseList, int newCredits_Num);
void UpdateCourseMax_Students(Course& CourseList, int newMax_Students);
void UpdateDay_Of_Week(Course& CourseList, string newDay_Of_Week);
void UpdateSession(Course& CourseList, string newSession);
void AddStudent(Course& CourseList, Student newStudent);
void RemoveStudent(Course& CourseList, Student deleteStudent);
void DeleteCourse(DLinkedList <Course>& CourseList, Course DeleteCourse);