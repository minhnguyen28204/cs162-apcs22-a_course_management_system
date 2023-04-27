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
    inline int operator == (const Course &other){
        return (ID == other.ID && class_name == other.class_name);
    }
    bool operator > (const Course& other) const
    {
        return course_name > other.course_name;
    }

};

#endif
