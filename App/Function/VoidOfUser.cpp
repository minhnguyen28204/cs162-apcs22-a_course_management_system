#ifndef VOID_OF_USER_CPP
#define VOID_OF_USER_CPP
#include "VoidOfUser.h"
#include "DoublyLinkedList.hpp"

DLinkedList<Course> View_Course_Default(User &CurUser, DLinkedList<Year> &ListYear){
    DLLNode<Course> *Cur = ListYear.Head->data.sem_list.Head->data.course_list.Head;
    DLinkedList<Course> CourseList;
    while (Cur){
        DLLNode<Student> *cur = Cur->data.stu_list.Head;
        bool ok = false;
        while (cur){
            if (cur->data.ID == CurUser.ID){
                ok = true;
                break;
            }
            cur = cur->pNext;
        }
        if (ok) CourseList.push(Cur->data);
        Cur = Cur->pNext;
    }
    return CourseList;
}

#endif // VOID_OF_USER_CPP
