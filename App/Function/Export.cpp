#include "Export.h"

bool Save_Data(const string& folder_path, DLinkedList <Year>& year_list)
{
    struct stat db;
    if(stat(folder_path.c_str(), &db) != 0)
    if(mkdir(folder_path.c_str()) == -1) return false;

    if(!Save_Years(folder_path, year_list)) return false;
    return true;
}

bool Save_Years(const string& folder_path,DLinkedList <Year>& year_list)
{
    ofstream fout(folder_path + "/years.dat");
    if(!fout.is_open()) return false;
    DLLNode <Year> *cur = year_list.Head;
    while(cur)
    {
        fout << cur->data.IDyear << endl;
        string yf_path = folder_path + "/" + to_string(cur->data.IDyear) + "-" + to_string(cur->data.IDyear + 1);
        
        struct stat db;
        if(stat(yf_path.c_str(), &db) != 0)
        if(mkdir(yf_path.c_str()) == -1) return false;

        string sem_path = yf_path + "/semesters";

        if(stat(sem_path.c_str(), &db) != 0)
        if(mkdir(sem_path.c_str()) == -1) return false;

        if(!Save_Semesters(sem_path, cur->data.sem_list)) return false;

        string cla_path = yf_path + "/classes";

        if(stat(cla_path.c_str(), &db) != 0)
        if(mkdir(cla_path.c_str()) == -1) return false;

        if(!Save_Classes(cla_path, cur->data.classes_list)) return false;
        cur = cur->pNext;
    }
    fout.close();
    return true;
}

bool Save_Semesters(const string& yf_path, DLinkedList <Semester>& semester_list)
{
    ofstream fout(yf_path + "/semesters.dat");
    if(!fout.is_open()) return false;

    DLLNode <Semester> *cur = semester_list.Head;

    while(cur)
    {
        fout << cur->data.IDsemester << '\n';
        fout << cur->data.start_day << '\n';
        fout << cur->data.end_day << '\n';
        string sf_path = yf_path + "/semester" + to_string(cur->data.IDsemester);

        struct stat db;
        if(stat(sf_path.c_str(), &db) != 0)
        if(mkdir(sf_path.c_str()) == -1) return false;
        
        if(!Save_Courses(sf_path, cur->data.course_list)) return false;
        cur = cur->pNext;
    }
    fout.close();
    return true;
}

bool Save_Classes(const string& yf_path, DLinkedList <Class>& class_list)
{
    ofstream fout(yf_path + "/classes.dat");
    if(!fout.is_open()) return false;
    DLLNode <Class> *cur = class_list.Head;

    while(cur)
    {
        fout << cur->data.class_name << endl;
        string cf_name = yf_path + "/" + cur->data.class_name;
        
        struct stat db;
        if(stat(cf_name.c_str(), &db) != 0)
        if(mkdir(cf_name.c_str()) == -1) return false;

        if(!Save_Students(cf_name, cur->data.stu_list)) return false;
        cur = cur->pNext;
    }
    fout.close();
    return true;
}

bool Save_Students(const string& cf_name, DLinkedList <Student>& student_list)
{
    DLLNode <Student> *cur = student_list.Head;
    string file_name = cf_name + "/students.dat";
    ofstream fout(file_name);
    if(!fout.is_open()) return false;

    while(cur)
    {
        fout << cur->data.No << '\n';
        fout << cur->data.ID << '\n';
        fout << cur->data.FirstName << '\n';
        fout << cur->data.LastName << '\n';
        fout << cur->data.Gender << '\n';
        fout << cur->data.dob << '\n';
        fout << cur->data.Social_ID << '\n';
        cur = cur->pNext;
    }
    fout.close();
    return true;
}

bool Save_Courses(const string& sf_path, DLinkedList <Course>& course_list)
{
    ofstream fout(sf_path + "/courses.dat");
    if(!fout.is_open()) return false;

    DLLNode <Course> *cur = course_list.Head;
    while(cur)
    {
        fout << cur->data.ID << '\n';
        fout << cur->data.course_name << '\n';
        fout << cur->data.class_name << '\n';
        fout << cur->data.teacher_name << '\n';
        fout << cur->data.credits_num << '\n';
        fout << cur->data.max_students << '\n';
        fout << cur->data.day_of_week << '\n';
        fout << cur->data.session << '\n';
        
        string course_path = sf_path + "/" + cur->data.ID + "_" + cur->data.class_name;
        struct stat db;
        
        if(stat(course_path.c_str(), &db) != 0)
        if(mkdir(course_path.c_str()) == -1) return false;
        
        if(!Save_Students(course_path, cur->data.stu_list)) return false;
        if(!Save_Scoreboards(course_path, cur->data.score_list)) return false;
        cur = cur->pNext;
    }
    fout.close();
    return true;
}

bool Save_Scoreboards(const string& course_path, DLinkedList <Score>& sco_list)
{
    ofstream fout(course_path + "/scoreboard.dat");
    if(!fout.is_open()) return false;

    DLLNode <Score> *cur = sco_list.Head;
    while(cur)
    {
        fout << cur->data.No << '\n';
        fout << cur->data.stu_id << '\n';
        fout << cur->data.first_name << '\n';
        fout << cur->data.last_name << '\n';
        fout << cur->data.tot_mark << '\n';
        fout << cur->data.fin_mark << '\n';
        fout << cur->data.mid_mark << '\n';
        fout << cur->data.other_mark << '\n';
        cur = cur->pNext;
    }
    fout.close();
    return true;
}
