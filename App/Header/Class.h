#ifndef CLASS_H
#define CLASS_H

#include "Student.h"
#include "DoublyLinkedList.hpp"
#include <string>
using namespace std;

struct Class
{
    string class_name;
    // Linked list of student
    DLinkedList <Student> stu_list;
    void Add_A_Student();
    void Quick_Input();
    void View_ScoreBoard_Class();
    bool operator > (const Class &other) const{
        return (class_name>other.class_name);
    }
};


#endif
