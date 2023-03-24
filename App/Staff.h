#ifndef STAFF_H
#define STAFF_H

#include "User.h"

struct Staff : User
{

    void View_ListClasses();
    void View_ListCourses();
    void View_StuS_In_AClass();
    void View_StuS_In_ACourse();
};

#endif