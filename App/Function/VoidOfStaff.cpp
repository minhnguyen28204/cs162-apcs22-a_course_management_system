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
        if(cur_course.stu_list.GetByValue(cur_student)) continue;
        cur_course.stu_list.push(cur_student);
        CreateDefaultScore(cur_course,cur_student);
    }
    fin.close();
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

bool ExportToCSV(Course& cou, const string& filename)
{
    ofstream fout(filename);
    if(!fout.is_open()) return false;
    string line = "No,ID,FirstName,LastName,TotalMark,FinalMark,MidtermMark,OtherMark\n";
    fout << line;
    DLLNode<Score> *cur = cou.score_list.Head;
    int no = 1;
    while(cur)
    {
        fout << no << ','
            << cur->data.stu_id << ','
            << cur->data.first_name << ','
            << cur->data.last_name << ','
            << cur->data.tot_mark << ','
            << cur->data.fin_mark << ','
            << cur->data.mid_mark << ','
            << cur->data.other_mark << endl;
        no++;
        cur = cur->pNext;
    }
    fout.close();
    return true;
}

bool ImpScoreCSV(const string folderpath, DLinkedList<Year> &ListYear, int IDYear, Course &CurCou, DLLNode<Score> *OldScore, DLinkedList<Score>& new_scorelist) {

    ifstream fin(folderpath);
    if (!fin.is_open()) return false;
    string line;
    getline(fin, line); // skip header line
    while (getline(fin, line)) {
        stringstream ss(line);
        string field;
        Score cur_score;
        getline(ss, field, ',');
        getline(ss, cur_score.stu_id, ',');
        if(!CheckID(cur_score.stu_id)) continue;
        getline(ss, cur_score.first_name, ',');
        if(!CheckFullName(cur_score.first_name)) continue;
        getline(ss, cur_score.last_name, ',');
        if(!CheckFullName(cur_score.last_name)) continue;
        getline(ss, line, ',');
        if(!CheckGrade(line)) cur_score.tot_mark = 0;
        else cur_score.tot_mark = stof(line);
        getline(ss, line, ',');
        if(!CheckGrade(line)) cur_score.fin_mark = 0;
        else cur_score.fin_mark = stof(line);
        getline(ss, line, ',');
        if(!CheckGrade(line)) cur_score.mid_mark = 0;
        else cur_score.mid_mark = stof(line);
        getline(ss, line);
        if(!CheckGrade(line)) cur_score.other_mark = 0;
        else cur_score.other_mark = stof(line);
        new_scorelist.push(cur_score);
    }
    fin.close();


    Update(CurCou, CurCou.score_list.Head, new_scorelist.Head, ListYear,false);
    CurCou.score_list.Delete();
    CurCou.score_list.Head = new_scorelist.Head;
    new_scorelist.Reset();

    return true;
}

void CreateDefaultScore(Course& cur_cou, Student& cur_stu)
{
    Score sc;
    sc.stu_id = cur_stu.ID;
    sc.first_name = cur_stu.FirstName;
    sc.last_name = cur_stu.LastName;
    sc.fin_mark = 0;
    sc.mid_mark = 0;
    sc.tot_mark = 0;
    sc.other_mark = 0;
    cur_cou.score_list.push(sc);
}

void UpdateCourseID(Course& CourseList, string newID)
{
    CourseList.ID = newID;
}
void UpdateCourseName(Course& CourseList, string newCourseName)
{
    CourseList.course_name = newCourseName;
}
void UpdateClassName(Course& CourseList, string newClassName)
{
    CourseList.class_name = newClassName;
}
void UpdateCourseTeacher(Course& CourseList, string newTeacher)
{
    CourseList.teacher_name = newTeacher;
}
void UpdateCourseCredits_Num(Course& CourseList, int newCredits_Num)
{
    CourseList.credits_num = newCredits_Num;
}
void UpdateCourseMax_Students(Course& CourseList, int newMax_Students)
{
    CourseList.max_students = newMax_Students;
}
void UpdateDay_Of_Week(Course& CourseList, string newDay_Of_Week)
{
    CourseList.day_of_week = newDay_Of_Week;
}
void UpdateSession(Course& CourseList, string newSession)
{
    CourseList.session = newSession;
}
bool AddStudentToCourse(Course& CourseList, Student newStudent, bool& isinclass)
{
    string filename = "Information/User/" + newStudent.ID + ".dat";
    ifstream fin(filename.c_str());
    if(!fin.is_open())
    {
        isinclass = false;
        return false;
    }
    fin.close();
    isinclass = true;
    if (CourseList.stu_list.GetByValue(newStudent)) return false;
    CourseList.stu_list.push(newStudent);
    CreateDefaultScore(CourseList,newStudent);
    return true;
}

void RemoveStudent(DLinkedList <Student>& StudentList, Student DeleteStudent)
{
    StudentList.remove(DeleteStudent);
}
void DeleteCourse(DLinkedList <Course>& CourseList, Course DeleteCourse)
{
    CourseList.remove(DeleteCourse);
}
bool UpdateScoreFinal(DLLNode <Score> *newSco, string x)
{
    if(!CheckGrade(x)) return false;
    newSco->data.fin_mark = stof(x);
    return true;
}

bool UpdateScoreMidterm(DLLNode <Score> *newSco, string x)
{
    if(!CheckGrade(x)) return false;
    newSco->data.mid_mark = stof(x);
    return true;
}

bool UpdateScoreTotal(DLLNode <Score> *newSco, string x)
{
    if(!CheckGrade(x)) return false;
    newSco->data.tot_mark = stof(x);
    return true;
}

bool UpdateScoreOther(DLLNode <Score> *newSco, string x)
{
    if(!CheckGrade(x)) return false;
    newSco->data.other_mark = stof(x);
    return true;
}
void PublicScoreboard(Course &CurCou, DLinkedList<Year> &ListYear){
    CurCou.unlocked = true;
    Update(CurCou,nullptr,CurCou.score_list.Head, ListYear, true);
}
