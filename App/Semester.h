#ifndef SEMESTER_H
#define SEMESTER_H

#include "Student.h"
#include "Course.h"

struct Semester
{
    int Semester;
    Date start_day;
    Date end_day;
    int year; // The school year it belongs to.
    DLinkedList <Course> course_list;
    // add a course to list of course above
    void Add_A_Course();
    void Delete_A_Course();
};

#endif