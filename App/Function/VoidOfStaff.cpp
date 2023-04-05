#include "VoidOfStaff.h"

void UpdateCourseID(Course& CourseList, string newID)
{
    CourseList.ID = newID;
}
void UpdateCourseName(Course& CourseList, string newCourseName)
{
    CourseList.course_name = newCourseName;
}
void UpdateClassName(Course& CourseList, string newClassName)
{
    CourseList.class_name = newClassName;
}
void UpdateCourseTeacher(Course& CourseList, string newTeacher)
{
    CourseList.teacher_name = newTeacher;
}
void UpdateCourseCredits_Num(Course& CourseList, int newCredits_Num)
{
    CourseList.credits_num = newCredits_Num;
}
void UpdateCourseMax_Students(Course& CourseList, int newMax_Students)
{
    CourseList.max_students = newMax_Students;
}
void UpdateDay_Of_Week(Course& CourseList, string newDay_Of_Week)
{
    CourseList.day_of_week = newDay_Of_Week;
}
void UpdateSession(Course& CourseList, string newSession)
{
    CourseList.session = newSession;
}
void AddStudent(Course& CourseList, Student newStudent)
{
    if (CourseList.stu_list.GetByValue(newStudent)) return;
    CourseList.stu_list.push(newStudent);
}
void RemoveStudent(DLinkedList <Student>& StudentList, Student DeleteStudent)
{
    StudentList.remove(DeleteStudent);
}
void DeleteCourse(DLinkedList <Course>& CourseList, Course DeleteCourse)
{
    CourseList.remove(DeleteCourse);
}