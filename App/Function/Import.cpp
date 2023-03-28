#include "Import.h"

void Add_Class(DLinkedList <Class>& classes_list)
{
    Class new_class;
    // code to set the properties of the new_class object

    // check if the class already exists in the list
    DLLNode<Class>* cur_class = classes_list.Head;
    while (cur_class != nullptr)
    {
        if (cur_class->data.class_name == new_class.class_name)
        {
            // class already exists, do not insert
            return;
        }
        cur_class = cur_class->pNext;
    }

    // class does not exist, insert it at the end of the list
    classes_list.push_back(new_class);
}

void importClass(string filename, DLinkedList <Class> &classes_list)
{
    ifstream fin(filename);
    string line, class_name, No, ID, FirstName, LastName, Gender, dob, Social_ID;
    getline(fin, line); // skip header row

    while (getline(fin, line))
    {
        stringstream ss(line);
        getline(ss, class_name, ',');
        getline(ss, No, ',');
        getline(ss, ID, ',');
        getline(ss, FirstName, ',');
        getline(ss, LastName, ',');
        getline(ss, Gender, ',');
        getline(ss, dob, ',');
        getline(ss, Social_ID, ',');
        Class cur_class(class_name);
        cur_class.Add_A_Student(No, ID, FirstName, LastName, Gender, dob, Social_ID);
        classes_list.Add_Class(cur_class);
        
    }
    fin.close();
}

void importCourse(String filename, DLinkedList <Semester> &courses_list)
{
    ifstream fin(filename);
    string line, year, semester, ID, course_name, class_name, teacher_name, credits_num, max_students, day_of_week, session, enrolled_students;
    getline(fin, line); // skip header row
    while (getline(fin, line))
    {
        stringstream ss(line);
        getline(ss, year, ',');
        getline(ss, semester, ',');
        getline(ss, ID, ',');
        getline(ss, course_name, ',');
        getline(ss, class_name, ',');
        getline(ss, teacher_name, ',');
        getline(ss, credits_num, ',');
        getline(ss, max_students, ',');
        getline(ss, day_of_week, ',');
        getline(ss, session, ',');
        Course cur_course(year, semester, ID, course_name, class_name, teacher_name, credits_num, max_students, day_of_week, session);
        while (getline(ss, enrolled_students, ','))
        {
            cur_course.ID_list.push_back(stoi(enrolled_students));
        }
        courses_list.push_back(cur_course);
    }
    fin.close();
}

void importSemester(string filename, DLinkedList <Semester> &semester_list)
{
    ifstream fin(filename);
    string line, year, IDsemester, start_day, end_day;
    getline(fin, line); // skip header row
    while (getline(fin, line))
    {
        stringstream ss(line);
        getline(ss, year, ',');
        getline(ss, IDsemester, ',');
        getline(ss, start_day, ',');
        getline(ss, end_day, ',');
        Semester cur_semester(IDsemester, start_day, end_day);
        semester_list.push_back(cur_semester);
    }
    fin.close();
}

void importYear(string filename, DLinkedList <Year> &year_list)
{
    ifstream fin(filename);
    string line, year;
    while (getline(fin, line))
    {
        stringstream ss(line);
        getline(ss, year);
        Year new_year(year);
        year_list.push_back(new_year);
    }
    fin.close();
}