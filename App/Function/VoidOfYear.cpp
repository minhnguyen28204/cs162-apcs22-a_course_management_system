#include "VoidOfYear.h"


bool CreateNewYear(DLinkedList<Year> &ListYear, Year &NewYear){
    if (ListYear.GetByValue(NewYear)!=nullptr) return false;
    ListYear.push_descending(NewYear);
    return true;
}
bool AddClass(Year &CurYear, Class &CurClass){
    if (CurYear.classes_list.GetByValue(CurClass)!=nullptr) return false;
    CurYear.classes_list.push(CurClass);
    return true;
}
bool AddStudent(Class &CurClass, Student &CurStudent){
    if (CurClass.stu_list.GetByValue(CurStudent)!=nullptr) return false;
    CurClass.stu_list.push(CurStudent);
    return true;
}

bool UpdateStudentAccount(Student& stu, const string& folderpath)
{
    string filename = folderpath + "/User/" + stu.ID + ".dat";
    ofstream fout(filename);
    if (!fout.is_open()) return false;

    int len = stu.dob.length();
    string pass = "";
    for (int i = 0; i < len; ++i)
    {
        if (stu.dob[i] != '/') pass.push_back(stu.dob[i]);
    }

    fout << pass << endl
        << true << endl
        << stu.FirstName << ' '
        << stu.LastName << ' '
        << stu.Gender << ' '
        << stu.dob << ' '
        << stu.Social_ID << '\n';


    fout.close();
    return true;
}

bool QuickInputClass(const string& filename,Class &CurClass, const string& folderpath){
    ifstream fin(filename);
    if(!fin.is_open()) return false;
    string line, no, id, FName, LName, Gen, dofb, Soc_ID;
    getline(fin,line);
    while(getline(fin,line))
    {
        stringstream ss(line);
        getline(ss, no, ',');
        getline(ss, id, ',');
        getline(ss, FName, ',');
        getline(ss, LName, ',');
        getline(ss, Gen, ',');
        getline(ss, dofb, ',');
        getline(ss, Soc_ID, ',');
        Student cur_student;
        cur_student.ID= id ;
        if(!CheckID(cur_student.ID)) continue;
        cur_student.FirstName=FName;
        if(!CheckName(cur_student.FirstName)) continue;
        cur_student.LastName=LName;
        if(!CheckName(cur_student.LastName)) continue;
        cur_student.Gender=stoi(Gen);
        if(!isnum(Gen[0])) continue;
        cur_student.dob=dofb;
        if(!CheckDOB(cur_student.dob)) continue;
        cur_student.Social_ID= Soc_ID ;
        if(!CheckID(cur_student.Social_ID)) continue;
        AddStudent(CurClass,cur_student);
        if(!UpdateStudentAccount(cur_student, folderpath)) return continue;
    }
    fin.close();
    return true;
}
