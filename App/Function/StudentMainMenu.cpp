#include "StudentMainMenu.h"
#include "TextBox.h"
#include "TextField.h"
#include "ClickableText.hpp"
#include "Button.h"
#include <string>
#include "ChangePass.h"
#include "VoidOfUser.h"
#include "Import.h"
#include "DoublyLinkedList.hpp"
#include "ListOfText.hpp"
#include "VoidOfStudent.h"
#include "Vector.h"

using namespace std;

string SPoint(double &a){
      string s;
      s= to_string((int)(a));
      if (((int)(a*10))%10 == 0) return s;
      s += '.';
      s += to_string((int)(a*10)%10);
     return s;
}

bool is_StuMenu;
bool is_StuCourse;
bool is_StuGrade;
bool is_StuPass;
bool is_StuDetailC;
bool is_StuDetailC2;

sf::Text Author;
sf::Text Welcome;
sf::Texture object;
DLinkedList<Year> listYear;
sf::Texture catPointer;
sf::Sprite BackGround;
sf::Sprite Pointer;
sf::Sprite Nun;
ButtonLibrary StuMenu_vecbutton;

//Log out
ButtonLibrary LogOut;

//View Course
ButtonLibrary StuCourse_vecbutton;
Button CurrCourse;
Vector<ButtonLibrary> course_page;
int num_course_page;
string ChoseCourseName;

//View Detail Course
sf::Text StuCID;
sf::Text StuCName;
sf::Text StuCClass;
sf::Text STuCTeacher;
sf::Text StuCCredits;
sf::Text StuCMax;
sf::Text StuCDOW;
sf::Text StuCSession;

//View detail course
ButtonLibrary detailc_vecbutton;

//View detail score
ButtonLibrary detailsco_vecbutton;
TextBox OtherUp;
TextBox OtherDown;
TextBox MidUp;
TextBox MidDown;
TextBox FinUp;
TextBox FinDown;
TextBox TotUp;
TextBox TotDown;

//View Grade
ButtonLibrary StuGrade_vecbutton;
vector<vector<TextBox>> grade_page;
vector<TextBox> currpage;
int num_grade_page;
TextBox StuGPA;
TextBox StuOGPA;
TextBox SCourse_ID;
TextBox SCourse_Name;
TextBox STotal_Point;
TextBox SID_Score;
TextBox SName_Score;
TextBox STotal_Score;
sf::Font _font;

//Change password
ButtonLibrary StuPass_vecbutton;
TextField SOldpass(_font,24,sf::Color::Black,300,300,600,50,true);
sf::Text SOPass;
TextField SNewpass(_font,24,sf::Color::Black,300,400,600,50,true);
sf::Text SNPass;


void SetText(sf::Text &m_text, string str, sf::Font& _font, unsigned int Size, float x, float y, sf::Color color){
    m_text.setString(str);
    m_text.setFont(_font);
    m_text.setCharacterSize(Size);
    m_text.setPosition(x,y);
    m_text.setColor(color);
}

void SetCourseText(Course Cur){
    string temp = "ID: " + Cur.ID;
    SetText(StuCID,temp,_font,24,150,200,sf::Color::Black);
    temp = "Course name: " + Cur.course_name;
    SetText(StuCName,temp,_font,24,150,250,sf::Color::Black);
    temp = "Class name: " + Cur.class_name;
    SetText(StuCClass,temp,_font,24,150,300,sf::Color::Black);
    temp = "Teacher name: " + Cur.teacher_name;
    SetText(STuCTeacher,temp,_font,24,150,350,sf::Color::Black);
    temp = "Credits: " + to_string(Cur.credits_num);
    SetText(StuCCredits,temp,_font,24,150,400,sf::Color::Black);
    temp = "Max students: " + to_string(Cur.max_students);
    SetText(StuCMax,temp,_font,24,150,450,sf::Color::Black);
    temp = "Day of week: " + Cur.day_of_week;
    SetText(StuCDOW,temp,_font,24,150,500,sf::Color::Black);
    temp = "Session: " + Cur.session;
    SetText(StuCSession,temp,_font,24,150,550,sf::Color::Black);
}

void PassEnter(sf::RenderWindow &window, string ID){
    string old_pass = SOldpass.getText();
    string new_pass = SNewpass.getText();
    bool is_change = ChangeUserPass(ID,old_pass,new_pass);
    if (is_change){
        TextBox Info(300,325,600,150,_font,"Change successfully",30);
        Info.draw(window);
        window.display();
        sf::sleep(sf::seconds(2));
        window.clear();
        window.display();
        is_StuPass = false;
        is_StuMenu = true;
    }
    else{
        TextBox Info(300,325,600,150,_font,"Wrong password",30);
        Info.draw(window);
        window.display();
        sf::sleep(sf::seconds(2));
        window.clear();
        window.display();
    }
}

void ProcessEvent(sf::RenderWindow &window, sf::Event &event, string ID){
    LogOut.handleEvent(event);
    if (is_StuMenu) StuMenu_vecbutton.handleEvent(event);
    else if (is_StuCourse) {
        StuCourse_vecbutton.handleEvent(event);
        if (course_page.getSize()) course_page[num_course_page].handleEvent(event);
    }
    else if (is_StuDetailC){
        detailc_vecbutton.handleEvent(event);
    }
    else if (is_StuDetailC2){
        detailsco_vecbutton.handleEvent(event);
    }
    else if (is_StuGrade) {
        StuGrade_vecbutton.handleEvent(event);
    }
    else if (is_StuPass) {
        StuPass_vecbutton.handleEvent(event);
        SOldpass.handleEvent(event);
        SNewpass.handleEvent(event);
        if (event.type==sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter){
            PassEnter(window,ID);
        }
        if (event.type==sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab){
            if (SOldpass.cur_state()){
                SOldpass.Tab_handle();
                SNewpass.Tab_handle();
            }
            else if (SNewpass.cur_state()){
                SNewpass.Tab_handle();
                SOldpass.Tab_handle();
            }
        }
    }
}

void WindowDraw(sf::RenderWindow &window){
    window.clear();
    window.draw(BackGround);
    window.draw(Author);
    window.draw(Welcome);
    LogOut.draw(window);

    if (is_StuMenu) StuMenu_vecbutton.draw(window);
    else if (is_StuCourse) {
        StuCourse_vecbutton.draw(window);
        if (course_page.getSize()) course_page[num_course_page].draw(window);
    }
    else if (is_StuDetailC){
        window.draw(StuCID);
        window.draw(StuCName);
        window.draw(StuCClass);
        window.draw(STuCTeacher);
        window.draw(StuCCredits);
        window.draw(StuCMax);
        window.draw(StuCDOW);
        window.draw(StuCSession);
        detailc_vecbutton.draw(window);
    }
    else if (is_StuDetailC2){
        detailsco_vecbutton.draw(window);
        OtherUp.draw(window);
        OtherDown.draw(window);
        MidUp.draw(window);
        MidDown.draw(window);
        FinUp.draw(window);
        FinDown.draw(window);
        TotUp.draw(window);
        TotDown.draw(window);
    }
    else if (is_StuGrade) {
        StuGrade_vecbutton.draw(window);
        StuGPA.draw(window);
        StuOGPA.draw(window);
        SCourse_ID.draw(window);
        SCourse_Name.draw(window);
        STotal_Point.draw(window);
        if (grade_page.size()){
            for(int i=0; i<grade_page[num_grade_page].size(); i++) grade_page[num_grade_page][i].draw(window);
        }
    }
    else if (is_StuPass) {
        window.draw(SOPass);
        window.draw(SNPass);
        StuPass_vecbutton.draw(window);
        SOldpass.draw(window);
        SNewpass.draw(window);
    }

    window.display();
}

void StudentScreen(sf::RenderWindow &window, Student Who, bool& logout){
    //preprocess
    is_StuMenu = true;
    is_StuCourse = false;
    is_StuGrade = false;
    is_StuPass = false;
    is_StuDetailC = false;
    is_StuDetailC2 = false;

    importData("Information/SystemData",listYear);
    object.loadFromFile("Image/MainMenu.png");
    catPointer.loadFromFile("Image/CatDab.png");
    BackGround.setTexture(object);
    Pointer.setTexture(catPointer);

    _font.loadFromFile("resources/font.ttf");

    SetText(Welcome,"Welcome " + Who.FirstName + " " + Who.LastName,_font,24,20,20,sf::Color::Black);
    SetText(Author,"A project made by Group 3, APCS22, enjoy using it :3",_font,15,170,760,sf::Color::Black);
    SetText(SNPass,"New password: ",_font,24,100,400,sf::Color::Black);
    SetText(SOPass,"Old password: ",_font,24,100,300,sf::Color::Black);

    Button Logout(Nun,20,1100,720,80,50,"Logout",[&](){
        logout = true;
        window.close();
    });
    LogOut.addButton(Logout);
    Button StuVCourse(Pointer,24,490,200,220,50,"View course",[&](){
        is_StuMenu  = false;
        is_StuCourse = true;
        vector<Course> all_course_id;
        DLLNode<Course> *TempCourse = listYear.Head->data.sem_list.Head->data.course_list.Head;
        while (TempCourse){
            DLLNode<Student> *cur = TempCourse->data.stu_list.Head;
            bool ok = false;
            while (cur){
                if (cur->data.ID == Who.ID){
                    ok = true;
                    break;
                }
                cur = cur->pNext;
            }
            if (ok) all_course_id.push_back(TempCourse->data);
            TempCourse = TempCourse->pNext;
        }
        int i = 0;
        int cur_num = all_course_id.size();
        while (i < cur_num){
            int cnt = 4;
            int UpperBound = 200;
            ButtonLibrary CurPage;
            while (i < cur_num && cnt){
                CurrCourse.SetFunction([=](){
                    ChoseCourseName = all_course_id[i].ID;
                    SetCourseText(all_course_id[i]);
                    is_StuCourse = false;
                    is_StuDetailC = true;
                });
                string TEMP = all_course_id[i].ID + " - " + all_course_id[i].course_name;
                CurrCourse.ChangeText(TEMP);
                CurrCourse.SetDetail(Nun,24,300,UpperBound,600,50);
                cnt--;
                i++;
                UpperBound+=100;
                CurPage.addButton(CurrCourse);
            }
            course_page.push_back(CurPage);
        }
        num_course_page = 0;
    });
    Button Back_To_Menu(Nun,20,105,100,70,50,"Back",[&](){
        is_StuMenu = true;
        is_StuCourse = false;
        is_StuGrade = false;
        is_StuPass = false;
    });
    Button StuVGrade(Pointer,24,490,300,220,50,"View grade",[&](){
        is_StuGrade = true;
        is_StuMenu = false;
        DLinkedList<Course> CL;
        DLLNode<Score> *cur_score;
        DLLNode<Student> *cur_stu = listYear.Head->data.classes_list.Head->data.stu_list.Head;
        while (cur_stu){
            if (cur_stu->data.ID == Who.ID) break;
            cur_stu = cur_stu->pNext;
        }
        int NumCre;
        double TotSco;
        ViewResultInSemester(cur_stu->data,listYear.Head->data.IDyear,listYear.Head->data.sem_list.Head->data.IDsemester,listYear,CL,cur_score,NumCre,TotSco);
        double gpa = TotSco/NumCre;
        double OveGpa = (cur_stu->data).TotalScore / (cur_stu->data).Number_Of_Credits;

        StuGPA.SetDetail(200,100,150,50,_font,"GPA: " + SPoint(gpa),24);
        StuOGPA.SetDetail(400,100,600,50,_font,"Overall GPA: " + SPoint(OveGpa),24);
        SCourse_ID.SetDetail(200,200,100,50,_font,"ID",24);
        SCourse_Name.SetDetail(300,200,600,50,_font,"Course name",24);
        STotal_Point.SetDetail(900,200,100,50,_font,"Total",24);
        grade_page.clear();
        DLLNode<Course> *cur = CL.Head;
        while (cur){
            int cnt = 6;
            int UpperBound = 250;
            currpage.clear();
            while (cnt && cur){
                SID_Score.SetDetail(200,UpperBound,100,50,_font,cur->data.ID,24);
                SName_Score.SetDetail(300,UpperBound,600,50,_font,cur->data.course_name,24);
                TextBox Total(900,UpperBound,100,50,_font,SPoint(cur_score->data.tot_mark),24);
                currpage.push_back(SID_Score);
                currpage.push_back(SName_Score);
                currpage.push_back(Total);
                cur = cur->pNext;
                cur_score = cur_score->pNext;
                UpperBound+=50;
                cnt--;
            }
            grade_page.push_back(currpage);
        }
        num_grade_page = 0;
    });
    Button StuChangePass(Pointer,24,490,400,220,50,"Change password",[&](){
        is_StuPass = true;
        is_StuMenu = false;
    });
    Button StuExit(Pointer,24,490,500,220,50,"Exit",[&](){
        window.close();
    });
    Button NextPage(Pointer,20,950,600,150,50,"Next Page",[=](){
        if (num_course_page < course_page.getSize()-1) num_course_page++;
        if (num_grade_page < grade_page.size()-1) num_grade_page++;
    });
    Button BackPage(Pointer,20,100,600,150,50,"Previous Page",[=](){
        if (num_course_page > 0) num_course_page--;
        if (num_grade_page > 0) num_grade_page--;
    });
    Button PassOK(Nun,24,500,700,200,50,"OK",[&](){
        PassEnter(window,Who.ID);
    });
    Button Back_Course(Nun,20,105,100,70,50,"Back",[&](){
        is_StuDetailC = false;
        is_StuCourse = true;
    });
    Button ViewDetailGrade(Nun,24,400,600,400,50,"View detail score of this course",[&](){
        is_StuDetailC = false;
        is_StuDetailC2 = true;
        DLLNode<Course> *CCourse = listYear.Head->data.sem_list.Head->data.course_list.Head;
        while (CCourse){
            if (CCourse->data.ID == ChoseCourseName) break;
            CCourse = CCourse->pNext;
        }
        DLLNode<Score> *Cur = CCourse->data.score_list.Head;
        while (Cur){
            cout << Cur->data.stu_id << '\n';
            if (Cur->data.stu_id == Who.ID) break;
            Cur = Cur->pNext;
        }
        if (Cur){
            OtherUp.SetDetail(200,300,200,100,_font,"Other",24);
            MidUp.SetDetail(400,300,200,100,_font,"Midterm",24);
            FinUp.SetDetail(600,300,200,100,_font,"Final",24);
            TotUp.SetDetail(800,300,200,100,_font,"Total",24);
            OtherDown.SetDetail(200,400,200,100,_font,SPoint(Cur->data.other_mark),24);
            MidDown.SetDetail(400,400,200,100,_font,SPoint(Cur->data.mid_mark),24);
            FinDown.SetDetail(600,400,200,100,_font,SPoint(Cur->data.fin_mark),24);
            TotDown.SetDetail(800,400,200,100,_font,SPoint(Cur->data.tot_mark),24);
        }
        else cout << "Khong co diem pa oi \n";
    });
    Button Back_Detail(Nun,20,105,100,70,50,"Back",[&](){
        is_StuDetailC2 = false;
        is_StuDetailC = true;
    });

    //Main menu
    StuMenu_vecbutton.addButton(StuVCourse);
    StuMenu_vecbutton.addButton(StuVGrade);
    StuMenu_vecbutton.addButton(StuChangePass);
    StuMenu_vecbutton.addButton(StuExit);

    //View Course
    StuCourse_vecbutton.addButton(Back_To_Menu);
    StuCourse_vecbutton.addButton(BackPage);
    StuCourse_vecbutton.addButton(NextPage);

    //View detail
    detailc_vecbutton.addButton(Back_Course);
    detailc_vecbutton.addButton(ViewDetailGrade);

    //View detail score
    detailsco_vecbutton.addButton(Back_Detail);

    //View Grade
    StuGrade_vecbutton.addButton(Back_To_Menu);
    StuGrade_vecbutton.addButton(BackPage);
    StuGrade_vecbutton.addButton(NextPage);

    //Change pass
    StuPass_vecbutton.addButton(Back_To_Menu);
    StuPass_vecbutton.addButton(PassOK);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type==sf::Event::Closed){
                window.close();
            }
            ProcessEvent(window,event,Who.ID);
        }
        WindowDraw(window);
    }
}
