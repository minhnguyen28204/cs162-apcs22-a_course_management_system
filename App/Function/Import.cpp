#include "Import.h"
bool importData(const string& folderpath,DLinkedList<Year> &year_list )
{
    if(!importListyear(folderpath,year_list))
    return false;

    return true;
}

bool importListyear(const string& folderpath, DLinkedList <Year> &year_list)
{
    string year_file = folderpath + "/years.CSV";
    ifstream fin(year_file);
    if(!fin.is_open()) return false;
    string line, yearid;
    getline(fin, line);
    while (getline(fin, line))
    {
        stringstream ss(line);
        getline(ss, yearid);
        Year new_year;
        new_year.IDyear = stoi(yearid);
        year_list.push_back(new_year);
        string yearpath=year_file+"/"+yearid+"-"+to_string(new_year.IDyear+1);
        if(!importListsemester(yearpath,new_year.sem_list))
            return false;
        if(!importListclass(yearpath, new_year.classes_list))
            return false;
    }
     
    fin.close();
    

    return true;

}

bool importListsemester(const string& folderpath, DLinkedList <Semester>&semester_list)
{
    string semester_file=folderpath +"/semesters.CSV";
    ifstream fin(semester_file);
    if(!fin.is_open()) return false;
    string line, IDsem, s_day, e_day;
    getline(fin,line);
    while(getline(fin,line))
    {
        stringstream ss(line);
        getline(ss, IDsem, ',');
        getline(ss, s_day, ',');
        getline(ss, e_day);
        Semester cur_semester;
        cur_semester.IDsemester=stoi(IDsem);
        cur_semester.start_day=s_day;
        cur_semester.end_day=e_day;
        semester_list.push_back(cur_semester);
        string sempath=folderpath+"/semesters"+"/"+"semester"+to_string(cur_semester.IDsemester) + "/courses";
        if(!importListcourse(sempath,cur_semester.course_list))
            return false;

    }
    fin.close();
    return true;
}

bool importListclass(const string& folderpath, DLinkedList <Class> &class_list)
{
    string class_file=folderpath+"/classes.CSV";
    ifstream fin(class_file);
    if(!fin.is_open()) return false;
    string line,clname;
    getline(fin,line);
    while(getline(fin,line))
    {
        getline(fin,clname);
        Class cur_class;
        cur_class.class_name = clname;
        class_list.push_back(cur_class);
    }
    fin.close();
    return true;
}

bool importListcourse(const string& folderpath,DLinkedList <Course> &course_list)
{
    string course_file=folderpath + "/courses.CSV";
    ifstream fin(course_file);
    if(!fin.is_open()) return false;
    string line, id, cour_name, cl_name, teach_name, cre_num, max_stu, dow, sess;
    getline(fin,line);
    while(getline(fin,line))
    {
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, cour_name, ',');
        getline(ss, cl_name, ',');
        getline(ss, teach_name, ',');
        getline(ss, cre_num, ',');
        getline(ss, max_stu, ',');
        getline(ss, dow, ',');
        getline(ss, sess);
        Course cur_course;
        cur_course.ID=stoi(id);
        cur_course.course_name=cour_name;
        cur_course.class_name=cl_name;
        cur_course.teacher_name=teach_name;
        cur_course.credits_num=stoi(cre_num);
        cur_course.max_students=stoi(max_stu);
        cur_course.day_of_week=dow;
        cur_course.session=sess;
        course_list.push_back(cur_course);
        string coursepath=folderpath+"/" + cur_course.course_name;
        if(!importListstudent(coursepath,cur_course.stu_list))
        return false;
        if(!importScoreboard(coursepath,cur_course.sco_board))
        return false;
    }
    fin.close();
    return true;
}

bool importListstudent(const string& folderpath,DLinkedList <Student> student_list)
{
    string student_file=folderpath + "/students.CSV";
    ifstream fin(student_file);
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
        cur_student.No=stoi(no);
        cur_student.ID=stoi(id);
        cur_student.FirstName=FName;
        cur_student.LastName=LName;
        cur_student.Gender=stoi(Gen);
        cur_student.dob=dofb;
        cur_student.Social_ID=stoi(Soc_ID);
        student_list.push_back(cur_student);
    }
    fin.close();
    return true;
}

bool importScoreboard(const string folderpath, Scoreboard sco)
{
    string score_file=folderpath+"/scores.CSV";
    ifstream fin(score_file);
    if(!fin.is_open()) return false;
    string line,no,id,f_name,l_name,total_mark,fi_mark,mi_mark,oth_mark;
    getline(fin,line);
    while (getline(fin,line))
    {
        stringstream ss(line);
        getline(ss, no, ',');
        getline(ss, id, ',');
        getline(ss, f_name, ',');
        getline(ss, l_name, ',');
        getline(ss, total_mark, ',');
        getline(ss, fi_mark, ',');
        getline(ss, mi_mark, ',');
        getline(ss, oth_mark);
        Score cur_score;
        cur_score.No=stoi(no);
        cur_score.stu_id=stoi(id);
        cur_score.first_name=f_name;
        cur_score.last_name=l_name;
        cur_score.tot_mark=stod(total_mark);
        cur_score.fin_mark=stod(fi_mark);
        cur_score.mid_mark=stod(mi_mark);
        cur_score.other_mark=stod(oth_mark);
        sco.score_list.push_back(cur_score);
    }
    fin.close();
    return true;
}