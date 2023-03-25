#ifndef USER_CPP
#define USER_CPP
#include "User.h"
#include "Course.h"
#include "Year.h"
#include "DoublyLinkedList.hpp"

DLinkedList<Course> User::View_Course_Default(){
        int a=3;
        int b=3;
        return View_Course(a,b);
        //edit LastYear and Last Semester
}
DLinkedList<Course> User::View_Course(int &IDYear, int &IDSem){
        DLinkedList<Course> Data;
        //create a NewYear with type Year to compare and getbyvalue
        Year NewYear;
        NewYear.IDyear = IDYear;
        DLinkedList<Year> ListYear;
        //
        ListYear.push_front(NewYear);
        // define ListYear
        DLLNode<Year> *cur = ListYear.GetByValue(NewYear);
        if (cur==nullptr){
            return Data;
        }
        DLinkedList<Semester> SemestersOfYear =  (cur)->data.sem_list;
        //create a NewSem with type Semester to compare and getbyvalue
        Semester NewSem;
        NewSem.IDsemester = IDSem;
        DLLNode<Semester> *cur2 = SemestersOfYear.GetByValue(NewSem);
        if (cur2==nullptr){
            return Data;
        }
        DLinkedList<Course> CourseOfSemester = (cur2)->data.course_list;
        //Find Courses
        DLLNode<Course> *cur3 = CourseOfSemester.Head;
        while (cur3){
            if ((cur3->data).ID_list.GetByValue(ID)){
                Data.push_front(cur3->data);
            }
            cur3=cur3->pNext;
        }
        return Data;
};

#endif // USER_CPP

