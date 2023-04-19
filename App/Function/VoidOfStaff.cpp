#include "VoidOfStaff.h"

bool Add_A_Semester(Year& ye, Semester& sem)
{
    if(ye.sem_list.GetByValue(sem)) return false;
    ye.sem_list.push_descending(sem);
    return true;
}

bool Add_A_Course(Semester& sem, Course& cou)
{
    if(sem.course_list.GetByValue(cou)) return false;
    sem.course_list.push(cou);
    return true;
}

bool QInputStuInCourse(const string& filename,Course& cur_course)
{
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
        cur_student.ID = id;
        cur_student.FirstName=FName;
        cur_student.LastName=LName;
        cur_student.Gender=stoi(Gen);
        cur_student.dob=dofb;
        cur_student.Social_ID=stoll(Soc_ID);
        if(cur_course.stu_list.GetByValue(cur_student)) continue;
        cur_course.stu_list.push(cur_student);
    }
    fin.close();
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

    fout << pass << '\n';
    fout << 1 << '\n';
    fout << stu.FirstName << '\n';
    fout << stu.LastName << '\n';
    fout << stu.Gender << '\n';
    fout << stu.dob << '\n';
    fout << stu.Social_ID;
    fout.close();
    return true;
}

bool UpdateDataStudent(Student& stu, const string& folderpath)
{
    string filename = folderpath + '/' + "UserData.txt";
    ofstream fout(filename, ios::app);
    if(!fout.is_open()) return false;

    fout << stu.ID << ' '
        << stu.FirstName << ' '
        << stu.LastName << ' '
        << stu.Gender << ' '
        << stu.dob << ' '
        << stu.Social_ID << '\n';

    fout.close();
    return true;
}








