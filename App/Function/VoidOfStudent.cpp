#include "VoidOfStudent.h"
void ViewResult(Student &CurStudent, int IDYear, int IDSem, DLinkedList<Year> &ListYear, DLLNode<Course>* &ListCourse, DLLNode<Score>* &ListScore){
   ListCourse =  View_Course(CurStudent,IDYear,IDSem,ListYear);
   DLLNode<Course> *cur = ListCourse;
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
   ListScore = Data.Head;
}
