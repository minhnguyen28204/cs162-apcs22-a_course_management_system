#ifndef SEMESTER_H
#define SEMESTER_H

#include "Course.h"

struct Semester
{
    int IDsemester;
    string start_day;
    string end_day;
    DLinkedList <Course> course_list;
    inline int operator == (const Semester& other){
        return (IDsemester==other.IDsemester);
    }
    bool operator > (const Semester &other) const{
        return (IDsemester>other.IDsemester);
    }
    // add a course to list of course above
};

#endif
