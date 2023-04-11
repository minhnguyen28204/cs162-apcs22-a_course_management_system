#pragma once
#include "Course.h"
#include "Student.h"
#include "DoublyLinkedList.hpp"
#include <string>
using namespace std;
void UpdateCourseID(Course& CourseList, string newID);
void UpdateCourseName(Course& CourseList, string newCourseName);
void UpdateClassName(Course& CourseList, string newClassName);
void UpdateCourseTeacher(Course& CourseList, string newTeacher);
void UpdateCourseCredits_Num(Course& CourseList, int newCredits_Num);
void UpdateCourseMax_Students(Course& CourseList, int newMax_Students);
void UpdateDay_Of_Week(Course& CourseList, string newDay_Of_Week);
void UpdateSession(Course& CourseList, string newSession);
void updateStudentAccount(Student& stu, string& folderpath);
void AddStudent(Course& CourseList, Student newStudent, string& folderpath);
void RemoveStudent(DLinkedList <Student>& StudentList, Student DeleteStudent);
void DeleteCourse(DLinkedList <Course>& CourseList, Course DeleteCourse);