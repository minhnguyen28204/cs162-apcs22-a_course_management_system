#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <iostream>
using namespace std;

struct Student : User
{
	int No;
	void View_Stu_Courses();
	void View_Stu_Grade();
};

#endif
