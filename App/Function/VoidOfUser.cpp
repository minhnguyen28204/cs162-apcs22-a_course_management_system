#ifndef VOID_OF_USER_CPP
#define VOID_OF_USER_CPP
#include "VoidOfUser.h"
#include "DoublyLinkedList.hpp"

DLLNode<Course> *View_Course_Default(User &CurUser, DLinkedList<Year> &ListYear){
    int LatestYear=ListYear.Head->data.IDyear; //= top of listyear
    int LatestSemester=(ListYear.Head->data).sem_list.Head->data.IDsemester;
    return View_Course(CurUser,LatestYear,LatestSemester,ListYear);
    //edit LastYear and LastSemester
}
DLLNode<Course> *View_Course(User& CurUser, int IDYear, int IDSem, DLinkedList<Year>& ListYear) {
    DLinkedList<Course> Data;
    //create a NewYear with type Year to compare and getbyvalue
    Year NewYear;
    NewYear.IDyear = IDYear;
    DLLNode<Year>* cur = ListYear.GetByValue(NewYear);
    if (cur == nullptr) {
        return nullptr;
    }
    DLinkedList<Semester> SemestersOfYear = (cur)->data.sem_list;
    //create a NewSem with type Semester to compare and getbyvalue
    Semester NewSem;
    NewSem.IDsemester = IDSem;
    DLLNode<Semester>* cur2 = SemestersOfYear.GetByValue(NewSem);
    if (cur2 == nullptr) {
        return nullptr;
    }
    DLinkedList<Course> CourseOfSemester = (cur2)->data.course_list;
    //Find Courses
    DLLNode<Course>* cur3 = CourseOfSemester.Head;
    Student NewStu;
    NewStu.ID = CurUser.ID;
    while (cur3) {
        if ((cur3->data).stu_list.GetByValue(NewStu)) {
            Data.push(cur3->data);
        }
        cur3 = cur3->pNext;
    }
    return Data.Head;
};


#endif // VOID_OF_USER_CPP
