#ifndef SAVE_CPP
#define SAVE_CPP

#include "Save.h"

// export to file Classes.CSV
void Save_Classes(string filename, DLinkedList <Class>& classes_list)
{
    ofstream fout(filename);
    string header = "class_name,No,ID,FirstName,LastName,Gender,dob,Social_ID\n";
    fout << header;
    DLLNode <Class> *cur_class = classes_list.Head;
    DLLNode <Student> *cur_student = (cur_class->data).stu_list.Head;
    while(cur_class)
    {
        cur_student = (cur_class->data).stu_list.Head;
        while(cur_student)
        {
            fout << cur_class->data.class_name << ',';
            fout << cur_student->data.No << ',';
            fout << cur_student->data.ID << ',';
            fout << cur_student->data.FirstName << ',';
            fout << cur_student->data.LastName << ',';
            fout << cur_student->data.Gender << ',';
            fout << cur_student->data.dob << ',';
            fout << cur_student->data.Social_ID << '\n';
            cur_student = cur_student->pNext;
        }
        cur_class = cur_class->pNext;
    }
    fout.close();
}

// export to file courses.CSV
void Save_Courses(string filename, DLinkedList <Course>& courses_list)
{
    ofstream fout(filename);
    string header = "Year,Semester,CourseID,CourseName,ClassName,TeacherName,CreditsNum,StudentsMax,DayOfWeek,Session,EnrolledStudents\n";
    DLLNode <Course> *cur_course = courses_list.Head;
    DLLNode <int> *cur_id = cur_course->data.ID_list.Head;
    while(cur_course)
    {
        cur_id = cur_course->data.ID_list.Head;
        fout << cur_course->data.year << ',';
        fout << cur_course->data.semester << ',';
        fout << cur_course->data.ID << ',';
        fout << cur_course->data.course_name << ',';
        fout << cur_course->data.class_name << ',';
        fout << cur_course->data.teacher_name << ',';
        fout << cur_course->data.credits_num << ',';
        fout << cur_course->data.max_students << ',';
        fout << cur_course->data.day_of_week << ',';
        fout << cur_course->data.session << ',';
        while(cur_id)
        {
            fout << cur_id->data << ',';
            cur_id = cur_id->pNext;
        }
        fout << endl;
        cur_course = cur_course->pNext;
    }
    fout.close();
}

// export to file Semesters.CSV
void Save_Semesters(string filename, DLinkedList <Year>& year_list)
{
    ofstream fout(filename);
    string header = "Year,Semester,StartDate,EndDate\n";
    DLLNode <Year> *cur_year = year_list.Head;
    DLLNode <Semester> *cur_semester = cur_year->data.sem_list.Head;
    while(cur_year)
    {
        cur_semester = cur_year->data.sem_list.Head;
        while(cur_semester)
        {
            fout << cur_semester->data.year << ',';
            fout << cur_semester->data.Semester << ',';
            fout << cur_semester->data.start_day << ',';
            fout << cur_semester->data.end_day << '\n';
            cur_semester = cur_semester->pNext;
        }
        cur_year = cur_year->pNext;
    }
    fout.close();    
}

// export to file Years.CSV
void Save_Years(string filename, DLinkedList <Year>& year_list)
{
    ofstream fout(filename);
    string header = "year\n";
    DLLNode <Year> *cur_year = year_list.Head;
    while(cur_year)
    {
        fout << cur_year->data.year << endl;
        cur_year = cur_year->pNext;
    }
    fout.close();
}

#endif