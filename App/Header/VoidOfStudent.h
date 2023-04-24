#ifndef VOID_OF_STUDENT_H
#define VOID_oF_STUDENT_H
#include "DoublyLinkedList.hpp"
#include "Student.h"
#include "Course.h"
#include "Scoreboard.h"
#include "year.h"
#include "VoidOfUser.h"
#include "User.h"
void ViewResult(Student &CurStudent, int IDYear, int IDSem, DLinkedList<Year> &ListYear, DLLNode<Course>* &ListCourse, DLLNode<Score>* &ListScore, int &Number_Of_Credits, double &TotalScore);
bool FindStudent(Student *&CurStudent, string StuID, DLinkedList<Year> &ListYear);
void UpdateStudentResult(Student *&CurStudent, Course &CurCou, Score &CurScore, int del, bool isPublic);
void Update(Course &CurCou, DLLNode<Score> *OldScore, DLLNode<Score> *NewScore, DLinkedList<Year> &ListYear, bool isPublic);
#endif // VOID_OF_STUDENT_H
