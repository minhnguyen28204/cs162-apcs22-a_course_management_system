#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <iostream>
using namespace std;

struct Student : User
{
	void View_Stu_Courses();
	void View_Stu_Grade();
	bool operator > (const Student &other) const{
        return (ID>other.ID);
    }
};

#endif
