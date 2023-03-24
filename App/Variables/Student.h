#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"

struct Student : User
{
	int No;
	void View_Stu_Courses();
	void View_Stu_Grade();
};

#endif