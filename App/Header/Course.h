#ifndef COURSE_H
#define COURSE_H

#include "ScoreBoard.h"
#include "Student.h"
using namespace std;

struct Course
{
    string ID;
    string course_name;
    string class_name;
    string teacher_name;
    int credits_num;
    int max_students;
    string day_of_week;
    string session; // S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)
    DLinkedList <Student> stu_list;
    DLinkedList <Score> score_list; // haven't has score list yet.
    bool unlocked; // has been puplished or not (so that the student can view it or not)
    void Update_Info(); // update a course info
    void Remove_A_Student();
    // in the end of semester
    // only by staff
    void Export_Students(); // Export a list of students in a course to a CSV file
    void Import_Scoreboard(); // Import from CSV file
    void view_scoreboard(); // if staff puplished, student can see it
    inline int operator == (const Course &other){
        return (course_name==other.course_name);
    }
    bool operator>(const Course& other) const
    {
        return course_name > other.course_name;
    }

};

#endif
