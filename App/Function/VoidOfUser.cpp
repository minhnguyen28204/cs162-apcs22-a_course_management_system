#ifndef VOID_OF_USER_CPP
#define VOID_OF_USER_CPP
#include "VoidOfUser.h"
#include "DoublyLinkedList.hpp"

DLinkedList<Course> View_Course_Default(User &CurUser, DLinkedList<Year> &ListYear){
        int LatestYear=3; //= top of listyear
        int LatestSemester=3;
        return View_Course(CurUser,LatestYear,LatestSemester,ListYear);
        //edit LastYear and LastSemester
}
DLinkedList<Course> View_Course(User& CurUser, int IDYear, int IDSem, DLinkedList<Year>& ListYear) {
    DLinkedList<Course> Data;
    //create a NewYear with type Year to compare and getbyvalue
    Year NewYear;
    NewYear.IDyear = IDYear;
    DLLNode<Year>* cur = ListYear.GetByValue(NewYear);
    if (cur == nullptr) {
        return Data;
    }
    DLinkedList<Semester> SemestersOfYear = (cur)->data.sem_list;
    //create a NewSem with type Semester to compare and getbyvalue
    Semester NewSem;
    NewSem.IDsemester = IDSem;
    DLLNode<Semester>* cur2 = SemestersOfYear.GetByValue(NewSem);
    if (cur2 == nullptr) {
        return Data;
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
    return Data;
};
void getUser(int &id, User &Who){
    ifstream fi("Information/Users.txt");
    while (fi >> Who.ID >> Who.FirstName >> Who.LastName >> Who.Gender >> Who.dob >> Who.Social_ID >> Who.IsStudent){
        //std::cout << Who.ID << Who.FirstName << Who.LastName << Who.Gender << Who.dob << Who.Social_ID << Who.IsStudent << '\n';
        //std::cout << Who.ID << ' ' << id << endl;
        if (Who.ID == id) {
            //cout << Who.ID << '\n';
            fi.close();
            return;
        }
    }
}

#endif // VOID_OF_USER_CPP
