#ifndef VOID_OF_STUDENT_CPP
#define VOID_OF_STUDENT_CPP
#ifndef VOID_OF_STUDENT_CPP
#define VOID_OF_STUDENT_CPP
#include "VoidOfStudent.h"
void ViewResultInSemester(Student &CurStudent, int IDYear, int IDSem, DLinkedList<Year> &ListYear, DLinkedList<Course> &ListCourse, DLLNode<Score>* &ListScore, int &Number_Of_Credits, double &TotalScore){
   Number_Of_Credits = 0;
   TotalScore = 0;
   View_Course(CurStudent,IDYear,IDSem,ListYear,ListCourse);
   DLLNode<Course> *cur = ListCourse.Head;
   DLinkedList<Score> Data;
   //cur = CurCourse
   //cur2 = cur score;
   while (cur){
        DLLNode<Score> *cur2 = cur->data.score_list.Head;
        bool check = false;
        while (cur2){
            if (cur2->data.stu_id==CurStudent.ID) {
                Number_Of_Credits+=cur->data.credits_num;
                TotalScore += cur2->data.tot_mark * cur->data.credits_num;
                Data.push_back(cur2->data);
                check = true;
                break;
            }
            cur2 = cur2 -> pNext;
        }
        if (!check){
            cout << "Khong co diem trong course " << cur->data.course_name;
            return;
        }
        cur = cur -> pNext;
   }
   ListScore = Data.Head;
}
bool FindStudent(Student *&CurStudent, string StuID, DLinkedList<Year> &ListYear){
    Student tmp;
    tmp.ID = StuID;
    DLLNode<Year>* cur = ListYear.Head;
    while (cur){
        DLLNode<Class> *CurClass  = cur->data.classes_list.Head;
        DLLNode<Student> *CurPointer;
        while (CurClass){
            CurPointer = CurClass->data.stu_list.GetByValue(tmp);
            if (CurPointer!=nullptr){
                CurStudent = &CurPointer->data;
                return true;
            }
            CurClass = CurClass->pNext;
        }
        cur=cur->pNext;
    }
    return false;
}
void UpdateStudentResult(Student *&CurStudent, Course &CurCou, Score &CurScore, int del){
    (*CurStudent).Number_Of_Credits += CurCou.credits_num*del;
    (*CurStudent).TotalScore += CurScore.tot_mark*CurCou.credits_num*del;
}
void Update(Course &CurCou, DLLNode<Score> *OldScore, DLLNode<Score> *NewScore, DLinkedList<Year> &ListYear){
    DLLNode<Score> *Cur = OldScore;
    while (Cur){
        Student *CurStudent;
        if (!FindStudent(CurStudent, Cur->data.stu_id,ListYear)){
            cout << "No student in old ";
            cout << Cur->data.stu_id;
            return;
        };
        UpdateStudentResult(CurStudent,CurCou,Cur->data,-1);
        Cur=Cur->pNext;
    }
    Cur = NewScore;
    while (Cur){
        Student *CurStudent;
        if (!FindStudent(CurStudent, Cur->data.stu_id,ListYear)){
            cout << "No student in new ";
            cout << Cur->data.stu_id;
            return;
        }
        UpdateStudentResult(CurStudent,CurCou,Cur->data,1);
        Cur=Cur->pNext;
    }
}
#endif // VOID_OF_STUDENT_CPP
