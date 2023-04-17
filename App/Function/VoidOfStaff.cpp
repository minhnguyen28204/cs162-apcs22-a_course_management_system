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
void AddStudent(Course& CourseList, Student newStudent, string& folderpath)
{
    if (CourseList.stu_list.GetByValue(newStudent)) return;
    CourseList.stu_list.push(newStudent);
    updateStudentAccount(newStudent, folderpath);
    return;
}
void updateStudentAccount(Student& stu, string& folderpath)
{
    ofstream fout(folderpath + "/" + to_string(stu.ID) + ".dat");
    if (!fout.is_open()) return;
    int len = stu.dob.length();
    string pass(len, ' '); // Initialize the pass string with the same length as dob
    int count = 0;
    for (int i = 0; i < len; ++i)
    {
        if (stu.dob[i] != '/')
        {
            pass[count] = stu.dob[i];
            count++;
        }
    }
    fout << pass;
    fout.close();
}
void RemoveStudent(DLinkedList <Student>& StudentList, Student DeleteStudent)
{
    StudentList.remove(DeleteStudent);
}
void DeleteCourse(DLinkedList <Course>& CourseList, Course DeleteCourse)
{
    CourseList.remove(DeleteCourse);
}