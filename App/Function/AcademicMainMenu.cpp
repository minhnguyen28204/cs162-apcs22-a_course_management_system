#include "AcademicMainMenu.h"
#include "TextField.h"
#include "TextBox.h"
#include "Button.h"
#include "year.h"
#include "Import.h"
#include "Export.h"
#include "Vector.h"
#include "VoidOfYear.h"
#include "VoidOfStaff.h"
#include "DropdownBox.h"
#include "ChangePass.h"
#include <vector>

string Point(double &a){
      string s;
      s= to_string((int)(a));
      if (((int)(a*10))%10 == 0) return s;
      s += '.';
      s += to_string((int)(a*10)%10);
     return s;
}

sf::Texture ob;
sf::Texture cat;
sf::Sprite background;
sf::Sprite cursor;
sf::Sprite Non;
sf::Font _Font;
sf::Text welcome;
sf::Text author;
sf::Text default_year;
sf::Text default_semester;
ButtonLibrary CheckLogOut;
ButtonLibrary MainMenu;
ButtonLibrary MainMenu2;
bool is_MainMenu;

bool is_ViewClass;
bool is_ViewClass2;
bool is_ViewClass3;
bool is_ViewScoreOfClass;

bool is_ViewCourse;
bool is_ViewCourse2;
bool is_ViewCourse3;
bool is_ViewDetailCourse;
bool is_ViewStudentCourse;
bool is_ChoseAction;
bool is_ViewStudentScoreboard;

bool is_AddSchoolYear;
bool is_AddClass;
bool is_AddCourse;
bool is_AddSemester;
bool is_AddStudent;
bool is_AddStudentToCourse;
bool is_AddIndividual;
bool is_AddFromCSV;
bool is_ChoseClass;

bool is_ChangePass;

Vector<ButtonLibrary> Page;

int curpage = 0;
DLinkedList <Year> ListYear;

//ViewCourse
ButtonLibrary viewcourse_buttons;
ButtonLibrary viewcourse3_buttons;

//View detail Course
sf::Text ID;
TextField detail_ID(_Font,24,sf::Color::Black,300,195,700,40,true);
sf::Text course_name;
TextField detail_course_name(_Font,24,sf::Color::Black,345,245,655,40,true);
sf::Text class_name;
TextField detail_class_name(_Font,24,sf::Color::Black,330,295,670,40,true);
sf::Text teacher_name;
TextField detail_teacher_name(_Font,24,sf::Color::Black,343,345,657,40,true);
sf::Text credits_num;
TextField detail_credits_num(_Font,24,sf::Color::Black,385,395,615,40,true);
sf::Text max_students;
TextField detail_max_students(_Font,24,sf::Color::Black,340,445,660,40,true);
sf::Text day_of_week;
TextField detail_day_of_week(_Font,24,sf::Color::Black,337,495,663,40,true);
sf::Text session;
TextField detail_session(_Font,24,sf::Color::Black,290,545,710,40,true);
ButtonLibrary detail_vecbutton;
DLLNode<Course> *CurChosenCourse;

//View student in course
ButtonLibrary viewstudent_vecbutton;
ButtonLibrary choseaction_vecbutton;
DLLNode<Student> *CurChoseStudent;

//Chose semester
ButtonLibrary ChoseSemester;
Button CurSemester;
int ID_chosen_semester;
Vector<int> all_semester_id;

//ViewClass
Vector<int> all_year_id;
int ID_chosen_year;
int chose_year_curpage;
Vector<ButtonLibrary> chose_year_page;
ButtonLibrary viewclass_vecbutton;

//ViewClass2
ButtonLibrary viewclass2_vecbutton;

//ViewClass3
Vector<ButtonLibrary> chose_student_page;
Button CurStu;
Vector<string> all_student_name;
int ID_chosen_student;
int chose_student_curpage;
ButtonLibrary viewclass3_vecbutton;

//View Scoreboard in Class
ButtonLibrary viewscoreboard_vecbutton;
vector<vector<TextBox>> ScorePage;
vector<TextBox> current_page;
int cur_score_page;
TextBox Course_ID;
TextBox Course_Name;
TextBox Total_Point;
TextBox ID_Score;
TextBox Name_Score;
TextBox Total_Score;
TextBox SemGPA;
TextBox OveGPA;

//Add school year
sf::Text addschoolyear_text;
TextField addschoolyear_textfield(_Font,24,sf::Color::Black,200,400,800,50,true);
ButtonLibrary addschoolyear_vecbutton;

//Add Classes
ButtonLibrary addclass_vecbutton;
TextField addclass_classname_input(_Font,24,sf::Color::Black,250,350,700,50,true);
sf::Text addclass_classname;

//Add course
ButtonLibrary addcourse_vecbutton;
TextField ID_input(_Font,24,sf::Color::Black,250,200,700,50,true);
sf::Text addcourse_id;
TextField Name_input(_Font,24,sf::Color::Black,250,300,700,50,true);
sf::Text addcourse_name;
TextField Class_input(_Font,24,sf::Color::Black,250,400,700,50,true);
sf::Text addcourse_class;
TextField Teacher_input(_Font,24,sf::Color::Black,250,500,700,50,true);
sf::Text addcourse_teacher;
TextField Credits_input(_Font,24,sf::Color::Black,250,200,700,50,true);
sf::Text addcourse_credits;
TextField MaxStudent_input(_Font,24,sf::Color::Black,250,300,700,50,true);
sf::Text addcourse_maxstu;
TextField DayWeek_input(_Font,24,sf::Color::Black,250,400,700,50,true);
sf::Text addcourse_dayweek;
TextField Session_input(_Font,24,sf::Color::Black,250,500,700,50,true);
sf::Text addcourse_sess;
ButtonLibrary p1, p2;
int cur_addcourse_page = 0;
Course temp;


//Add semester
ButtonLibrary addsemester_vecbutton;
TextField IDSem(_Font,24,sf::Color::Black,250,300,700,50,true);
TextField StDay(_Font,24,sf::Color::Black,250,400,700,50,true);
TextField EnDay(_Font,24,sf::Color::Black,250,500,700,50,true);
sf::Text addsem_box;
sf::Text addsem_stday;
sf::Text addsem_enday;

//Add student
ButtonLibrary addstudent_vecbutton;
ButtonLibrary addstudent_indi;
ButtonLibrary addstudent_csv;

//Chose Class
Vector<string> all_class_name;
int ID_chosen_class;
int chose_class_curpage;
Vector<ButtonLibrary> chose_class_page;
ButtonLibrary choseclass_vecbutton;
Button CurClass;

//Chose course
Vector<string> all_course_id;
int ID_chosen_course;
int chose_course_curpage;
Vector<ButtonLibrary> chose_course_page;
Button CurCourse;
ButtonLibrary chosecourse_vecbutton;

//Add individual
sf::Text addstudent_ID;
sf::Text addstudent_FirstName;
sf::Text addstudent_LastName;
sf::Text addstudent_Gender;
sf::Text addstudent_Dob;
sf::Text addstudent_Social;
TextField addstudent_ID_input(_Font,24,sf::Color::Black,300,200,700,50,true);
TextField addstudent_FirstName_input(_Font,24,sf::Color::Black,300,270,700,50,true);
TextField addstudent_LastName_input(_Font,24,sf::Color::Black,300,340,700,50,true);
TextField addstudent_Gender_input(_Font,24,sf::Color::Black,600,410,400,50,true);
TextField addstudent_Dob_input(_Font,24,sf::Color::Black,300,480,700,50,true);
TextField addstudent_Social_input(_Font,24,sf::Color::Black,300,550,700,50,true);
ButtonLibrary addindi_vecbutton;

//Add student from csv file
sf::Text addstudent_folderpath;
sf::Text addstudent_manual;
TextField addstudent_folderpath_input(_Font,20,sf::Color::Black,300,375,700,50,true);

//Change password
TextField oldpass(_Font,24,sf::Color::Black,400,300,600,50,true);
sf::Text Oldpass;
TextField newpass(_Font,24,sf::Color::Black,400,400,600,50,true);
sf::Text Newpass;
ButtonLibrary changepass_vecbutton;

void setText(sf::Text &m_text, string str, sf::Font& _Font, unsigned int Size, float x, float y, sf::Color color){
    m_text.setString(str);
    m_text.setFont(_Font);
    m_text.setCharacterSize(Size);
    m_text.setPosition(x,y);
    m_text.setColor(color);
}

void SetBackGround(){
    ob.loadFromFile("Image/MainMenu.png");
    cat.loadFromFile("Image/CatDab.png");
    background.setTexture(ob);
    cursor.setTexture(cat);
    _Font.loadFromFile("resources/font.ttf");
}

void SetwelcomeText(User Who){
    setText(welcome,"Welcome " + Who.FirstName + " " + Who.LastName,_Font,24,20,20,sf::Color::Black);
    setText(author,"A project made by Group 3, APCS22, enjoy using it :3",_Font,15,170,760,sf::Color::Black);
}

//handle add school year
void HandleAddSchoolYear(sf::RenderWindow &window){
        string cur_year_id = addschoolyear_textfield.getText();
        int ID = 0;
        for(int i=0; i<cur_year_id.size(); i++) ID = ID * 10 + cur_year_id[i]-'0';
        Year NY;
        NY.IDyear = stoi(cur_year_id);
        bool is_add_success = CreateNewYear(ListYear,NY);
        if (is_add_success){
            TextBox Info(400,325,400,150,_Font,"Added successfully",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
            addschoolyear_textfield.clear_str();
            setText(default_year,"Current year: " + to_string(ListYear.Head->data.IDyear),_Font,20,50,50,sf::Color::Black);
            setText(default_semester,"",_Font,20,300,50,sf::Color::Black);
            is_MainMenu = true;
            is_AddSchoolYear = false;
        }
        else{
            TextBox Info(400,325,400,150,_Font,"Invalid year",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
}

//OK handle add class
void HandleAddClass(sf::RenderWindow &window){
        string TEMP = addclass_classname_input.getText();
        Class NC; NC.class_name = TEMP;
        bool is_add_success = AddClass(ListYear.Head->data,NC);
        if (is_add_success){
            TextBox Info(400,325,400,150,_Font,"Added successfully",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
        else{
            TextBox Info(400,325,400,150,_Font,"Invalid year",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
        addclass_classname_input.clear_str();
        is_MainMenu = true;
        is_AddClass = false;
}

//OK1
void HandleOK1(sf::RenderWindow &window){
    bool is_valid_id = ID_input.getText().size();
    temp.ID = ID_input.getText();
    bool is_valid_class = Class_input.getText().size();
    temp.class_name = Class_input.getText();
    bool is_valid_course = Name_input.getText().size();
    temp.course_name = Name_input.getText();
    string TEMP;
    TEMP = Teacher_input.getText();
    bool is_valid_teacher = false;
    if (TEMP.size()){
        is_valid_teacher = CheckFullName(TEMP);
        temp.teacher_name = TEMP;
    }
    if (is_valid_teacher && is_valid_id && is_valid_class && is_valid_course){
        cur_addcourse_page = 1;
    }
    else{
        if (is_valid_teacher) setText(addcourse_teacher,"Teacher Name",_Font,20,100,510,sf::Color::Black);
        else setText(addcourse_teacher,"Teacher Name",_Font,20,100,510,sf::Color::Red);
        if (is_valid_id) setText(addcourse_id,"Course ID",_Font,20,100,210,sf::Color::Black);
        else setText(addcourse_id,"Course ID",_Font,20,100,210,sf::Color::Red);
        if (is_valid_course) setText(addcourse_name,"Course name",_Font,20,100,310,sf::Color::Black);
        else setText(addcourse_name,"Course name",_Font,20,100,310,sf::Color::Red);
        if (is_valid_class) setText(addcourse_class,"Class name",_Font,20,100,410,sf::Color::Black);
        else setText(addcourse_class,"Class name",_Font,20,100,410,sf::Color::Red);
        TextBox Info(400,325,400,150,_Font,"Invalid information",30);
        Info.draw(window);
        window.display();
        sf::sleep(sf::seconds(2));
        window.clear();
        window.display();
    }
}
//OK2
void HandleOK2(sf::RenderWindow &window){
    string TEMP = Credits_input.getText();

        bool is_valid_credit = false;
        if (TEMP.size()){
            is_valid_credit = CheckID(TEMP);
            if (is_valid_credit) temp.credits_num = stoi(TEMP);
        }

        bool is_valid_dayofweek = false;
        TEMP = DayWeek_input.getText();
        if (TEMP.size()){
            is_valid_dayofweek = CheckDOW(TEMP);
            temp.day_of_week = TEMP;
        }

        bool is_valid_session = false;
        TEMP = Session_input.getText();
        if (TEMP.size()){
            is_valid_session = CheckSession(TEMP);
            temp.session = TEMP;
        }

        bool is_valid_maxstudents = false;
        TEMP = MaxStudent_input.getText();
        if (TEMP.size()){
            is_valid_maxstudents = CheckID(TEMP);
            if (is_valid_maxstudents) temp.max_students = stoi(TEMP);
        }

        bool is_add_success = false;
        if (is_valid_credit && is_valid_dayofweek && is_valid_session && is_valid_maxstudents) is_add_success = Add_A_Course(ListYear.Head->data.sem_list.Head->data,temp);
        if (is_add_success && is_valid_credit && is_valid_dayofweek && is_valid_session && is_valid_maxstudents){
            TextBox Info(400,325,400,150,_Font,"Added successfully",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
            is_AddCourse = false;
            is_MainMenu = true;
        }
        else if (is_valid_credit && is_valid_dayofweek && is_valid_session && is_valid_maxstudents){
            TextBox Info(400,325,400,150,_Font,"Course has already been added",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
        else{
            if (is_valid_credit) setText(addcourse_credits,"Credits",_Font,20,100,210,sf::Color::Black);
            else setText(addcourse_credits,"Credits",_Font,20,100,210,sf::Color::Red);

            if (is_valid_maxstudents) setText(addcourse_maxstu,"Max students",_Font,20,100,310,sf::Color::Black);
            else setText(addcourse_maxstu,"Max students",_Font,20,100,310,sf::Color::Red);

            if (is_valid_dayofweek) setText(addcourse_dayweek,"Day of week",_Font,20,100,410,sf::Color::Black);
            else setText(addcourse_dayweek,"Day of week",_Font,20,100,410,sf::Color::Red);

            if (is_valid_session) setText(addcourse_sess,"Session",_Font,20,100,510,sf::Color::Black);
            else setText(addcourse_sess,"Session",_Font,20,100,510,sf::Color::Red);

            TextBox Info(400,325,400,150,_Font,"Invalid information",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
}
//Handle Add Semester
void HandleAddSemester(sf::RenderWindow &window){
    string temp;
        Semester NS;
        temp = IDSem.getText();
        bool is_valid_temp = false;
        if (temp.size()){
            is_valid_temp = ValidSemester(temp);
            if (is_valid_temp) NS.IDsemester = stoi(temp);
        }

        string start_day = StDay.getText();
        bool is_valid_start = false;
        if (start_day.size()){
            is_valid_start = CheckDOB(start_day);
            if (is_valid_start) NS.start_day = start_day;
        }
        string end_day = EnDay.getText();
        bool is_valid_end = false;
        if (end_day.size()){
            is_valid_end = CheckDOB(end_day);
            if (is_valid_end) NS.end_day = end_day;
        }
        bool is_add_success = false;
        if (is_valid_temp && is_valid_start && is_valid_end) is_add_success = Add_A_Semester(ListYear.Head->data,NS);
        if (is_add_success){
            TextBox Info(400,325,400,150,_Font,"Added successfully",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
            setText(default_semester,"Current semester: " + to_string(ListYear.Head->data.sem_list.Head->data.IDsemester),_Font,20,300,50,sf::Color::Black);
            IDSem.clear_str();
            StDay.clear_str();
            EnDay.clear_str();
            is_AddSemester = false;
            is_MainMenu = true;
            setText(addsem_box,"Semester ID:",_Font,24,100,310,sf::Color::Black);
            setText(addsem_stday,"Start day:",_Font,24,100,410,sf::Color::Black);
            setText(addsem_enday,"End day:",_Font,24,100,510,sf::Color::Black);
        }
        else{
            if (is_valid_temp) setText(addsem_box,"Semester ID:",_Font,24,100,310,sf::Color::Black);
            else setText(addsem_box,"Semester ID:",_Font,24,100,310,sf::Color::Red);
            if (is_valid_start) setText(addsem_stday,"Start day:",_Font,24,100,410,sf::Color::Black);
            else setText(addsem_stday,"Start day:",_Font,24,100,410,sf::Color::Red);
            if (is_valid_end) setText(addsem_enday,"End day:",_Font,24,100,510,sf::Color::Black);
            else setText(addsem_enday,"End day:",_Font,24,100,510,sf::Color::Red);
            TextBox Info(400,325,400,150,_Font,"Invalid information",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
}

void HandleAddIndi(sf::RenderWindow &window){
    Student NS;
        bool is_valid_ID = true;
        string temp;

        temp = addstudent_ID_input.getText();
        if (temp.size()){
            is_valid_ID = CheckID(temp);
            NS.ID = temp;
        }
        else is_valid_ID = false;

        bool is_valid_FN;
        temp = addstudent_FirstName_input.getText();
        if (temp.size()){
            is_valid_FN = CheckFullName(temp);
            NS.FirstName = temp;
        }
        else is_valid_FN = false;

        bool is_valid_LN;
        temp = addstudent_LastName_input.getText();
        if (temp.size()){
            is_valid_LN = CheckFullName(temp);
            NS.LastName = temp;
        }
        else is_valid_LN = false;

        bool is_valid_Gender;
        temp = addstudent_Gender_input.getText();
        if (temp.size()){
            is_valid_Gender = ValidSemester(temp);
            if (is_valid_Gender) NS.Gender = stoi(addstudent_Gender_input.getText());
        }
        else is_valid_Gender = false;

        bool is_valid_dob;
        temp = addstudent_Dob_input.getText();
        if (temp.size()){
            is_valid_dob = CheckDOB(temp);
            NS.dob = temp;
        }
        else is_valid_dob = false;

        bool is_valid_social;
        temp = addstudent_Social_input.getText();
        if (temp.size()){
            is_valid_social = CheckID(temp);
            NS.Social_ID = temp;
        }
        else is_valid_social = false;

        bool is_add_success = false;
        bool is_valid_student = false;
        if (!is_AddStudentToCourse && is_valid_ID && is_valid_FN && is_valid_LN && is_valid_dob && is_valid_social && is_valid_Gender){
            DLLNode<Class> *Cur = ListYear.Head->data.classes_list.Head;
            while (Cur){
                if (Cur->data.class_name == all_class_name[ID_chosen_class]) break;
                Cur = Cur->pNext;
            }
            is_add_success = AddStudent(Cur->data,NS);
        }
        else if (is_AddStudentToCourse && is_valid_ID && is_valid_FN && is_valid_LN && is_valid_dob && is_valid_social && is_valid_Gender){
            DLLNode<Course> *Cur = ListYear.Head->data.sem_list.Head->data.course_list.Head;
            while (Cur){
                if (all_course_id[ID_chosen_course] == Cur->data.ID + " - " + Cur->data.course_name) break;
                Cur = Cur->pNext;
            }
            is_add_success = AddStudentToCourse(Cur->data,NS,is_valid_student,ListYear);
        }
        if (is_add_success){
            TextBox Info(400,325,400,150,_Font,"Added successfully",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
            is_MainMenu = true;
            if (is_AddStudentToCourse) is_AddStudentToCourse = false;
            is_AddIndividual  = false;
        }
        else if (is_valid_ID && is_valid_FN && is_valid_LN && is_valid_dob && is_valid_social && is_valid_Gender && !is_valid_student && is_AddStudentToCourse){
            setText(addstudent_ID,"ID",_Font,24,100,210,sf::Color::Black);
            setText(addstudent_FirstName,"First Name",_Font,25,100,280,sf::Color::Black);
            setText(addstudent_LastName,"Last Name",_Font,25,100,350,sf::Color::Black);
            setText(addstudent_Gender,"Gender (1. Male, 2. Female, 3. Other)",_Font,25,100,420,sf::Color::Black);
            setText(addstudent_Dob,"Date of Birth",_Font,25,100,490,sf::Color::Black);
            setText(addstudent_Social,"Social ID",_Font,25,100,560,sf::Color::Black);
            TextBox info(250,325,700,100,_Font,"Student is not in any class",30);
            info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
        else if (is_valid_ID && is_valid_FN && is_valid_LN && is_valid_dob && is_valid_social && is_valid_Gender && is_AddStudentToCourse){
            setText(addstudent_ID,"ID",_Font,24,100,210,sf::Color::Black);
            setText(addstudent_FirstName,"First Name",_Font,25,100,280,sf::Color::Black);
            setText(addstudent_LastName,"Last Name",_Font,25,100,350,sf::Color::Black);
            setText(addstudent_Gender,"Gender (1. Male, 2. Female, 3. Other)",_Font,25,100,420,sf::Color::Black);
            setText(addstudent_Dob,"Date of Birth",_Font,25,100,490,sf::Color::Black);
            setText(addstudent_Social,"Social ID",_Font,25,100,560,sf::Color::Black);
            TextBox info(250,325,700,100,_Font,"This student has already been in the course",30);
            info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
        else if (is_valid_ID && is_valid_FN && is_valid_LN && is_valid_dob && !is_AddStudentToCourse){
            setText(addstudent_ID,"ID",_Font,24,100,210,sf::Color::Black);
            setText(addstudent_FirstName,"First Name",_Font,25,100,280,sf::Color::Black);
            setText(addstudent_LastName,"Last Name",_Font,25,100,350,sf::Color::Black);
            setText(addstudent_Gender,"Gender (1. Male, 2. Female, 3. Other)",_Font,25,100,420,sf::Color::Black);
            setText(addstudent_Dob,"Date of Birth",_Font,25,100,490,sf::Color::Black);
            setText(addstudent_Social,"Social ID",_Font,25,100,560,sf::Color::Black);
            TextBox info(250,325,700,100,_Font,"This student has already been in the class",30);
            info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
        else{
            if (is_valid_ID) setText(addstudent_ID,"ID",_Font,24,100,210,sf::Color::Black);
            else setText(addstudent_ID,"ID",_Font,24,100,210,sf::Color::Red);
            if (is_valid_FN) setText(addstudent_FirstName,"First Name",_Font,25,100,280,sf::Color::Black);
            else setText(addstudent_FirstName,"First Name",_Font,25,100,280,sf::Color::Red);
            if (is_valid_LN) setText(addstudent_LastName,"Last Name",_Font,25,100,350,sf::Color::Black);
            else setText(addstudent_LastName,"Last Name",_Font,25,100,350,sf::Color::Red);
            if (is_valid_dob) setText(addstudent_Dob,"Date of Birth",_Font,25,100,490,sf::Color::Black);
            else setText(addstudent_Dob,"Date of Birth",_Font,25,100,490,sf::Color::Red);
            if (is_valid_social) setText(addstudent_Social,"Social ID",_Font,25,100,560,sf::Color::Black);
            else setText(addstudent_Social,"Social ID",_Font,25,100,560,sf::Color::Red);
            if (is_valid_Gender) setText(addstudent_Gender,"Gender (1. Male, 2. Female, 3. Other)",_Font,25,100,420,sf::Color::Black);
            else setText(addstudent_Gender,"Gender (1. Male, 2. Female, 3. Other)",_Font,25,100,420,sf::Color::Red);
            TextBox Info(400,325,400,150,_Font,"Invalid information",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
}

void HandleAddCSV(sf::RenderWindow &window){
string folderpath = addstudent_folderpath_input.getText();
        DLLNode<Class> *Cur = ListYear.Head->data.classes_list.Head;
        if (!is_AddStudentToCourse){
            while (Cur){
                if (Cur->data.class_name == all_class_name[ID_chosen_class]) break;
                Cur = Cur->pNext;
            }
        }
        DLLNode<Course> *cur = ListYear.Head->data.sem_list.Head->data.course_list.Head;
        if (is_AddStudentToCourse){
            while(cur){
                if (cur->data.ID + " - " + cur->data.course_name == all_course_id[ID_chosen_course]) break;
                cur = cur->pNext;
            }
        }
        cout << cur->data.course_name << '\n';
        bool is_add_success;
        if (!is_AddStudentToCourse) is_add_success = QuickInputClass(folderpath,Cur->data);
        else is_add_success = QInputStuInCourse(folderpath,cur->data,ListYear);
        if (is_add_success){
            TextBox Info(400,325,400,150,_Font,"Added successfully",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
            is_MainMenu = true;
            if (is_AddStudentToCourse) is_AddStudentToCourse = false;
            is_AddFromCSV = false;
        }
        else{
            TextBox Info(300,325,600,150,_Font,"Invalid folder path, please try again",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
}

void ProcessDetailCourse(){
    DLLNode<Year> *Cur = ListYear.Head;
    while (Cur){
        if (Cur->data.IDyear == all_year_id[ID_chosen_year]) break;
        Cur = Cur->pNext;
    }
    DLLNode<Semester> *cur = Cur->data.sem_list.Head;
    while (cur){
        if (cur->data.IDsemester == ID_chosen_semester) break;
        cur = cur->pNext;
    }
    DLLNode<Course> *cur_course = cur->data.course_list.Head;
    while (cur_course){
        if (cur_course->data.ID + " - " + cur_course->data.course_name == all_course_id[ID_chosen_course]) break;
        cur_course = cur_course->pNext;
    }
    CurChosenCourse = cur_course;
    setText(ID,"Course id: ",_Font,24,200,200,sf::Color::Black);
    detail_ID.SetIniStr(cur_course->data.ID);
    setText(course_name,"Course name: ",_Font,24,200,250,sf::Color::Black);
    detail_course_name.SetIniStr(cur_course->data.course_name);
    setText(class_name,"Class name: ",_Font,24,200,300,sf::Color::Black);
    detail_class_name.SetIniStr(cur_course->data.class_name);
    setText(teacher_name,"Teacher name: ",_Font,24,200,350,sf::Color::Black);
    detail_teacher_name.SetIniStr(cur_course->data.teacher_name);
    setText(credits_num,"Number of credits: ",_Font,24,200,400,sf::Color::Black);
    detail_credits_num.SetIniStr(to_string(cur_course->data.credits_num));
    setText(max_students,"Max students: ",_Font,24,200,450,sf::Color::Black);
    detail_max_students.SetIniStr(to_string(cur_course->data.max_students));
    setText(day_of_week,"Day of week: ",_Font,24,200,500,sf::Color::Black);
    detail_day_of_week.SetIniStr(cur_course->data.day_of_week);
    setText(session,"Session: ",_Font,24,200,550,sf::Color::Black);
    detail_session.SetIniStr(cur_course->data.session);
}

//Draw window
void DrawWindow(sf::RenderWindow &window){
    window.clear();
    window.draw(background);
    window.draw(welcome);
    window.draw(author);
    CheckLogOut.draw(window);
    window.draw(default_year);
    window.draw(default_semester);

    if (is_MainMenu) Page[curpage].draw(window);

    if (is_ViewCourse){
        if (chose_year_page.getSize()) chose_year_page[chose_year_curpage].draw(window);
        viewcourse_buttons.draw(window);
    }
    else if (is_ViewCourse2){
        ChoseSemester.draw(window);
    }
    else if (is_ViewCourse3){
        if (chose_course_page.getSize()) chose_course_page[chose_course_curpage].draw(window);
        viewcourse3_buttons.draw(window);
    }
    else if (is_ViewDetailCourse){
        //cout << all_year_id[ID_chosen_year] << ' ' << ID_chosen_semester << ' ' << all_course_id[ID_chosen_course] << '\n';
        window.draw(ID); window.draw(course_name); window.draw(class_name); window.draw(teacher_name);
        window.draw(credits_num); window.draw(max_students); window.draw(day_of_week); window.draw(session);
        detail_ID.draw(window);
        detail_course_name.draw(window);
        detail_class_name.draw(window);
        detail_teacher_name.draw(window);
        detail_credits_num.draw(window);
        detail_max_students.draw(window);
        detail_day_of_week.draw(window);
        detail_session.draw(window);
        detail_vecbutton.draw(window);
    }
    else if (is_ViewStudentCourse){
        if (chose_student_page.getSize()) chose_student_page[chose_student_curpage].draw(window);
        viewstudent_vecbutton.draw(window);
    }
    else if (is_ChoseAction){
        choseaction_vecbutton.draw(window);
    }

    if (is_ViewClass){
        if (chose_year_page.getSize()) chose_year_page[chose_year_curpage].draw(window);
        viewclass_vecbutton.draw(window);
    }
    else if (is_ViewClass2) {
        if (chose_class_page.getSize()) chose_class_page[chose_class_curpage].draw(window);
        viewclass2_vecbutton.draw(window);
    }
    else if (is_ViewClass3){
        if (chose_student_page.getSize()) chose_student_page[chose_student_curpage].draw(window);
        viewclass3_vecbutton.draw(window);
    }
    else if (is_ViewScoreOfClass){
        viewscoreboard_vecbutton.draw(window);
        Course_ID.draw(window);
        Course_Name.draw(window);
        Total_Point.draw(window);
        OveGPA.draw(window);
        SemGPA.draw(window);
        if (ScorePage.size()){
            for(int j=0; j<ScorePage[cur_score_page].size(); j++){
                ScorePage[cur_score_page][j].draw(window);
            }
        }
    }

    if (is_AddSchoolYear){
        window.draw(addschoolyear_text);
        addschoolyear_textfield.draw(window);
        addschoolyear_vecbutton.draw(window);
    }

    if (is_AddClass){
        addclass_vecbutton.draw(window);
        addclass_classname_input.draw(window);
        window.draw(addclass_classname);
    }

    if (is_AddCourse){
        addcourse_vecbutton.draw(window);
        if (cur_addcourse_page==0){
            ID_input.draw(window); window.draw(addcourse_id);
            Class_input.draw(window); window.draw(addcourse_name);
            Teacher_input.draw(window); window.draw(addcourse_class);
            Name_input.draw(window); window.draw(addcourse_teacher);
        }
        else{
            MaxStudent_input.draw(window); window.draw(addcourse_maxstu);
            Session_input.draw(window); window.draw(addcourse_sess);
            Credits_input.draw(window); window.draw(addcourse_credits);
            DayWeek_input.draw(window); window.draw(addcourse_dayweek);
        }
        if (cur_addcourse_page==0) p1.draw(window);
        else p2.draw(window);
    }

    if (is_AddSemester){
        addsemester_vecbutton.draw(window);
        IDSem.draw(window);
        StDay.draw(window);
        EnDay.draw(window);
        window.draw(addsem_box);
        window.draw(addsem_stday);
        window.draw(addsem_enday);
    }

    if (is_AddStudent){
        addstudent_vecbutton.draw(window);
    }
    if (is_ChoseClass && !is_AddStudent){
        if (chose_class_page.getSize()) chose_class_page[chose_class_curpage].draw(window);
        choseclass_vecbutton.draw(window);
    }
    if (is_AddIndividual){
        addstudent_indi.draw(window);
        addstudent_ID_input.draw(window);
        addstudent_FirstName_input.draw(window);
        addstudent_LastName_input.draw(window);
        addstudent_Gender_input.draw(window);
        addstudent_Dob_input.draw(window);
        addstudent_Social_input.draw(window);
        window.draw(addstudent_ID);
        window.draw(addstudent_FirstName);
        window.draw(addstudent_LastName);
        window.draw(addstudent_Gender);
        window.draw(addstudent_Dob);
        window.draw(addstudent_Social);
        addindi_vecbutton.draw(window);
    }
    if (is_AddFromCSV){
        addstudent_csv.draw(window);
        window.draw(addstudent_folderpath);
        window.draw(addstudent_manual);
        addstudent_folderpath_input.draw(window);
    }

    if (is_AddStudentToCourse && !is_AddStudent && !is_AddIndividual && !is_AddFromCSV){
        if (chose_course_page.getSize()) chose_course_page[chose_course_curpage].draw(window);
        chosecourse_vecbutton.draw(window);
    }
    if (is_ChangePass){
        oldpass.draw(window); window.draw(Oldpass);
        newpass.draw(window); window.draw(Newpass);
        changepass_vecbutton.draw(window);
    }
    window.display();
}



//Handle event query from the window
void HandleEvent(sf::Event event, sf::RenderWindow &window){
    CheckLogOut.handleEvent(event);

    if (is_MainMenu) Page[curpage].handleEvent(event);

    if (is_ViewCourse){
        if (chose_year_page.getSize()) chose_year_page[chose_year_curpage].handleEvent(event);
        viewcourse_buttons.handleEvent(event);
    }
    else if (is_ViewCourse2){
        ChoseSemester.handleEvent(event);
    }
    else if (is_ViewCourse3){
        if (chose_course_page.getSize()) chose_course_page[chose_course_curpage].handleEvent(event);
        viewcourse3_buttons.handleEvent(event);
    }
    else if (is_ViewDetailCourse){
        detail_vecbutton.handleEvent(event);
        detail_ID.handleEvent(event);
        detail_course_name.handleEvent(event);
        detail_class_name.handleEvent(event);
        detail_credits_num.handleEvent(event);
        detail_day_of_week.handleEvent(event);
        detail_max_students.handleEvent(event);
        detail_session.handleEvent(event);
        detail_teacher_name.handleEvent(event);
    }
    else if (is_ViewStudentCourse){
        if (chose_student_page.getSize()) chose_student_page[chose_student_curpage].handleEvent(event);
        viewstudent_vecbutton.handleEvent(event);
    }
    else if (is_ChoseAction){
        choseaction_vecbutton.handleEvent(event);
    }

    if (is_ViewClass){
        if (chose_year_page.getSize()) chose_year_page[chose_year_curpage].handleEvent(event);
        viewclass_vecbutton.handleEvent(event);
    }
    else if (is_ViewClass2){
        if (chose_class_page.getSize()) chose_class_page[chose_class_curpage].handleEvent(event);
        viewclass2_vecbutton.handleEvent(event);
    }

    else if (is_ViewClass3){
        if (chose_student_page.getSize()) chose_student_page[chose_student_curpage].handleEvent(event);
        viewclass3_vecbutton.handleEvent(event);
    }
    else if (is_ViewScoreOfClass){
        viewscoreboard_vecbutton.handleEvent(event);
    }

    if (is_AddSchoolYear){
        addschoolyear_vecbutton.handleEvent(event);
        addschoolyear_textfield.handleEvent(event);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter){
            HandleAddSchoolYear(window);
        }
    }

    if (is_AddClass){
        addclass_vecbutton.handleEvent(event);
        addclass_classname_input.handleEvent(event);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) HandleAddClass(window);
    }

    if (is_AddCourse){
        addcourse_vecbutton.handleEvent(event);
        if (cur_addcourse_page==0){
            p1.handleEvent(event);
            ID_input.handleEvent(event);
            Class_input.handleEvent(event);
            Teacher_input.handleEvent(event);
            Name_input.handleEvent(event);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) HandleOK1(window);
        }
        else{
            p2.handleEvent(event);
            MaxStudent_input.handleEvent(event);
            Session_input.handleEvent(event);
            Credits_input.handleEvent(event);
            DayWeek_input.handleEvent(event);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) HandleOK2(window);
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab){
            if (ID_input.cur_state()){
                ID_input.Tab_handle();
                Name_input.Tab_handle();
            }
            else if (Name_input.cur_state()){
                Name_input.Tab_handle();
                Class_input.Tab_handle();
            }
            else if (Class_input.cur_state()){
                Class_input.Tab_handle();
                Teacher_input.Tab_handle();
            }
            else if (Teacher_input.cur_state()){
                Teacher_input.Tab_handle();
                ID_input.Tab_handle();
            }

            if (Credits_input.cur_state()){
                Credits_input.Tab_handle();
                MaxStudent_input.Tab_handle();
            }
            else if (MaxStudent_input.cur_state()){
                MaxStudent_input.Tab_handle();
                DayWeek_input.Tab_handle();
            }
            else if (DayWeek_input.cur_state()){
                DayWeek_input.Tab_handle();
                Session_input.Tab_handle();
            }
            else if (Session_input.cur_state()){
                Session_input.Tab_handle();
                Credits_input.Tab_handle();
            }
        }
    }

    if (is_AddSemester){
        addsemester_vecbutton.handleEvent(event);
        IDSem.handleEvent(event);
        StDay.handleEvent(event);
        EnDay.handleEvent(event);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) HandleAddSemester(window);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab){
            if (IDSem.cur_state()){
                IDSem.Tab_handle();
                StDay.Tab_handle();
            }
            else if (StDay.cur_state()){
                StDay.Tab_handle();
                EnDay.Tab_handle();
            }
            else if (EnDay.cur_state()){
                EnDay.Tab_handle();
                IDSem.Tab_handle();
            }
        }
    }


    if (is_ChoseClass && !is_MainMenu){
        if (chose_class_page.getSize()) chose_class_page[chose_class_curpage].handleEvent(event);
        choseclass_vecbutton.handleEvent(event);
    }
    else if (is_AddIndividual && !is_AddStudent){
        addstudent_indi.handleEvent(event);
        addstudent_ID_input.handleEvent(event);
        addstudent_FirstName_input.handleEvent(event);
        addstudent_LastName_input.handleEvent(event);
        addstudent_Gender_input.handleEvent(event);
        addstudent_Dob_input.handleEvent(event);
        addstudent_Social_input.handleEvent(event);
        addindi_vecbutton.handleEvent(event);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) HandleAddIndi(window);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab){
            if (addstudent_ID_input.cur_state()){
                addstudent_ID_input.Tab_handle();
                addstudent_FirstName_input.Tab_handle();
            }
            else if (addstudent_FirstName_input.cur_state()){
                addstudent_FirstName_input.Tab_handle();
                addstudent_LastName_input.Tab_handle();
            }
            else if (addstudent_LastName_input.cur_state()){
                addstudent_LastName_input.Tab_handle();
                addstudent_Gender_input.Tab_handle();
            }
            else if (addstudent_Gender_input.cur_state()){
                addstudent_Gender_input.Tab_handle();
                addstudent_Dob_input.Tab_handle();
            }
            else if (addstudent_Dob_input.cur_state()){
                addstudent_Dob_input.Tab_handle();
                addstudent_Social_input.Tab_handle();
            }
            else if (addstudent_Social_input.cur_state()){
                addstudent_Social_input.Tab_handle();
                addstudent_ID_input.Tab_handle();
            }
        }
    }
    else if (is_AddFromCSV && !is_AddStudent){
        addstudent_csv.handleEvent(event);
        addstudent_folderpath_input.handleEvent(event);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) HandleAddCSV(window);
    }
    else if (is_AddStudent && !is_ChoseClass){
        addstudent_vecbutton.handleEvent(event);
    }
    if (is_AddStudentToCourse && !is_AddStudent && !is_AddIndividual && !is_AddFromCSV){
        if (chose_course_page.getSize()) chose_course_page[chose_course_curpage].handleEvent(event);
        chosecourse_vecbutton.handleEvent(event);
    }
    if (is_ChangePass){
        changepass_vecbutton.handleEvent(event);
        oldpass.handleEvent(event);
        newpass.handleEvent(event);
    }
}

void ProcessScoreBoardOfStudent(){
    DLLNode<Year> *CurYear = ListYear.Head;
    DLLNode<Semester> *CurSem = CurYear->data.sem_list.Head;
    DLinkedList<Course> ListCourse;
    DLLNode<Score> *ListScore = nullptr;
    int Numcredit=0;
    double Total_point=0;
    //
    ViewResultInSemester(CurChoseStudent->data,CurYear->data.IDyear,CurSem->data.IDsemester,ListYear,ListCourse,ListScore,Numcredit,Total_point);

    double gpa = 0;
    if (Numcredit) gpa = Total_point/Numcredit;
    double OveGpa =  0;
    if (CurChoseStudent->data.Number_Of_Credits) OveGpa = CurChoseStudent->data.TotalScore/CurChoseStudent->data.Number_Of_Credits;
    cout << CurChoseStudent->data.TotalScore << ' ' << CurChoseStudent->data.Number_Of_Credits << '\n';
    SemGPA.SetDetail(500,100,150,50,_Font,"GPA: " + Point(gpa),24);
    OveGPA.SetDetail(700,100,300,50,_Font,"Overall GPA: " + Point(OveGpa),24);
    Course_ID.SetDetail(200,200,100,50,_Font,"ID",24);
    Course_Name.SetDetail(300,200,600,50,_Font,"Course name",24);
    Total_Point.SetDetail(900,200,100,50,_Font,"Total",24);
    ScorePage.clear();
    if (ListScore==nullptr) {cout << "Wrong qua wrong roi\n";return;}
    DLLNode<Course> *cur = ListCourse.Head;
    if (cur==nullptr) {cout << "Wrong double r\n"; return;}
    while (cur){
        int cnt = 5;
        int UpperBound = 250;
        current_page.clear();
        while (cnt && cur){
            ID_Score.SetDetail(200,UpperBound,100,50,_Font,cur->data.ID,24);
            Name_Score.SetDetail(300,UpperBound,600,50,_Font,cur->data.course_name,24);
            TextBox Total(900,UpperBound,100,50,_Font,Point(ListScore->data.tot_mark),24);
            current_page.push_back(ID_Score);
            current_page.push_back(Name_Score);
            current_page.push_back(Total);
            cur = cur->pNext;
            ListScore = ListScore->pNext;
            UpperBound+=50;
            cnt--;
        }
        ScorePage.push_back(current_page);
    }
    cur_score_page = 0;
}

void ProcessListOfStudent(){
    DLLNode <Year> *cur = ListYear.Head;
    while (cur){
        if (cur->data.IDyear==all_year_id[ID_chosen_year]) break;
        cur = cur->pNext;
    }
    DLLNode <Class> *Cur = cur->data.classes_list.Head;
    while (Cur){
        if (Cur->data.class_name==all_class_name[ID_chosen_class]) break;
        Cur = Cur->pNext;
    }
    DLLNode <Student> *head = Cur->data.stu_list.Head;
    while (all_student_name.getSize()) all_student_name.pop_back();
    while (chose_student_page.getSize()) chose_student_page.pop_back();
    int cur_num = 0;
    int i = 0;
    while (head){
        ButtonLibrary CurPage;
        int cnt = 4;
        int UpperBound = 205;
        while (cnt && head){
            all_student_name.push_back(head->data.ID + " - " + head->data.FirstName + " " + head->data.LastName);
            CurStu.SetFunction([=](){
                CurChoseStudent = head;
                is_ViewClass3 = false;
                is_ViewScoreOfClass  = true;
                ProcessScoreBoardOfStudent();
            });
            CurStu.ChangeText(all_student_name[cur_num]);
            CurStu.SetDetail(Non,24,400,UpperBound,400,40);
            CurPage.addButton(CurStu);
            cnt--;
            cur_num++;
            UpperBound+=100;
            head = head->pNext;
        }
        chose_student_page.push_back(CurPage);
    }
    chose_student_curpage = 0;
}

void ProcessListOfClass(){
    DLLNode <Year> *cur = ListYear.Head;
    while (cur){
        if (cur->data.IDyear==all_year_id[ID_chosen_year]) break;
        cur = cur->pNext;
    }
    DLLNode <Class> *Cur = cur->data.classes_list.Head;
    while (all_class_name.getSize()) all_class_name.pop_back();
    while (chose_class_page.getSize()) chose_class_page.pop_back();
    int cur_num = 0;
    string Temp;
    while (Cur){
        Temp = Cur->data.class_name;
        all_class_name.push_back(Temp);
        Cur = Cur->pNext;
        cur_num++;
    }
    int i = 0;
    while (i < cur_num){
        ButtonLibrary CurPage;
        int cnt = 4;
        int UpperBound = 205;
        while (cnt && i < cur_num){
            CurClass.SetFunction([=](){
                if (!is_MainMenu){
                    ID_chosen_class = i;
                    is_ViewClass2 = false;
                    is_ViewClass3 = true;
                    ProcessListOfStudent();
                }
            });
            CurClass.ChangeText(all_class_name[i]);
            CurClass.SetDetail(Non,24,400,UpperBound,400,40);
            CurPage.addButton(CurClass);
            cnt--;
            UpperBound += 100;
            i++;
        }
        chose_class_page.push_back(CurPage);
    }
    chose_class_curpage = 0;
}

void ProcessListOfCourse(){
    DLLNode<Year> *Cur = ListYear.Head;
    while (Cur){
        if (Cur->data.IDyear == all_year_id[ID_chosen_year]) break;
        Cur = Cur->pNext;
    }
    DLLNode<Semester> *cur = Cur->data.sem_list.Head;
    while (cur){
        if (cur->data.IDsemester == ID_chosen_semester) break;
        cur = cur->pNext;
    }
    DLLNode<Course> *cur_course = cur->data.course_list.Head;
    while (all_course_id.getSize()) all_course_id.pop_back();
    while (chose_course_page.getSize()) chose_course_page.pop_back();
    int i = 0;
    int cur_num = 0;
    while (cur_course){
        all_course_id.push_back(cur_course->data.ID + " - " + cur_course->data.course_name);
        cur_course = cur_course->pNext;
        cur_num++;
    }
    while (i < cur_num){
        ButtonLibrary CurPage;
        int cnt = 4;
        int UpperBound = 205;
        while (cnt && i < cur_num){
            CurCourse.SetFunction([=](){
                ID_chosen_course = i;
                is_ViewCourse3 = false;
                is_ViewDetailCourse = true;
                ProcessDetailCourse();
            });
            CurCourse.ChangeText(all_course_id[i]);
            CurCourse.SetDetail(Non,24,300,UpperBound,600,40);
            CurPage.addButton(CurCourse);
            cnt--;
            UpperBound+=100;
            i++;
        }
        chose_course_page.push_back(CurPage);
    }
    chose_course_curpage = 0;
}

void ProcessListOfSemester(Button Back){
    DLLNode<Year> *Cur = ListYear.Head;
    while (Cur){
        if (Cur->data.IDyear == all_year_id[ID_chosen_year]) break;
        Cur = Cur->pNext;
    }
    DLLNode<Semester> *cur = Cur->data.sem_list.Head;
    ChoseSemester.ResetSize();
    while (all_semester_id.getSize()) all_semester_id.pop_back();
    int UpperBound = 200;

    ChoseSemester.addButton(Back);
    int i = 0;
    while (cur){
        all_semester_id.push_back(cur->data.IDsemester);
        string Term = "Semester " + to_string(cur->data.IDsemester);
        CurSemester.ChangeText(Term);
        CurSemester.SetDetail(Non,24,475,UpperBound,250,50);
        CurSemester.SetFunction([=](){
            ID_chosen_semester = cur->data.IDsemester;
            is_ViewCourse2 = false;
            is_ViewCourse3 = true;
            ProcessListOfCourse();
        });
        UpperBound+=125;
        ChoseSemester.addButton(CurSemester);
        cur = cur->pNext;
        i++;
    }
}

void ProcessListOfStudentInCourse(){
    DLLNode<Student> *head = CurChosenCourse->data.stu_list.Head;
    while (all_student_name.getSize()) all_student_name.pop_back();
    while (chose_student_page.getSize()) chose_student_page.pop_back();
    int cur_num = 0;
    while (head){
        ButtonLibrary CurPage;
        int cnt = 4;
        int UpperBound = 205;
        while (cnt && head){
            all_student_name.push_back(head->data.ID + " - " + head->data.FirstName + " " + head->data.LastName);
            CurStu.SetFunction([=](){
                CurChoseStudent = head;
                is_ViewStudentCourse = false;
                is_ChoseAction = true;
            });
            CurStu.ChangeText(all_student_name[cur_num]);
            CurStu.SetDetail(Non,24,400,UpperBound,400,40);
            CurPage.addButton(CurStu);
            cnt--;
            cur_num++;
            UpperBound+=100;
            head = head->pNext;
        }
        chose_student_page.push_back(CurPage);
    }
    chose_student_curpage = 0;
}

string GetDir(sf::RenderWindow &window, bool &is_backed){
    TextField Dir_Input(_Font,24,sf::Color::Black,150,375,900,50,true);
    sf::Text Manual;
    setText(Manual,"Input directory",_Font,24,150,200,sf::Color::Black);
    bool stop = false;
    bool is_return = true;
    Button OK(Non,24,550,500,100,50,"OK",[&](){
        stop = true;
    });
    Button Back(Non,20,105,100,70,50,"Back",[&](){
        stop = true;
        is_return = false;
        is_backed = true;
    });
    ButtonLibrary AllButtons;
    AllButtons.addButton(OK);
    AllButtons.addButton(Back);
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (stop) break;
            Dir_Input.handleEvent(event);
            CheckLogOut.handleEvent(event);
            AllButtons.handleEvent(event);
            if (event.type==sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter){
                stop = true;
                break;
            }
            if (event.type==sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(background);
        window.draw(welcome);
        window.draw(author);
        CheckLogOut.draw(window);
        window.draw(default_year);
        window.draw(default_semester);
        window.draw(Manual);
        if (stop) break;
        Dir_Input.draw(window);
        AllButtons.draw(window);
        window.display();
    }
    if (is_return) return Dir_Input.getText();
    else return "";
}

void ViewScore(sf::RenderWindow &window){
    TextBox ID(175,200,150,50,_Font,"ID",23);
    TextBox FullName(325,200,150,50,_Font,"First name",23);
    TextBox LastName(475,200,150,50,_Font,"Last name",23);
    TextBox OtherMark(625,200,100,50,_Font,"Other",23);
    TextBox MidMark(725,200,100,50,_Font,"Mid",23);
    TextBox FinMark(825,200,100,50,_Font,"Final",23);
    TextBox TotMark(925,200,100,50,_Font,"Total",23);
    bool stop = false;
    Button Back(Non,20,105,100,70,50,"Back",[&](){
        stop = true;
    });
    Vector<TextBox> Title;
    Title.push_back(ID);
    Title.push_back(FullName);
    Title.push_back(LastName);
    Title.push_back(OtherMark);
    Title.push_back(MidMark);
    Title.push_back(FinMark);
    Title.push_back(TotMark);

    //Process the scoreboard
    int npage = 0;
    vector<vector<TextBox>> page;
    DLLNode<Score> *Cur = CurChosenCourse->data.score_list.Head;
    int Maxsize = 0;
    vector<TextBox> Curpage;
    TextBox cur_id;
    TextBox cur_fn;
    TextBox cur_ln;
    TextBox cur_om;
    TextBox cur_mt;
    TextBox cur_ft;
    TextBox cur_tot;
    while(Cur){
        int cnt = 7;
        int UpperBound = 250;
        while (Curpage.size()) Curpage.pop_back();
        while(Cur && cnt>0){
            cur_id.SetDetail(175,UpperBound,150,50,_Font,Cur->data.stu_id,23);
            cur_fn.SetDetail(325,UpperBound,150,50,_Font,Cur->data.first_name,23);
            cur_ln.SetDetail(475,UpperBound,150,50,_Font,Cur->data.last_name,23);
            cur_om.SetDetail(625,UpperBound,100,50,_Font,Point(Cur->data.other_mark),23);
            cur_mt.SetDetail(725,UpperBound,100,50,_Font,Point(Cur->data.mid_mark),23);
            cur_ft.SetDetail(825,UpperBound,100,50,_Font,Point(Cur->data.fin_mark),23);
            cur_tot.SetDetail(925,UpperBound,100,50,_Font,Point(Cur->data.tot_mark),23);
            Curpage.push_back(cur_id);
            Curpage.push_back(cur_fn);
            Curpage.push_back(cur_ln);
            Curpage.push_back(cur_om);
            Curpage.push_back(cur_mt);
            Curpage.push_back(cur_ft);
            Curpage.push_back(cur_tot);
            cnt--;
            Cur = Cur->pNext;
            UpperBound+=50;
        }
        page.push_back(Curpage);
        Maxsize++;
    }
    Button NextPage(cursor,20,950,650,150,50,"Next Page",[&](){
        if (npage < Maxsize-1) npage++;
    });
    Button BackPage(cursor,20,100,650,150,50,"Previous Page",[&](){
        if (npage > 0) npage--;
    });

    ButtonLibrary AllButtons;
    AllButtons.addButton(Back);
    AllButtons.addButton(BackPage);
    AllButtons.addButton(NextPage);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            AllButtons.handleEvent(event);
            CheckLogOut.handleEvent(event);
            if (event.type==sf::Event::Closed){
                window.close();
            }
            if (stop) return;
        }
        window.clear();
        window.draw(background);
        window.draw(welcome);
        window.draw(author);
        CheckLogOut.draw(window);
        window.draw(default_year);
        window.draw(default_semester);
        if (stop) return;
        for(int i=0; i<Title.getSize(); i++) Title[i].draw(window);
        AllButtons.draw(window);
        if (page.size()){
            for(int i=0; i< page[npage].size(); i++) page[npage][i].draw(window);
        }
        window.display();
    }
}

void UpdateScoreWindow(sf::RenderWindow &window){
    sf::Text ID;
    setText(ID,"ID: " + CurChoseStudent->data.ID,_Font,24,200,150,sf::Color::Black);
    sf::Text Name;
    setText(Name,"Full name: " + CurChoseStudent->data.FirstName + " " + CurChoseStudent->data.LastName,_Font,24,200,200,sf::Color::Black);
    bool stop = false;
    Button Back(Non,20,105,100,70,50,"Back",[&](){
        stop = true;
    });
    DLLNode<Score> *Cur = CurChosenCourse->data.score_list.Head;
    while (Cur){
        if (Cur->data.stu_id == CurChoseStudent->data.ID) break;
        Cur = Cur->pNext;
    }
    TextField OtherMark(_Font,24,sf::Color::Black,400,300,200,50,true);
    sf::Text othermark; setText(othermark,"Other mark",_Font,24,200,310,sf::Color::Black);
    TextField MidMark(_Font,24,sf::Color::Black,400,400,200,50,true);
    sf::Text midmark; setText(midmark,"Midterm mark",_Font,24,200,410,sf::Color::Black);
    TextField FinMark(_Font,24,sf::Color::Black,400,500,200,50,true);
    sf::Text finmark; setText(finmark,"Final mark",_Font,24,200,510,sf::Color::Black);
    TextField TotMark(_Font,24,sf::Color::Black,400,600,200,50,true);
    sf::Text totmark; setText(totmark,"Total mark",_Font,24,200,610,sf::Color::Black);
    if (Cur) {
        OtherMark.SetIniStr(Point(Cur->data.other_mark));
        MidMark.SetIniStr(Point(Cur->data.mid_mark));
        FinMark.SetIniStr(Point(Cur->data.fin_mark));
        TotMark.SetIniStr(Point(Cur->data.tot_mark));
    }
    Button OK(Non,24,700,460,200,50,"OK",[&](){
        Student *tmp;
        FindStudent(tmp,CurChoseStudent->data.ID,ListYear);
        UpdateStudentResult(tmp,CurChosenCourse->data,Cur->data,-1);
        UpdateScoreOther(Cur,OtherMark.getText());
        UpdateScoreMidterm(Cur,MidMark.getText());
        UpdateScoreFinal(Cur,FinMark.getText());
        UpdateScoreTotal(Cur,TotMark.getText());
        UpdateStudentResult(tmp,CurChosenCourse->data,Cur->data,1);
        stop = true;
        TextBox Info(300,350,600,100,_Font,"Update successfully",30);
        Info.draw(window);
        window.display();
        sf::sleep(sf::seconds(2));
        window.clear();
        window.display();
    });

    ButtonLibrary AllButtons;
    AllButtons.addButton(Back);
    AllButtons.addButton(OK);
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            AllButtons.handleEvent(event);
            CheckLogOut.handleEvent(event);
            OtherMark.handleEvent(event);
            MidMark.handleEvent(event);
            FinMark.handleEvent(event);
            TotMark.handleEvent(event);
            if (event.type==sf::Event::Closed){
                window.close();
            }
            if (event.type==sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter){
                UpdateScoreOther(Cur,OtherMark.getText());
                UpdateScoreMidterm(Cur,MidMark.getText());
                UpdateScoreFinal(Cur,FinMark.getText());
                UpdateScoreTotal(Cur,TotMark.getText());
                stop = true;
                TextBox Info(300,350,600,100,_Font,"Update successfully",30);
                Info.draw(window);
                window.display();
                sf::sleep(sf::seconds(2));
                window.clear();
                window.display();
            }
            if (stop) return;
        }
        window.clear();
        window.draw(background);
        window.draw(welcome);
        window.draw(author);
        window.draw(ID);
        window.draw(Name);
        CheckLogOut.draw(window);
        window.draw(default_year);
        window.draw(default_semester);
        if (stop) return;
        OtherMark.draw(window); window.draw(othermark);
        MidMark.draw(window); window.draw(midmark);
        FinMark.draw(window); window.draw(finmark);
        TotMark.draw(window); window.draw(totmark);
        AllButtons.draw(window);
        window.display();
    }
}

//Main function
void AcademicScreen(sf::RenderWindow &window, User Who, bool &logout){
    importData("Information/SystemData",ListYear);


    if (ListYear.Head) setText(default_year,"Current year: " + to_string(ListYear.Head->data.IDyear),_Font,20,50,50,sf::Color::Black);
    if (ListYear.Head && ListYear.Head->data.sem_list.Head) setText(default_semester,"Current semester: " + to_string(ListYear.Head->data.sem_list.Head->data.IDsemester),_Font,20,300,50,sf::Color::Black);
    //set text for add course page
    setText(addcourse_id,"Course ID",_Font,20,100,210,sf::Color::Black);
    setText(addcourse_name,"Course name",_Font,20,100,310,sf::Color::Black);
    setText(addcourse_class,"Class name",_Font,20,100,410,sf::Color::Black);
    setText(addcourse_teacher,"Teacher Name",_Font,20,100,510,sf::Color::Black);
    setText(addcourse_credits,"Credits",_Font,20,100,210,sf::Color::Black);
    setText(addcourse_maxstu,"Max students",_Font,20,100,310,sf::Color::Black);
    setText(addcourse_dayweek,"Day of week",_Font,20,100,410,sf::Color::Black);
    setText(addcourse_sess,"Session",_Font,20,100,510,sf::Color::Black);

    //set text for add student
    setText(addstudent_ID,"ID",_Font,24,100,210,sf::Color::Black);
    setText(addstudent_FirstName,"First Name",_Font,25,100,280,sf::Color::Black);
    setText(addstudent_LastName,"Last Name",_Font,25,100,350,sf::Color::Black);
    setText(addstudent_Gender,"Gender (1. Male, 2. Female, 3. Other)",_Font,25,100,420,sf::Color::Black);
    setText(addstudent_Dob,"Date of Birth",_Font,25,100,490,sf::Color::Black);
    setText(addstudent_Social,"Social ID",_Font,25,100,560,sf::Color::Black);

    //set text for add from csv
    setText(addstudent_folderpath,"Folder path of CSV",_Font,20,100,385,sf::Color::Black);
    setText(addstudent_manual,"Using the / instead of \\ , for example: D:/folder_1/file_name.CSV",_Font,24,100,250,sf::Color::Black);

    //set text for add class page
    setText(addclass_classname,"Class name",_Font,20,100,360,sf::Color::Black);

    //set text for change pass
    setText(Oldpass,"Old password",_Font,24,200,300,sf::Color::Black);
    setText(Newpass,"New password",_Font,24,200,400,sf::Color::Black);

    //preprocess
    //Set all scene to default
    is_MainMenu = true;
    curpage = 0;

    is_ChangePass=  false;
    is_ViewCourse2 = false;
    is_ViewCourse3 = false;
    is_ViewClass = false;
    is_ViewClass2 = false;
    is_ViewClass3 = false;
    is_ViewScoreOfClass = false;
    is_ViewCourse = false;
    is_ViewDetailCourse = false;
    is_ViewStudentCourse = false;
    is_ChoseAction = false;
    is_AddSchoolYear = false;
    is_AddClass = false;
    is_AddCourse = false;
    is_AddSemester = false;
    is_AddStudent = false;
    is_AddIndividual = false;
    is_AddFromCSV = false;
    is_ChoseClass = false;
    is_AddStudentToCourse = false;

    //Set Back ground and welcome text
    SetBackGround();
    SetwelcomeText(Who);

    //Set text for add school year
    setText(addschoolyear_text,"Enter id school year", _Font, 24, 200, 300, sf::Color::Black);

    //Set text for add semester
    setText(addsem_box,"Semester ID:",_Font,24,100,310,sf::Color::Black);
    setText(addsem_stday,"Start day:",_Font,24,100,410,sf::Color::Black);
    setText(addsem_enday,"End day:",_Font,24,100,510,sf::Color::Black);

    //Button
    Button addschoolyear_back(Non,20,105,100,70,50,"Back",[&](){
        is_MainMenu = true;
        is_ViewClass = false;
        is_AddSchoolYear = false;
        is_AddClass = false;
        is_AddSemester = false;
        is_AddCourse = false;
        is_AddStudent = false;
        is_ViewCourse = false;
        curpage = 0;
    });
    Button addschoolyear_okbutton(Non,24,550,600,100,50,"OK",[&](){
        HandleAddSchoolYear(window);
    });
    Button Back_From_Chose_Semester(Non,20,105,100,70,50,"Back",[=](){
        is_ViewCourse2 = false;
        is_ViewCourse = true;
    });
    Button BackPage(cursor,20,100,600,150,50,"Previous Page",[=](){
        if (curpage > 0) curpage--;
        if (chose_class_curpage > 0) chose_class_curpage--;
        if (chose_year_curpage > 0) chose_year_curpage--;
        if (chose_student_curpage > 0) chose_student_curpage--;
        if (chose_course_curpage > 0) chose_course_curpage--;
        if (cur_score_page > 0) cur_score_page--;
    });
    Button NextPage(cursor,20,950,600,150,50,"Next Page",[=](){
        if (curpage < 1) curpage++;
        if (chose_class_curpage < chose_class_page.getSize()-1) chose_class_curpage++;
        if (chose_year_curpage < chose_year_page.getSize()-1) chose_year_curpage++;
        if (chose_student_curpage < chose_student_page.getSize()-1) chose_student_curpage++;
        if (chose_course_curpage < chose_course_page.getSize()-1) chose_course_curpage++;
        if (cur_score_page < ScorePage.size()-1) cur_score_page++;
    });
    Button addsemester_okbutton(Non,24,550,700,100,50,"OK",[&](){
        HandleAddSemester(window);
    });
    Button Logout(Non,20,1100,720,80,50,"Logout",[&](){
        logout = true;
        window.close();
    });
    Button ViewClass(cursor,24,490,150,220,50,"View Class",[&](){
        is_ViewClass = true;
        is_MainMenu = false;
        DLLNode<Year> *Cur = ListYear.Head;
        while (all_year_id.getSize()) all_year_id.pop_back();
        while (chose_year_page.getSize()) chose_year_page.pop_back();
        int cur_num = 0;
        while (Cur){
            all_year_id.push_back(Cur->data.IDyear);
            Cur = Cur->pNext;
            cur_num++;
        }
        int i = 0;
        while (i < cur_num){
            ButtonLibrary CurPage;
            int cnt = 4;
            int UpperBound = 205;
            while (cnt && i < cur_num){
                CurClass.SetFunction([=](){
                    ID_chosen_year = i;
                    is_ViewClass = false;
                    is_ViewClass2 = true;
                    ProcessListOfClass();
                });
                string TEMP = to_string(all_year_id[i]);
                CurClass.ChangeText(TEMP);
                CurClass.SetDetail(Non,24,400,UpperBound,400,40);
                CurPage.addButton(CurClass);
                cnt--;
                UpperBound += 100;
                i++;
            }
            chose_year_page.push_back(CurPage);
        }
        chose_year_curpage = 0;
    });
    Button ViewCourse(cursor,24,490,250,220,50,"View Course",[&](){
        is_MainMenu = false;
        is_ViewCourse = true;
        DLLNode<Year> *Cur = ListYear.Head;
        while (all_year_id.getSize()) all_year_id.pop_back();
        while (chose_year_page.getSize()) chose_year_page.pop_back();
        int cur_num = 0;
        while (Cur){
            all_year_id.push_back(Cur->data.IDyear);
            Cur = Cur->pNext;
            cur_num++;
        }
        int i = 0;
        while (i < cur_num){
            ButtonLibrary CurPage;
            int cnt = 4;
            int UpperBound = 205;
            while (cnt && i < cur_num){
                CurClass.SetFunction([=](){
                    ID_chosen_year = i;
                    is_ViewCourse = false;
                    is_ViewCourse2 = true;
                    ProcessListOfSemester(Back_From_Chose_Semester);
                });
                string TEMP = to_string(all_year_id[i]);
                CurClass.ChangeText(TEMP);
                CurClass.SetDetail(Non,24,400,UpperBound,400,40);
                CurPage.addButton(CurClass);
                cnt--;
                UpperBound += 100;
                i++;
            }
            chose_year_page.push_back(CurPage);
        }
        chose_year_curpage = 0;
    });
    Button AddSchoolYear(cursor,24,490,350,220,50,"Add school year",[&](){
        is_MainMenu = false;
        is_AddSchoolYear = true;
        addschoolyear_textfield.clear_str();
    });
    Button AddClasses(cursor,24,490,450,220,50,"Add class",[&](){
        if (ListYear.Head){
            is_AddClass = true;
            is_MainMenu = false;
        }
        else{
            TextBox Info(300,325,600,150,_Font,"Please add year",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
    });
    Button AddCourses(cursor,24,490,150,220,50,"Add course",[&](){
        if (ListYear.Head && ListYear.Head->data.sem_list.Head){
            is_AddCourse = true;
            is_MainMenu = false;
            ID_input.clear_str();
            Name_input.clear_str();
            Class_input.clear_str();
            Teacher_input.clear_str();
            Session_input.clear_str();
            DayWeek_input.clear_str();
            Credits_input.clear_str(); Credits_input.SetIniStr("4");
            MaxStudent_input.clear_str(); MaxStudent_input.SetIniStr("50");
            setText(addcourse_id,"Course ID",_Font,20,100,210,sf::Color::Black);
            setText(addcourse_name,"Course name",_Font,20,100,310,sf::Color::Black);
            setText(addcourse_class,"Class name",_Font,20,100,410,sf::Color::Black);
            setText(addcourse_teacher,"Teacher Name",_Font,20,100,510,sf::Color::Black);
            setText(addcourse_credits,"Credits",_Font,20,100,210,sf::Color::Black);
            setText(addcourse_maxstu,"Max students",_Font,20,100,310,sf::Color::Black);
            setText(addcourse_dayweek,"Day of week",_Font,20,100,410,sf::Color::Black);
            setText(addcourse_sess,"Session",_Font,20,100,510,sf::Color::Black);
            cur_addcourse_page = 0;
        }
        else{
            TextBox Info(300,325,600,150,_Font,"Please add year or semester first",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
    });
    Button AddSemester(cursor,24,490,550,220,50,"Add semester",[&](){
        if (ListYear.Head){
            is_AddSemester = true;
            is_MainMenu = false;
        }
        else{
            TextBox Info(300,325,600,150,_Font,"Please add year",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
    });
    Button OK1(Non,24,550,600,100,50,"OK",[&](){
        HandleOK1(window);
    });
    Button OK2(Non,24,550,600,100,50,"OK",[&](){
        HandleOK2(window);
    });
    Button addclass_okbutton(Non,24,550,600,100,50,"OK",[&](){
        HandleAddClass(window);
    });
    Button Back_From_Chose_Class(Non,20,105,100,70,50,"Back",[&](){
        is_ChoseClass = false;
        is_MainMenu = true;
    });
    Button AddNewStudent(cursor,24,435,250,330,50,"Add student to class",[&](){
        if (ListYear.Head && ListYear.Head->data.sem_list.Head){
            DLLNode <Class> *Cur = ListYear.Head->data.classes_list.Head;
            while (all_class_name.getSize()) all_class_name.pop_back();
            while (chose_class_page.getSize()) chose_class_page.pop_back();
            int cur_num = 0;
            string Temp;
            while (Cur){
                Temp = Cur->data.class_name;
                all_class_name.push_back(Temp);
                Cur = Cur->pNext;
                cur_num++;
            }
            int i = 0;
            while (i < cur_num){
                ButtonLibrary CurPage;
                int cnt = 4;
                int UpperBound = 205;
                while (cnt && i < cur_num){
                    CurClass.SetFunction([=](){
                        if (!is_MainMenu){
                            ID_chosen_class = i;
                            is_ChoseClass = false;
                            is_AddStudent = true;
                        }
                    });
                    CurClass.ChangeText(all_class_name[i]);
                    CurClass.SetDetail(Non,24,400,UpperBound,400,40);
                    CurPage.addButton(CurClass);
                    cnt--;
                    UpperBound += 100;
                    i++;
                }
                CurPage.addButton(BackPage);
                CurPage.addButton(NextPage);
                chose_class_page.push_back(CurPage);
            }
            is_MainMenu = false;
            is_ChoseClass = true;
            is_AddIndividual = false;
            chose_class_curpage = 0;
        }
        else{
            TextBox Info(300,325,600,150,_Font,"Please add year or semester first",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
    });
    Button AddIndividualStudent(cursor,24,490,300,220,50,"Add a student",[&](){
        is_AddIndividual = true;
        is_AddStudent = false;
        addstudent_ID_input.clear_str();
        addstudent_FirstName_input.clear_str();
        addstudent_LastName_input.clear_str();
        addstudent_Dob_input.clear_str();
        addstudent_Gender_input.clear_str();
        addstudent_Social_input.clear_str();
        setText(addstudent_ID,"ID",_Font,24,100,210,sf::Color::Black);
        setText(addstudent_FirstName,"First Name",_Font,25,100,280,sf::Color::Black);
        setText(addstudent_LastName,"Last Name",_Font,25,100,350,sf::Color::Black);
        setText(addstudent_Gender,"Gender (1. Male, 2. Female, 3. Other)",_Font,25,100,420,sf::Color::Black);
        setText(addstudent_Dob,"Date of Birth",_Font,25,100,490,sf::Color::Black);
        setText(addstudent_Social,"Social ID",_Font,25,100,560,sf::Color::Black);
    });
    Button AddCSVStudent(cursor,24,435,410,330,50,"Add student from CSV file",[&](){
        is_AddFromCSV = true;
        addstudent_folderpath_input.clear_str();
        is_AddStudent = false;
    });
    Button addstudent_okbutton(Non,24,550,700,100,50,"OK",[&](){
        HandleAddIndi(window);
    });
    Button addstudentcsv_okbutton(Non,24,550,700,100,50,"OK",[&](){
        HandleAddCSV(window);
    });
    Button Back_To_Chose_Year(Non,20,105,100,70,50,"Back",[&](){
        is_ViewClass2 = false;
        is_ViewClass = true;
    });
    Button Back_To_Chose_Class(Non,20,105,100,70,50,"Back",[&](){
        is_ViewClass3 = false;
        is_ViewClass2 = true;
    });
    Button AddNewStudentToCourse(cursor,24,435,350,330,50,"Add student to course",[&](){
        if (ListYear.Head && ListYear.Head->data.sem_list.Head){
            is_MainMenu = false;
            is_AddStudentToCourse = true;
            DLLNode <Course> *Cur = ListYear.Head->data.sem_list.Head->data.course_list.Head;
            while (all_course_id.getSize()) all_course_id.pop_back();
            while (chose_course_page.getSize()) chose_course_page.pop_back();
            int i = 0;
            int cur_num = 0;
            while (Cur){
                all_course_id.push_back(Cur->data.ID + " - " + Cur->data.course_name);
                Cur = Cur->pNext;
                cur_num++;
            }
            while (i < cur_num){
                ButtonLibrary CurPage;
                int cnt = 4;
                int UpperBound = 205;
                while (cnt && i < cur_num){
                    CurCourse.SetFunction([=](){
                        ID_chosen_course = i;
                        is_AddStudent = true;
                    });
                    CurCourse.ChangeText(all_course_id[i]);
                    CurCourse.SetDetail(Non,24,300,UpperBound,600,40);
                    CurPage.addButton(CurCourse);
                    cnt--;
                    UpperBound+=100;
                    i++;
                }
                chose_course_page.push_back(CurPage);
            }
            chose_course_curpage = 0;
        }
        else{
            TextBox Info(300,325,600,150,_Font,"Please add year or semester first",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
    });
    Button Back_From_Chose_Course_To_Main_Menu(Non,20,105,100,70,50,"Back",[&](){
        is_AddStudentToCourse = false;
        is_MainMenu = true;
    });
    Button Back_From_View_Course(Non,20,105,100,70,50,"Back",[&](){
        is_ViewCourse3 = false;
        is_ViewCourse2 = true;
    });
    Button Back_From_View_Detail(Non,20,105,100,70,50,"Back",[&](){
        is_ViewDetailCourse = false;
        is_ViewCourse3 = true;
    });
    Button Save_Change_Course(Non,24,550,630,100,50,"OK",[&](){
        string old_ID = CurChosenCourse->data.ID;
        string old_class_name = CurChosenCourse->data.class_name;
        string get_ID = detail_ID.getText(); UpdateCourseID(CurChosenCourse->data,get_ID);
        string get_course_name = detail_course_name.getText();  UpdateCourseName(CurChosenCourse->data,get_course_name);
        string get_class_name = detail_class_name.getText(); UpdateClassName(CurChosenCourse->data,get_class_name);
        if ((get_class_name != old_class_name) || (get_ID != old_ID)) RemoveFolderCourse("Information/SystemData",ListYear.Head->data.IDyear,
                               ListYear.Head->data.sem_list.Head->data.IDsemester,
                               old_ID,
                               old_class_name);
        string get_teacher_name = detail_teacher_name.getText(); UpdateCourseTeacher(CurChosenCourse->data,get_teacher_name);
        UpdateCourseCredits_Num(CurChosenCourse->data,stoi(detail_credits_num.getText()));
        UpdateCourseMax_Students(CurChosenCourse->data,stoi(detail_max_students.getText()));
        UpdateDay_Of_Week(CurChosenCourse->data,detail_day_of_week.getText());
        UpdateSession(CurChosenCourse->data,detail_session.getText());
        TextBox Info(400,325,400,150,_Font,"Saved successfully",30);
        Info.draw(window);
        window.display();
        sf::sleep(sf::seconds(2));
        window.clear();
        window.display();
        is_MainMenu = true;
        is_ViewDetailCourse = false;
    });
    Button Delete_Course(Non,24,120,630,200,50,"Delete course",[&](){
        bool ok = true;
        ok &= (ListYear.Head->data.IDyear == all_year_id[ID_chosen_year]);
        ok &= (ListYear.Head->data.sem_list.Head->data.IDsemester ==  ID_chosen_semester);
        if (ok) {
            DLLNode<Course> *Cur = ListYear.Head->data.sem_list.Head->data.course_list.Head;
            RemoveFolderCourse("Information/SystemData",ListYear.Head->data.IDyear,
                               ListYear.Head->data.sem_list.Head->data.IDsemester,
                               Cur->data.ID,
                               Cur->data.class_name);
            ListYear.Head->data.sem_list.Head->data.course_list.remove(CurChosenCourse->data);
            TextBox Info(400,325,400,150,_Font,"Deleted successfully",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
            is_MainMenu = true;
            is_ViewDetailCourse = false;
        }
        else{
            TextBox Info(400,325,400,150,_Font,"Cannot delete this course",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
    });
    Button View_List_Of_Students_In_Course(Non,24,880,630,200,50,"Students list",[&](){
        is_ViewDetailCourse = false;
        is_ViewStudentCourse = true;
        ProcessListOfStudentInCourse();
    });
    Button Back_To_View_Detail(Non,20,105,100,70,50,"Back",[&](){
        is_ViewStudentCourse = false;
        is_ViewDetailCourse = true;
    });
    Button ViewScoreBoard(cursor,24,900,100,200,50,"View Scoreboard",[&](){
        ViewScore(window);
    });
    Button UpdateScoreBoard(cursor,24,450,200,300,50,"Update Scoreboard",[&](){
        UpdateScoreWindow(window);
    });
    Button DeleteStudent(cursor,24,450,400,300,50,"Delete Student",[&](){
        DLLNode<Score> *Cur = CurChosenCourse->data.score_list.Head;
        while (Cur){
            if (Cur->data.stu_id == CurChoseStudent->data.ID) break;
            Cur = Cur->pNext;
        }
        CurChosenCourse->data.score_list.remove(Cur->data);
        CurChosenCourse->data.stu_list.remove(CurChoseStudent->data);
        is_ChoseAction = false;
        ProcessListOfStudentInCourse();
        is_ViewStudentCourse = true;
    });
    Button Back_To_View_Student(Non,20,105,100,70,50,"Back",[&](){
        is_ViewStudentCourse = true;
        is_ChoseAction = false;
    });
    Button ExportStudentCourseToCSV(Non,24,350,600,200,50,"Export scoreboard",[&](){
        bool is_backed = false;
        string filename = GetDir(window,is_backed);
        bool export_success = false;
        if (filename.size()) export_success = ExportToCSV(CurChosenCourse->data,filename);
        if (export_success){
            TextBox Info(300,325,600,150,_Font,"Export successfully",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
        else if (!is_backed){
            TextBox Info(300,325,600,150,_Font,"Invalid folder path",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
    });
    Button ImportScore(Non,24,650,600,200,50,"Import scoreboard",[&](){
        bool is_backed = false;
        string filename = GetDir(window,is_backed);
        DLinkedList<Score> NewScore;
        bool is_success = false;
        if (filename.size()) is_success = ImpScoreCSV(filename,ListYear,ListYear.Head->data.IDyear,CurChosenCourse->data,CurChosenCourse->data.score_list.Head,NewScore);
        if (is_success){
            TextBox Info(300,325,600,150,_Font,"Import successfully",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
        else if (!is_backed){
            TextBox Info(300,325,600,150,_Font,"Invalid folder path",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
    });
    Button Back_To_View_Class3(Non,20,105,100,70,50,"Back",[&](){
        is_ViewScoreOfClass = false;
        is_ViewClass3 = true;
    });
    Button ChangePassword(cursor,24,490,450,220,50,"Change password",[&](){
        is_MainMenu = false;
        is_ChangePass = true;
    });
    Button Back_From_Change_Pass(Non,20,105,100,70,50,"Back",[&](){
        is_ChangePass = false;
        is_MainMenu = true;
    });
    Button OK_change_pass(Non,24,575,600,50,50,"OK",[&](){
        bool is_change = ChangeUserPass(Who.ID,oldpass.getText(),newpass.getText());
        if (is_change){
            TextBox Info(300,325,600,150,_Font,"Change successfully",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
        else{
            TextBox Info(300,325,600,150,_Font,"Incorrect old password",30);
            Info.draw(window);
            window.display();
            sf::sleep(sf::seconds(2));
            window.clear();
            window.display();
        }
    });
    Button Exit(cursor,24,490,550,220,50,"Exit",[&](){
        window.close();
    });

    MainMenu.addButton(ViewClass);
    MainMenu.addButton(ViewCourse);
    MainMenu.addButton(AddSchoolYear);
    MainMenu.addButton(AddClasses);
    MainMenu.addButton(AddSemester);

    MainMenu2.addButton(AddCourses);
    MainMenu2.addButton(AddNewStudent);
    MainMenu2.addButton(AddNewStudentToCourse);
    MainMenu2.addButton(ChangePassword);
    MainMenu2.addButton(Exit);

    CheckLogOut.addButton(Logout);

    MainMenu.addButton(BackPage);
    MainMenu.addButton(NextPage);

    MainMenu2.addButton(BackPage);
    MainMenu2.addButton(NextPage);

    //view course
    viewcourse_buttons.addButton(addschoolyear_back);
    viewcourse_buttons.addButton(BackPage);
    viewcourse_buttons.addButton(NextPage);
    viewcourse3_buttons.addButton(Back_From_View_Course);
    viewcourse3_buttons.addButton(NextPage);
    viewcourse3_buttons.addButton(BackPage);
    detail_vecbutton.addButton(Back_From_View_Detail);
    detail_vecbutton.addButton(Save_Change_Course);
    detail_vecbutton.addButton(Delete_Course);
    detail_vecbutton.addButton(View_List_Of_Students_In_Course);
    detail_vecbutton.addButton(ViewScoreBoard);
    viewstudent_vecbutton.addButton(Back_To_View_Detail);
    viewstudent_vecbutton.addButton(ExportStudentCourseToCSV);
    viewstudent_vecbutton.addButton(ImportScore);
    viewstudent_vecbutton.addButton(BackPage);
    viewstudent_vecbutton.addButton(NextPage);
    choseaction_vecbutton.addButton(UpdateScoreBoard);
    choseaction_vecbutton.addButton(DeleteStudent);
    choseaction_vecbutton.addButton(Back_To_View_Student);


    //view class
    viewclass_vecbutton.addButton(addschoolyear_back);
    viewclass_vecbutton.addButton(BackPage);
    viewclass_vecbutton.addButton(NextPage);

    //view class 2
    viewclass2_vecbutton.addButton(BackPage);
    viewclass2_vecbutton.addButton(NextPage);
    viewclass2_vecbutton.addButton(Back_To_Chose_Year);

    //view class 3
    viewclass3_vecbutton.addButton(BackPage);
    viewclass3_vecbutton.addButton(NextPage);
    viewclass3_vecbutton.addButton(Back_To_Chose_Class);

    //view score of class
    viewscoreboard_vecbutton.addButton(Back_To_View_Class3);
    viewscoreboard_vecbutton.addButton(NextPage);
    viewscoreboard_vecbutton.addButton(BackPage);

    //add school year
    addschoolyear_vecbutton.addButton(addschoolyear_okbutton);
    addschoolyear_vecbutton.addButton(addschoolyear_back);

    //add class
    addclass_vecbutton.addButton(addschoolyear_back);
    addclass_vecbutton.addButton(addclass_okbutton);


    //add semester
    addsemester_vecbutton.addButton(addschoolyear_back);
    addsemester_vecbutton.addButton(addsemester_okbutton);
    Page.push_back(MainMenu);
    Page.push_back(MainMenu2);

    //add course
    p1.addButton(OK1);
    p2.addButton(OK2);
    addcourse_vecbutton.addButton(addschoolyear_back);

    //add student
    Button Back_from_add(Non,20,105,100,70,50,"Back",[&](){
        is_AddStudent = true;
        is_AddIndividual = false;
        is_AddFromCSV = false;
    });
    Button Back_to_Chose(Non,20,105,100,70,50,"Back",[&](){
        is_AddStudent = false;
        if (!is_AddStudentToCourse) is_ChoseClass = true;
    });
    choseclass_vecbutton.addButton(Back_From_Chose_Class);
    addstudent_vecbutton.addButton(Back_to_Chose);
    addstudent_vecbutton.addButton(AddIndividualStudent);
    addstudent_vecbutton.addButton(AddCSVStudent);
    addstudent_csv.addButton(Back_from_add);
    addstudent_csv.addButton(addstudentcsv_okbutton);
    addstudent_indi.addButton(Back_from_add);
    //add individual
    addindi_vecbutton.addButton(addstudent_okbutton);

    //add student to course
    chosecourse_vecbutton.addButton(Back_From_Chose_Course_To_Main_Menu);
    chosecourse_vecbutton.addButton(NextPage);
    chosecourse_vecbutton.addButton(BackPage);

    //change pass
    changepass_vecbutton.addButton(Back_From_Change_Pass);
    changepass_vecbutton.addButton(OK_change_pass);


    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            HandleEvent(event,window);
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        DrawWindow(window);
    }
    Save_Data("Information/SystemData",ListYear);
}
