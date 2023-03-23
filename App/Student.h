#pragma once
#include "bits/stdc++.h"
using namespace std;

struct Student{
    int ID;
    string LastName;
    int Gender;
    string DoB;
    string Social_ID;
    string Password;
    Student(){}
    Student(int _ID, string _LastName, int _Gender, string _DoB, string _SID, string pass){
        ID = _ID;
        LastName = _LastName;
        Gender = _Gender;
        DoB = _DoB;
        Social_ID = _SID;
        Password = pass;
    }
};
