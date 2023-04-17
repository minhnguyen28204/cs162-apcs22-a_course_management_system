#include "VoidOfStaff.h"
#include "VoidOfStudent.h"

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

bool QInputStuInCourse(const string& filename,Course& cur_course, const string& folderpath)
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
        cur_student.FirstName=FName;
        cur_student.LastName=LName;
        cur_student.Gender=stoi(Gen);
        cur_student.dob=dofb;
        cur_student.Social_ID= Soc_ID ;
        if(cur_course.stu_list.GetByValue(cur_student)) continue;
        cur_course.stu_list.push(cur_student);
        if(!UpdateStudentAccount(cur_student, folderpath)) return false;
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
        getline(ss, cur_score.first_name, ',');
        getline(ss, cur_score.last_name, ',');
        fin >> cur_score.tot_mark;
        fin >> cur_score.fin_mark;
        fin >> cur_score.mid_mark;
        fin >> cur_score.other_mark;
        fin.ignore(1000,'\n');

        new_scorelist.push(cur_score);
    }
    fin.close();
    
    Update(IDYear, CurCou, CurCou.score_list.Head, new_scorelist.Head, ListYear);
    CurCou.score_list.Delete();
    CurCou.score_list.Head = new_scorelist.Head;
    return true;
}