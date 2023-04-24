#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <iostream>
using namespace std;

struct Student : User
{
    int Number_Of_Credits;
    double TotalScore;
    int Official_Number_Of_Credits;
    double Official_TotalScore;
    Student(){
        Number_Of_Credits = 0;
        TotalScore = 0;
        Official_Number_Of_Credits = 0;
        Official_TotalScore = 0;
    }
	bool operator > (const Student &other) const{
        return (ID>other.ID);
    }
};

#endif
