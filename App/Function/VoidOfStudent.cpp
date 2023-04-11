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
bool FindStudent(Student *&CurStudent, int IDYear, int StuID, DLinkedList<Year> &ListYear){
    Student tmp;
    tmp.ID = StuID;
    Year NewYear;
    NewYear.IDyear = IDYear;
    DLLNode<Year>* cur = ListYear.GetByValue(NewYear);
    if (cur == nullptr) return false;
    DLLNode<Class> *CurClass  = cur->data.classes_list.Head;
    DLLNode<Student> *CurPointer;
    while (CurClass){
        CurPointer = CurClass->data.stu_list.GetByValue(tmp);
        if (CurPointer!=nullptr){
            CurStudent = &CurPointer->data;
            return true;
        }
    }
    return false;
}
void UpdateStudentResult(Student *&CurStudent, Course &CurCou, Score &CurScore, int del){
    (*CurStudent).Number_Of_Credits += CurCou.credits_num*del;
    (*CurStudent).GPA += CurScore.tot_mark*CurCou.credits_num*del;
}
void Update(int IDYear, Course &CurCou, DLLNode<Score> *OldScore, DLLNode<Score> *NewScore, DLinkedList<Year> &ListYear){
    DLLNode<Score> *Cur = OldScore;
    Student *CurStudent;
    FindStudent(CurStudent, IDYear, OldScore->data.stu_id,ListYear);
    while (Cur){
        UpdateStudentResult(CurStudent,CurCou,Cur->data,-1);
        Cur=Cur->pNext;
    }
    Cur = NewScore;
    while (Cur){
        UpdateStudentResult(CurStudent,CurCou,Cur->data,1);
        Cur=Cur->pNext;
    }
}
