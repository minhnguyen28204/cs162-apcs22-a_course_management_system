#include <string>
#include <fstream>
#include "DoublyLinkedList.hpp"
#include "Class.h"
#include "Course.h"
#include "Year.h"
#include "Login/LoginScreen.h"
#include "VoidOfUser.h"
#include "Export.h"
#define y1 kdbfksdjfbkdjfb

int main()
{
    bool Stop = false;
    while(1){
        sf::RenderWindow window(sf::VideoMode(1200, 800), "Course Management System",sf::Style::Titlebar | sf::Style::Close);
        bool isLogin = false;
        User CurrentUser;
        int ID;
        Checking(window,isLogin,ID,Stop);
        if (isLogin && !Stop){
            Profile(ID);
            break;
        }
        else if (!Stop){
            sf::RenderWindow window3(sf::VideoMode(1200, 800), "Course Management System",sf::Style::Titlebar | sf::Style::Close);
            WP(window3,Stop);
        }
        if (Stop) break;
    }
    Score sc_st1;
    Score sc_st2;
    Score sc_st3;
    sc_st1.No = 1;
    sc_st1.first_name = "Bach";
    sc_st1.mid_mark = 10;
    sc_st2.No = 2;
    sc_st2.first_name = "Nghia";
    sc_st2.mid_mark = 10;
    sc_st3.No = 3;
    sc_st3.first_name = "Minh";
    sc_st3.mid_mark = 10;
    Scoreboard sco1,sco2,sco3;
    sco1.score_list.push_front(sc_st1);
    sco1.unlocked = false;
    sco1.score_list.push_front(sc_st2);
    sco2.score_list.push_front(sc_st3);
    sco2.unlocked = true;
    sco3.score_list.push_front(sc_st1);
    sco3.unlocked = false;
    Student stu1, stu2, stu3;
    stu1.ID = 22125005;
    stu1.FirstName = "Bach";
    stu1.No = 1;
    stu2.ID = 22125006;
    stu2.FirstName = "Nghia";
    stu2.No = 2;
    stu3.No = 3;
    stu3.FirstName = "Minh";
    stu3.ID = 22125007;
    Class class1, class2;
    class1.class_name = "22CTT1";
    class2.class_name = "22CTT2";
    class1.stu_list.push_front(stu1);
    class1.stu_list.push_front(stu2);
    class2.stu_list.push_front(stu3);
    Course course1, course2, course3;
    course1.course_name = "INTRODUCTION TO COMPUTER SCIENCE I";
    course2.course_name = "CALCULUS II";
    course3.course_name = "GENERAL PHYSIC II";
    course1.stu_list.push_front(stu1);
    course1.stu_list.push_front(stu2);
    course2.stu_list.push_front(stu3);
    course3.stu_list.push_front(stu1);
    course1.sco_board = sco1;
    course2.sco_board = sco2;
    course3.sco_board = sco3;
    Semester s1,s2,s3;
    s1.IDsemester = 1;
    s2.IDsemester = 2;
    s3.IDsemester = 3;
    s1.start_day = "1/1/2023";
    s2.start_day = "4/5/2023";
    s3.start_day = "9/9/2023";
    s1.course_list.push_front(course1);
    s2.course_list.push_front(course2);
    s3.course_list.push_front(course3);
    Year y1, y2;
    y1.IDyear = 2019;
    y2.IDyear = 2020;
    y1.classes_list.push_front(class1);
    y1.classes_list.push_front(class2);
    y2.classes_list.push_front(class2);
    y1.sem_list.push_front(s1);
    y1.sem_list.push_front(s2);
    y1.sem_list.push_front(s3);
    y2.sem_list.push_front(s1);
    y2.sem_list.push_front(s2);
    DLinkedList <Year> listyear;
    listyear.push_front(y1);
    listyear.push_front(y2);
    if(Save_Data("D:/SystemData", listyear)) cout << "Successfull!" << endl;
    else cout << "Failed! " << endl;

    return 0;
}
