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
bool is_AddSchoolYear;
bool is_AddClass;
bool is_AddCourse;
bool is_AddSemester;
bool is_AddStudent;
bool is_AddIndividual;
bool is_AddFromCSV;
Vector<ButtonLibrary> Page;
int curpage = 0;
DLinkedList <Year> ListYear;

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

//Add individual


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
    if (is_AddIndividual){
        addstudent_indi.draw(window);
    }
    if (is_AddFromCSV){
        addstudent_csv.draw(window);
    }

    window.display();
}



//Handle event query from the window
void HandleEvent(sf::Event event, sf::RenderWindow &window){
    CheckLogOut.handleEvent(event);

    if (is_MainMenu) Page[curpage].handleEvent(event);

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

    if (is_AddStudent){
        addstudent_vecbutton.handleEvent(event);
    }
    if (is_AddIndividual && !is_AddStudent){
        addstudent_indi.handleEvent(event);
    }
    if (is_AddFromCSV && !is_AddStudent){
        addstudent_csv.handleEvent(event);
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

    });
    Button ViewCourse(cursor,24,490,260,220,50,"View Course",[&](){

    });
    Button AddSchoolYear(cursor,24,490,370,220,50,"Add school year",[&](){
        is_MainMenu = false;
        is_AddSchoolYear = true;
        addschoolyear_textfield.clear_str();
    });
    Button AddClasses(cursor,24,490,480,220,50,"Add class",[&](){
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
    Button AddSemester(cursor,24,490,590,220,50,"Add semester",[&](){
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
    Button AddNewStudent(cursor,24,435,260,330,50,"Add student to class",[&](){
        is_MainMenu = false;
        is_AddStudent = true;
    });
    Button AddIndividualStudent(cursor,24,490,300,220,50,"Add a student",[&](){
        is_AddIndividual = true;
        is_AddStudent = false;
    });
    Button AddCSVStudent(cursor,24,435,410,330,50,"Add student from CSV file",[&](){
        is_AddFromCSV = true;
        is_AddStudent = false;
    });


    MainMenu.addButton(ViewClass);
    MainMenu.addButton(ViewCourse);
    MainMenu.addButton(AddSchoolYear);
    MainMenu.addButton(AddClasses);
    MainMenu.addButton(AddSemester);

    MainMenu2.addButton(AddCourses);
    MainMenu2.addButton(AddNewStudent);

    Button BackPage(cursor,20,100,600,150,50,"Previous Page",[&](){
        if (curpage > 0) curpage--;
    });
    Button NextPage(cursor,20,950,600,150,50,"Next Page",[&](){
        if (curpage < 1) curpage++;
    });
    CheckLogOut.addButton(Logout);

    MainMenu.addButton(BackPage);
    MainMenu.addButton(NextPage);

    MainMenu2.addButton(BackPage);
    MainMenu2.addButton(NextPage);

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
    addstudent_vecbutton.addButton(addschoolyear_back);
    addstudent_vecbutton.addButton(AddIndividualStudent);
    addstudent_vecbutton.addButton(AddCSVStudent);
    addstudent_csv.addButton(Back_from_add);
    addstudent_indi.addButton(Back_from_add);


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
