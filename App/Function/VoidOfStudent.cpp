#include "VoidOfStudent.h"
void ViewResult(Student &CurStudent, int IDYear, int IDSem, DLinkedList<Year> &ListYear, DLinkedList<Course> &ListCourse, DLinkedList<Score> &ListScore){
   ListCourse =  View_Course_Default(CurStudent,ListYear);
   DLLNode<Course> *cur = ListCourse.Head;
   DLinkedList<Score> Data;
   while (cur){
        DLLNode<Score> *cur2 = cur->data.score_list.Head;
        bool check = false;
        while (cur2){
            if (cur2->data.stu_id==CurStudent.ID) {
                Data.push_back(cur2->data);
                check = true;
                break;
            }
        }
        if (!check){
            Score a;
            Data.push_back(a);
        }
   }
   ListScore = Data;
}
