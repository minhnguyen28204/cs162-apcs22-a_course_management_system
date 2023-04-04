#include "VoidOfYear.h"
void CreateNewYear(DLinkedList<Year> &ListYear, Year &NewYear){
    ListYear.push(NewYear);
}
void AddClass(Year &CurYear, Class &CurClass){
    CurYear.classes_list.push(CurClass);
}
void AddStudent(Class &CurClass, Student &CurStudent){
    CurClass.stu_list.push(CurStudent);
}
