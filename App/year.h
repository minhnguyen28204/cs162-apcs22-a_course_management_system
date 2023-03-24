#ifndef YEAR_H
#define YEAR_H

#include "DoublyLinkedList.hpp"
#include "Class.h"
#include "Semester.h"

struct Year
{
    int year;
    DLinkedList <Class> class_list; // haven't created linked list for classes yet
    DLinkedList <Semester> sem_list; // haven't created linked list for classes yet
    void Create_A_Class(); // class linked list
    void Create_A_Semester();
};

struct Year_Storage
{
    DLinkedList <Year> year_list;
    void Create_A_Year(); 
};


#endif