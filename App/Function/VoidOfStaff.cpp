#include "VoidOfStaff.h"
#include "VoidOfStudent.h"

bool Add_A_Semester(Year& ye, Semester& sem)
{
    if(!ValidSemester(sem.IDsemester)) return false;
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
        if(!CheckFullName(cur_student.FirstName)) continue;
        cur_student.LastName=LName;
        if(!CheckFullName(cur_student.LastName)) continue;
        cur_student.Gender=stoi(Gen);
        if(!isnum(Gen[0])) continue;
        cur_student.dob=dofb;
        if(!CheckDOB(cur_student.dob)) continue;
        cur_student.Social_ID= Soc_ID ;
        if(!CheckID(cur_student.Social_ID)) continue;
        if(cur_course.stu_list.GetByValue(cur_student)) continue;
        cur_course.stu_list.push(cur_student);
    }
    fin.close();
    return true;
}

bool ExportToCSV(Course& cou, const string& filename)
{
    ofstream fout(filename);
    if(!fout.is_open()) return false;
    string line = "No,ID,FirstName,LastName,TotalMark,FinalMark,MidtermMark,OtherMark\n";
    fout << line;
    DLLNode<Student> *cur = cou.stu_list.Head;
    int no = 1;
    while(cur)
    {
        fout << no << ','
            << cur->data.ID << ','
            << cur->data.FirstName << ','
            << cur->data.LastName << ',' << endl;
        no++;
        cur = cur->pNext;
    }
    fout.close();
    return true;
}

bool ImpScoreCSV(const string filepath, DLinkedList<Score>& sco_list) {
 
    ifstream fin(filepath);
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
        sco_list.push(cur_score);
    }
    fin.close();
    return true;
}