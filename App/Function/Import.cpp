#include "Import.h"

bool importData(const string& folderpath,DLinkedList<Year> &year_list )
{
    if(!importListyear(folderpath,year_list))
    return false;

    return true;
}

bool importListyear(const string& folderpath, DLinkedList <Year> &year_list)
{
    string year_file = folderpath + "/years.dat";
    ifstream fin(year_file);
    if(!fin.is_open()) return false;
    string line;
    while (getline(fin, line))
    {
        Year new_year;
        new_year.IDyear = stoi(line);
        string yearpath = folderpath + "/"+ to_string(new_year.IDyear)+ "-" + to_string(new_year.IDyear+1);
        if(!importListclass(yearpath, new_year.classes_list))
            return false;
        if(!importListsemester(yearpath,new_year.sem_list))
            return false;
        year_list.push_descending(new_year);
    }

    fin.close();
    return true;
}

bool importListsemester(const string& folderpath, DLinkedList <Semester>&semester_list)
{
    string semester_file=folderpath + "/semesters/semesters.dat";
    ifstream fin(semester_file);
    if(!fin.is_open()) return false;
    string line;
    while(getline(fin, line))
    {
        Semester cur_semester;
        cur_semester.IDsemester = stoi(line);
        getline(fin, cur_semester.start_day);
        getline(fin, cur_semester.end_day);
        string sempath=folderpath + "/semesters/semester" + line;
        if(!importListcourse(sempath,cur_semester.course_list))
            return false;
        semester_list.push_descending(cur_semester);
    }
    fin.close();
    return true;
}

bool importListclass(const string& folderpath, DLinkedList <Class> &class_list)
{
    string class_file=folderpath+"/classes/classes.dat";
    ifstream fin(class_file);
    if(!fin.is_open()) return false;
    string line;
    while(getline(fin, line))
    {
        Class cur_class;
        cur_class.class_name = line;
        string clpath = folderpath + "/classes" + "/" + line;
        if(!importListstudent(clpath, cur_class.stu_list))
        return false;

        class_list.push(cur_class);
    }
    fin.close();
    return true;
}

bool importListcourse(const string& folderpath,DLinkedList <Course> &course_list)
{
    string course_file=folderpath + "/courses.dat";
    ifstream fin(course_file);
    if(!fin.is_open()) return false;

    string line;
    while(getline(fin,line))
    {
        Course cur_course;
        cur_course.ID = line;
        getline(fin, cur_course.course_name);
        getline(fin, cur_course.class_name);
        getline(fin, cur_course.teacher_name);
        fin >> cur_course.credits_num;
        fin >> cur_course.max_students;
        fin.ignore();
        getline(fin, cur_course.day_of_week);
        getline(fin, cur_course.session);
        string coursepath = folderpath + "/" + line + "_" + cur_course.class_name;
        if(!importListstudent(coursepath,cur_course.stu_list))
        return false;
        if(!importScoreboard(coursepath,cur_course.score_list))
        return false;
        course_list.push(cur_course);
    }
    fin.close();
    return true;
}

bool importListstudent(const string& folderpath,DLinkedList <Student>& student_list)
{
    string student_file=folderpath + "/students.dat";
    ifstream fin(student_file);
    if(!fin.is_open()) return false;
    string line;
    while(getline(fin, line))
    {
        Student cur_student;
        fin >> cur_student.ID;
        fin.ignore(1000,'\n');
        getline(fin, cur_student.FirstName);
        getline(fin, cur_student.LastName);
        fin >> cur_student.Gender;
        fin.ignore(1000, '\n');
        getline(fin, cur_student.dob);
        fin >> cur_student.Social_ID;
        fin.ignore(1000, '\n');
        student_list.push(cur_student);
    }
    fin.close();
    return true;
}

bool importScoreboard(const string folderpath, DLinkedList <Score>& sco_list)
{
    string score_file=folderpath+"/scoreboard.dat";
    ifstream fin(score_file);
    if(!fin.is_open()) return false;

    string line;
    while (getline(fin, line))
    {
        Score cur_score;
        cur_score.No = stoi(line);
        fin >> cur_score.stu_id;
        fin.ignore(1000, '\n');
        getline(fin, cur_score.first_name);
        getline(fin, cur_score.last_name);
        fin >> cur_score.tot_mark;
        fin >> cur_score.fin_mark;
        fin >> cur_score.mid_mark;
        fin >> cur_score.other_mark;
        fin.ignore(1000, '\n');
        sco_list.push(cur_score);
    }
    fin.close();
    return true;
}
