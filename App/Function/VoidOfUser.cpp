#ifndef VOID_OF_USER_CPP
#define VOID_OF_USER_CPP
#include "VoidOfUser.h"
#include "DoublyLinkedList.hpp"

DLinkedList<Course> View_Course_Default(Student &CurUser, DLinkedList<Year> &ListYear){
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

void View_Course(User& CurUser, int IDYear, int IDSem, DLinkedList<Year>& ListYear, DLinkedList<Course> &ListCourse) {
    //create a NewYear with type Year to compare and getbyvalue
    Year NewYear;
    NewYear.IDyear = IDYear;
    DLLNode<Year>* cur = ListYear.GetByValue(NewYear);
    if (cur == nullptr) {
        return;
    }
    DLinkedList<Semester> SemestersOfYear = (cur)->data.sem_list;
    //create a NewSem with type Semester to compare and getbyvalue
    Semester NewSem;
    NewSem.IDsemester = IDSem;
    DLLNode<Semester>* cur2 = SemestersOfYear.GetByValue(NewSem);
    if (cur2 == nullptr) {
        return ;
    }
    DLinkedList<Course> CourseOfSemester = (cur2)->data.course_list;
    //Find Courses
    DLLNode<Course>* cur3 = CourseOfSemester.Head;
    Student NewStu;
    NewStu.ID = CurUser.ID;
    while (cur3) {
        if ((cur3->data).stu_list.GetByValue(NewStu)) {
            ListCourse.push(cur3->data);
        }
        cur3 = cur3->pNext;
    }
};

#endif // VOID_OF_USER_CPP
