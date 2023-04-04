#include "VoidOfStaff.h"

void UpdateCourseID(Course& CourseList, string newID)
{
    CourseList.ID = newID;
}
void UpdateCourseName(Course& CourseList, string newName)
{
    CourseList.class_name = newName;
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
void RemoveStudent(Course& CourseList, Student deleteStudent)
{
    if (!CourseList.stu_list.GetByValue(deleteStudent)) {
        return;
    }
    DLLNode <Student>* temp = CourseList.stu_list.Head;
    while (temp->pNext)
    {
        if (temp->data.ID == deleteStudent.ID)
        {
            DLLNode <Student>* deleteStu = temp->pNext;
            temp->pNext = temp->pNext->pNext;
            delete deleteStu;
        }
    }
}
