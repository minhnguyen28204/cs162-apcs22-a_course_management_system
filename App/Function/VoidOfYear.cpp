#include "VoidOfYear.h"
#include "VoidOfStaff.h"
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
    UpdateStudentAccount(CurStudent,"Information");
    CurClass.stu_list.push(CurStudent);
    return true;
}
bool QuickInputClass(const string& folderpath,Class &CurClass){
    ifstream fin(folderpath);
    if(!fin.is_open()){
        return false;
    }
    string line, no, id, FName, LName, Gen, dofb, Soc_ID;
    fin >> line;
    while(fin >> line)
    {
        stringstream ss(line);
        cout << line << '\n';
        getline(ss, no, ',');
        getline(ss, id, ',');
        getline(ss, FName, ',');
        getline(ss, LName, ',');
        getline(ss, Gen, ',');
        getline(ss, dofb, ',');
        getline(ss, Soc_ID, ',');
        Student cur_student;
        cur_student.ID = id;
        cur_student.FirstName=FName;
        cur_student.LastName=LName;
        cur_student.Gender=stoi(Gen);
        cur_student.dob=dofb;
        cur_student.Social_ID = Soc_ID;
        if (CurClass.stu_list.GetByValue(cur_student)!=nullptr) return false;
        CurClass.stu_list.push(cur_student);
    }
    fin.close();
    return true;
}
