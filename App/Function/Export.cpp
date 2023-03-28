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
    ofstream fout(folder_path + "/years.CSV");
    if(!fout.is_open()) return false;
    fout << "Year\n";
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
    ofstream fout(yf_path + "/semesters.CSV");
    if(!fout.is_open()) return false;

    DLLNode <Semester> *cur = semester_list.Head;
    string header = "Semester,StartDate,EndDate\n";
    fout << header;

    while(cur)
    {
        fout << cur->data.IDsemester << ',';
        fout << cur->data.start_day << ',';
        fout << cur->data.end_day << '\n';
        string sf_path = yf_path + "/semester" + to_string(cur->data.IDsemester);

        struct stat db;
        if(stat(sf_path.c_str(), &db) != 0)
        if(mkdir(sf_path.c_str()) == -1) return false;

        string cou_path = sf_path + "/courses";

        if(stat(cou_path.c_str(), &db) != 0)
        if(mkdir(cou_path.c_str()) == -1) return false;

        if(!Save_Courses(cou_path, cur->data.course_list)) return false;
        cur = cur->pNext;
    }
    fout.close();
    return true;
}

bool Save_Classes(const string& yf_path, DLinkedList <Class>& class_list)
{
    ofstream fout(yf_path + "/classes.CSV");
    if(!fout.is_open()) return false;
    DLLNode <Class> *cur = class_list.Head;
    string header = "Class\n";
    fout << header;
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
    string file_name = cf_name + "/students.CSV";
    ofstream fout(file_name);
    if(!fout.is_open()) return false;
    string header = "No,ID,FirstName,LastName,Gender,dob,Social_ID\n";
    fout << header;
    while(cur)
    {
        fout << cur->data.No << ',';
        fout << cur->data.ID << ',';
        fout << cur->data.FirstName << ',';
        fout << cur->data.LastName << ',';
        fout << cur->data.Gender << ',';
        fout << cur->data.dob << ',';
        fout << cur->data.Social_ID << '\n';
        cur = cur->pNext;
    }
    fout.close();
    return true;
}

bool Save_Courses(const string& sf_path, DLinkedList <Course>& course_list)
{
    ofstream fout(sf_path + "/courses.CSV");
    if(!fout.is_open()) return false;
    string header = "CourseID,CourseName,ClassName,TeacherName,CreditsNum,StudentsMax,DayOfWeek,Session\n";
    fout << header;
    DLLNode <Course> *cur = course_list.Head;
    while(cur)
    {
        fout << cur->data.ID << ',';
        fout << cur->data.course_name << ',';
        fout << cur->data.class_name << ',';
        fout << cur->data.teacher_name << ',';
        fout << cur->data.credits_num << ',';
        fout << cur->data.max_students << ',';
        fout << cur->data.day_of_week << ',';
        fout << cur->data.session << endl;

        string course_path = sf_path + "/" + cur->data.course_name;
        struct stat db;

        if(stat(course_path.c_str(), &db) != 0)
        if(mkdir(course_path.c_str()) == -1) return false;

        if(!Save_Students(course_path, cur->data.stu_list)) return false;
        if(!Save_Scoreboards(course_path, cur->data.sco_board)) return false;
        cur = cur->pNext;
    }
    fout.close();
    return true;
}

bool Save_Scoreboards(const string& course_path, Scoreboard& sco_board)
{
    ofstream fout(course_path + "/scoreboard.CSV");
    if(!fout.is_open()) return false;
    string header = "No,ID,first_name,last_name,total_mark,final_mark,mid_mark,other_mark\n";
    fout << header;
    DLLNode <Score> *cur = sco_board.score_list.Head;
    while(cur)
    {
        fout << cur->data.No << ',';
        fout << cur->data.stu_id << ',';
        fout << cur->data.first_name << ',';
        fout << cur->data.last_name << ',';
        fout << cur->data.tot_mark << ',';
        fout << cur->data.fin_mark << ',';
        fout << cur->data.mid_mark << ',';
        fout << cur->data.other_mark << endl;
        cur = cur->pNext;
    }
    fout.close();
    return true;
}

