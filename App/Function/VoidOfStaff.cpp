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
        cur_student.ID=stoi(id);
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

void updateStudentAccount(Student& stu, string& folderpath)
{
    ofstream fout(folderpath + "/" + stu.ID + ".dat");
    if (!fout.is_open()) return;
    int len = stu.dob.length();
    string pass(len, ' '); // Initialize the pass string with the same length as dob
    int count = 0;
    for (int i = 0; i < len; ++i)
    {
        if (stu.dob[i] != '/')
        {
            pass[count] = stu.dob[i];
            count++;
        }
    }
    fout << pass;
    fout.close();
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


bool ScoreCSV(const string folderpath, DLinkedList<Score>& sco_list) {

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

        sco_list.push(cur_score);
    }
    fin.close();
    return true;
}





