#ifndef YEAR_H
#define YEAR_H

#include "DoublyLinkedList.hpp"
#include "Class.h"
#include "Semester.h"
#include "fstream"
#include "sstream"

struct Year
{
    int IDyear;
    DLinkedList <Semester> sem_list; // haven't created linked list for classes yet
    void Create_A_Class(DLinkedList <Class>& classes_list);
    void Create_A_Semester();
    inline int operator == (const Year& other){
        return (IDyear==other.IDyear);
    }
};

struct Year_Storage
{
    DLinkedList <Year> year_list;
    void Create_A_Year();
};


#endif
