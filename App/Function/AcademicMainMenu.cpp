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
#include <vector>

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
bool is_ViewCourse;
bool is_AddSchoolYear;
bool is_AddClass;
bool is_AddCourse;
bool is_AddSemester;
bool is_AddStudent;
bool is_AddIndividual;
bool is_AddFromCSV;
bool is_ChoseClass;
Vector<ButtonLibrary> Page;

int curpage = 0;
DLinkedList <Year> ListYear;

//ViewClass
Vector<int> all_year_id;
int ID_chosen_year;
int chose_year_curpage;
Vector<ButtonLibrary> chose_year_page;

//ViewClass2
ButtonLibrary viewclass2_vecbutton;

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
Button CurClass;

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

//OK handle add class
void HandleAddClass(){
    string TEMP = addclass_classname_input.getText();
    Class NC; NC.class_name = TEMP;
    AddClass(ListYear.Head->data,NC);
    addclass_classname_input.clear_str();
    is_MainMenu = true;
    is_AddClass = false;
}

//OK1
void HandleOK1(){
    cur_addcourse_page = 1;
    temp.ID = ID_input.getText();
    temp.class_name = Class_input.getText();
    temp.course_name = Name_input.getText();
    temp.teacher_name = Teacher_input.getText();
}
//OK2
void HandleOK2(){
    string TEMP = Credits_input.getText();
    int crdts = 0; for(int i=0; i<TEMP.size(); i++) crdts = crdts*10 + (TEMP[i]-'0');
    temp.credits_num = crdts;
    temp.day_of_week = DayWeek_input.getText();
    temp.session = Session_input.getText();
    int maxst = 0;
    TEMP = MaxStudent_input.getText();
    for(int i=0; i<TEMP.size(); i++) maxst = maxst*10 + TEMP[i]-'0';
    temp.max_students = maxst;
    is_AddCourse = false;
    is_MainMenu = true;
    Add_A_Course(ListYear.Head->data.sem_list.Head->data,temp);
}
//Handle Add Semester
void HandleAddSemester(){
    string cur_sem_id = IDSem.getText();
    string start_day = StDay.getText();
    string end_day = EnDay.getText();
    Semester NS;
    int ID = 0; for(int i=0; i<cur_sem_id.size(); i++) ID = ID*10+cur_sem_id[i]-'0';
    NS.IDsemester = ID;
    NS.start_day = start_day;
    NS.end_day = end_day;
    if (ID) Add_A_Semester(ListYear.Head->data,NS);
    setText(default_semester,"Current semester: " + to_string(ListYear.Head->data.sem_list.Head->data.IDsemester),_Font,20,300,50,sf::Color::Black);
    IDSem.clear_str();
    StDay.clear_str();
    EnDay.clear_str();
    is_AddSemester = false;
    is_MainMenu = true;
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

    if (is_ViewClass) chose_year_page[chose_year_curpage].draw(window);
    if (is_ViewClass2) {
        if (chose_class_page.getSize()) chose_class_page[chose_class_curpage].draw(window);
        viewclass2_vecbutton.draw(window);
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

    window.display();
}



//Handle event query from the window
void HandleEvent(sf::Event event, sf::RenderWindow &window){
    CheckLogOut.handleEvent(event);

    if (is_MainMenu) Page[curpage].handleEvent(event);

    if (is_ViewClass) chose_year_page[chose_year_curpage].handleEvent(event);

    if (is_ViewClass2){
        if (chose_class_page.getSize()) chose_class_page[chose_class_curpage].handleEvent(event);
        viewclass2_vecbutton.handleEvent(event);
    }

    if (is_AddSchoolYear){
        addschoolyear_vecbutton.handleEvent(event);
        addschoolyear_textfield.handleEvent(event);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter){
            string cur_year_id = addschoolyear_textfield.getText();
            int ID = 0;
            for(int i=0; i<cur_year_id.size(); i++) ID = ID * 10 + cur_year_id[i]-'0';
            Year NY;
            NY.IDyear = ID;
            CreateNewYear(ListYear,NY);
            addschoolyear_textfield.clear_str();
            setText(default_year,"Current year: " + to_string(ListYear.Head->data.IDyear),_Font,20,50,50,sf::Color::Black);
            is_MainMenu = true;
            is_AddSchoolYear = false;
        }
    }

    if (is_AddClass){
        addclass_vecbutton.handleEvent(event);
        addclass_classname_input.handleEvent(event);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) HandleAddClass();
    }

    if (is_AddCourse){
        addcourse_vecbutton.handleEvent(event);
        if (cur_addcourse_page==0){
            ID_input.handleEvent(event);
            Class_input.handleEvent(event);
            Teacher_input.handleEvent(event);
            Name_input.handleEvent(event);
        }
        else{
            MaxStudent_input.handleEvent(event);
            Session_input.handleEvent(event);
            Credits_input.handleEvent(event);
            DayWeek_input.handleEvent(event);
        }
        if (cur_addcourse_page==0) p1.handleEvent(event);
        else p2.handleEvent(event);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && cur_addcourse_page==0) HandleOK1();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && cur_addcourse_page==1) HandleOK2();
    }

    if (is_AddSemester){
        addsemester_vecbutton.handleEvent(event);
        IDSem.handleEvent(event);
        StDay.handleEvent(event);
        EnDay.handleEvent(event);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) HandleAddSemester();
    }


    if (is_ChoseClass && !is_MainMenu){
        if (chose_class_page.getSize()) chose_class_page[chose_class_curpage].handleEvent(event);
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
    }
    else if (is_AddFromCSV && !is_AddStudent){
        addstudent_csv.handleEvent(event);
        addstudent_folderpath_input.handleEvent(event);
    }
    else if (is_AddStudent && !is_ChoseClass){
        addstudent_vecbutton.handleEvent(event);
    }
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
                    //is_ViewClass2 = false;
                    //is_ViewClass3 = true;
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

    //preprocess
    is_MainMenu = true;
    SetBackGround();
    SetwelcomeText(Who);
    setText(addschoolyear_text,"Enter id school year", _Font, 24, 200, 300, sf::Color::Black);
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
    });
    Button addschoolyear_okbutton(Non,24,550,600,100,50,"OK",[&](){
        string cur_year_id = addschoolyear_textfield.getText();
        int ID = 0;
        for(int i=0; i<cur_year_id.size(); i++) ID = ID * 10 + cur_year_id[i]-'0';
        Year NY;
        NY.IDyear = ID;
        CreateNewYear(ListYear,NY);
        addschoolyear_textfield.clear_str();
        setText(default_year,"Current year: " + to_string(ListYear.Head->data.IDyear),_Font,20,50,50,sf::Color::Black);
        is_MainMenu = true;
        is_AddSchoolYear = false;
    });
    Button BackPage(cursor,20,100,600,150,50,"Previous Page",[&](){
        if (curpage > 0) curpage--;
        if (chose_class_curpage > 0) chose_class_curpage--;
        if (chose_year_curpage > 0) chose_year_curpage--;
    });
    Button NextPage(cursor,20,950,600,150,50,"Next Page",[&](){
        if (curpage < 1) curpage++;
        if (chose_class_curpage < chose_class_page.getSize()-1) chose_class_curpage++;
        if (chose_year_curpage < chose_year_page.getSize()-1) chose_class_curpage++;
    });
    Button addsemester_okbutton(Non,24,550,700,100,50,"OK",[&](){
        string cur_sem_id = IDSem.getText();
        string start_day = StDay.getText();
        string end_day = EnDay.getText();
        Semester NS;
        int ID = 0; for(int i=0; i<cur_sem_id.size(); i++) ID = ID*10+cur_sem_id[i]-'0';
        NS.IDsemester = ID;
        NS.start_day = start_day;
        NS.end_day = end_day;
        if (ID) Add_A_Semester(ListYear.Head->data,NS);
        setText(default_semester,"Current semester: " + to_string(ListYear.Head->data.sem_list.Head->data.IDsemester),_Font,20,300,50,sf::Color::Black);
        IDSem.clear_str();
        StDay.clear_str();
        EnDay.clear_str();
        is_AddSemester = false;
        is_MainMenu = true;
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
            CurPage.addButton(BackPage);
            CurPage.addButton(NextPage);
            CurPage.addButton(addschoolyear_back);
            chose_year_page.push_back(CurPage);
        }
        chose_year_curpage = 0;
    });
    Button ViewCourse(cursor,24,490,250,220,50,"View Course",[&](){

    });
    Button AddSchoolYear(cursor,24,490,350,220,50,"Add school year",[&](){
        is_MainMenu = false;
        is_AddSchoolYear = true;
        addschoolyear_textfield.clear_str();
    });
    Button AddClasses(cursor,24,490,450,220,50,"Add class",[&](){
        is_AddClass = true;
        is_MainMenu = false;
    });
    Button AddCourses(cursor,24,490,150,220,50,"Add course",[&](){
        is_AddCourse = true;
        is_MainMenu = false;
        ID_input.clear_str();
        Name_input.clear_str();
        Class_input.clear_str();
        Teacher_input.clear_str();
        Session_input.clear_str();
        DayWeek_input.clear_str();
        Credits_input.clear_str();
        MaxStudent_input.clear_str();
        cur_addcourse_page = 0;
    });
    Button AddSemester(cursor,24,490,550,220,50,"Add semester",[&](){
        is_AddSemester = true;
        is_MainMenu = false;
    });
    Button OK1(Non,24,550,600,100,50,"OK",[&](){
        cur_addcourse_page = 1;
        temp.ID = ID_input.getText();
        temp.class_name = Class_input.getText();
        temp.course_name = Name_input.getText();
        temp.teacher_name = Teacher_input.getText();
    });
    Button OK2(Non,24,550,600,100,50,"OK",[&](){
        string TEMP = Credits_input.getText();
        int crdts = 0; for(int i=0; i<TEMP.size(); i++) crdts = crdts*10 + (TEMP[i]-'0');
        temp.credits_num = crdts;
        temp.day_of_week = DayWeek_input.getText();
        temp.session = Session_input.getText();
        int maxst = 0;
        TEMP = MaxStudent_input.getText();
        for(int i=0; i<TEMP.size(); i++) maxst = maxst*10 + TEMP[i]-'0';
        temp.max_students = maxst;
        is_AddCourse = false;
        is_MainMenu = true;
        Add_A_Course(ListYear.Head->data.sem_list.Head->data,temp);
    });
    Button addclass_okbutton(Non,24,550,600,100,50,"OK",[&](){
        string TEMP = addclass_classname_input.getText();
        Class NC; NC.class_name = TEMP;
        AddClass(ListYear.Head->data,NC);
        addclass_classname_input.clear_str();
        is_MainMenu = true;
        is_AddClass = false;
    });
    Button Back_From_Chose_Class(Non,20,105,100,70,50,"Back",[&](){
        is_ChoseClass = false;
        is_MainMenu = true;
    });
    Button AddNewStudent(cursor,24,435,250,330,50,"Add student to class",[&](){
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
            CurPage.addButton(Back_From_Chose_Class);
            chose_class_page.push_back(CurPage);
        }
        is_MainMenu = false;
        is_ChoseClass = true;
        is_AddIndividual = false;
        chose_class_curpage = 0;
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
    });
    Button AddCSVStudent(cursor,24,435,410,330,50,"Add student from CSV file",[&](){
        is_AddFromCSV = true;
        addstudent_folderpath_input.clear_str();
        is_AddStudent = false;
    });
    Button addstudent_okbutton(Non,24,550,700,100,50,"OK",[&](){
        Student NS;
        NS.ID = addstudent_ID_input.getText();
        NS.FirstName = addstudent_FirstName_input.getText();
        NS.LastName = addstudent_LastName_input.getText();
        NS.Gender = stoi(addstudent_Gender_input.getText());
        NS.dob = addstudent_Dob_input.getText();
        NS.Social_ID = addstudent_Social_input.getText();
        DLLNode<Class> *Cur = ListYear.Head->data.classes_list.Head;
        while (Cur){
            if (Cur->data.class_name == all_class_name[ID_chosen_class]) break;
            Cur = Cur->pNext;
        }
        AddStudent(Cur->data,NS);
        is_MainMenu = true;
        is_AddIndividual  = false;
    });
    Button addstudentcsv_okbutton(Non,24,550,700,100,50,"OK",[&](){
        string folderpath = addstudent_folderpath_input.getText();
        DLLNode<Class> *Cur = ListYear.Head->data.classes_list.Head;
        while (Cur){
            if (Cur->data.class_name == all_class_name[ID_chosen_class]) break;
            Cur = Cur->pNext;
        }
        bool is_add_success = QuickInputClass(folderpath,Cur->data);
        if (is_add_success) cout << "Success \n";
        is_MainMenu = true;
        is_AddFromCSV = false;
    });
    Button Back_To_Chose_Year(Non,20,105,100,70,50,"Back",[&](){
        is_ViewClass2 = false;
        is_ViewClass = true;
    });

    MainMenu.addButton(ViewClass);
    MainMenu.addButton(ViewCourse);
    MainMenu.addButton(AddSchoolYear);
    MainMenu.addButton(AddClasses);
    MainMenu.addButton(AddSemester);

    MainMenu2.addButton(AddCourses);
    MainMenu2.addButton(AddNewStudent);

    CheckLogOut.addButton(Logout);

    MainMenu.addButton(BackPage);
    MainMenu.addButton(NextPage);

    MainMenu2.addButton(BackPage);
    MainMenu2.addButton(NextPage);

    //view class 2
    viewclass2_vecbutton.addButton(BackPage);
    viewclass2_vecbutton.addButton(NextPage);
    viewclass2_vecbutton.addButton(Back_To_Chose_Year);

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
        is_ChoseClass = true;
    });
    addstudent_vecbutton.addButton(Back_to_Chose);
    addstudent_vecbutton.addButton(AddIndividualStudent);
    addstudent_vecbutton.addButton(AddCSVStudent);
    addstudent_csv.addButton(Back_from_add);
    addstudent_csv.addButton(addstudentcsv_okbutton);
    addstudent_indi.addButton(Back_from_add);
    //add individual
    addindi_vecbutton.addButton(addstudent_okbutton);


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
