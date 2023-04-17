#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <iostream>
using namespace std;

struct Student : User
{
	int Number_Of_Credits;
	double TotalScore;
	bool operator > (const Student &other) const{
        return (ID>other.ID);
    }
};

#endif
