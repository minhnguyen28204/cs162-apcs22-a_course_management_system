#ifndef CLASS_H
#define CLASS_H

#include "Student.h"
#include "DoublyLinkedList.hpp"

struct Class
{
    string class_name;
    // Linked list of student
    DLLNode <Student> stu_list;
    void Add_A_Student();
    void Quick_Input();
    void View_ScoreBoard_Class();
};
#endif