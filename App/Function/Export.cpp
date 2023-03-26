#include "Export.h"

void Save_Data(const string& folder_path, DLinkedList <Year>& year_list)
{
    filesystem::create_directory(folder_path);
    Save_Years(folder_path, year_list);
}

void Save_Years(const string& folder_path,DLinkedList <Year>& year_list)
{
    ofstream fout(folder_path + "/years.CSV");
    if(year_list.isEmpty()) return;
    DLLNode <Year> *cur = year_list.Head;
    fout << "year" << endl;
    while(cur)
    {
        fout << cur->data.IDyear << endl;
        string yf_path = folder_path + "/" + to_string(cur->data.IDyear) + "-" + to_string(cur->data.IDyear + 1);
        filesystem::create_directories(yf_path);
        string sem_path = yf_path + "/semesters";
        filesystem::create_directories(sem_path);
        Save_Semesters(sem_path, cur->data.sem_list);
        string cla_path = yf_path + "/classes";
        filesystem::create_directories(cla_path);
        Save_Classes(cla_path, cur->data.classes_list);
        cur = cur->pNext;
    }
    fout.close();
}

void Save_Semesters(const string& yf_path, DLinkedList <Semester>& semester_list)
{
    ofstream fout(yf_path + "/semesters.CSV");
    if(semester_list.isEmpty()) return;
    DLLNode <Semester> *cur = semester_list.Head;
    string header = "Year,Semester,StartDate,EndDate\n";
    fout << header;
    while(cur)
    {
        fout << cur->data.IDsemester << ',';
        fout << cur->data.start_day << ',';
        fout << cur->data.end_day << '\n';
        string sf_path = yf_path + "/semester" + to_string(cur->data.IDsemester);
        filesystem::create_directories(sf_path);
        string cou_path = sf_path + "/courses";
        filesystem::create_directories(cou_path);
        Save_Courses(cou_path, cur->data.course_list);
        cur = cur->pNext;
    }
    fout.close();
}

void Save_Classes(const string& yf_path, DLinkedList <Class>& class_list)
{
    ofstream fout(yf_path + "/classes.CSV");
    if(class_list.isEmpty()) return;
    DLLNode <Class> *cur = class_list.Head;
    string header = "Class\n";
    fout << header;
    while(cur)
    {
        fout << cur->data.class_name << endl;
        string cf_name = yf_path + "/" + cur->data.class_name;
        filesystem::create_directory(cf_name);
        Save_Students(cf_name, cur->data.stu_list);
        cur = cur->pNext;
    }
    fout.close();
}

void Save_Students(const string& cf_name, DLinkedList <Student>& student_list)
{
    if(student_list.isEmpty()) return;
    DLLNode <Student> *cur = student_list.Head;
    string file_name = cf_name + "/students.CSV";
    ofstream fout(file_name);
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
}

void Save_Courses(const string& sf_path, DLinkedList <Course>& course_list)
{
    ofstream fout(sf_path + "/courses.CSV");
    if(course_list.isEmpty()) return;
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
        filesystem::create_directory(course_path);
        Save_Students(course_path, cur->data.stu_list);
        Save_Scoreboards(course_path, cur->data.sco_board);
        cur = cur->pNext;
    }
    fout.close();
}

void Save_Scoreboards(const string& course_path, Scoreboard& sco_board)
{
    if(sco_board.score_list.isEmpty()) return;
    ofstream fout(course_path + "/scoreboard.CSV");
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
}

