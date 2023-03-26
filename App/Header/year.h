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
    inline int operator == (const Year& other){
        return (IDyear==other.IDyear);
    }
};


#endif
