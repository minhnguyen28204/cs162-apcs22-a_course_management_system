#include <string>
#include <fstream>
#include "DoublyLinkedList.hpp"
#include "CheckAccount.h"
#include "ProfileScreen.h"
#include "WrongPass.h"
#include "Class.h"
#include "Course.h"
#include "Year.h"
#include "Login/LoginScreen.h"
#include "VoidOfUser.h"
#include "Export.h"
#include "StudentMainMenu.h"
#include <SFML/Graphics.hpp>
#define y1 kdbfksdjfbkdjfb

int main(){
    /*
    bool Stop = false, isLogin = false;
    int ID;
    while(1){
        sf::RenderWindow window(sf::VideoMode(1200, 800), "Course Management System",sf::Style::Titlebar | sf::Style::Close);
        User CurrentUser;
        Checking(window,isLogin,ID,Stop);
        if (!isLogin && !Stop){
            sf::RenderWindow window2(sf::VideoMode(1200, 800), "Course Management System",sf::Style::Titlebar | sf::Style::Close);
            WP(window2,Stop);
        }
        if (Stop) break;
    }
    User CurrAccount;
    getUser(ID,CurrAccount);
    sf::RenderWindow MainMenu(sf::VideoMode(1200,800), "Main Menu",sf::Style::Titlebar | sf::Style::Close);
    if (CurrAccount.IsStudent){
        StudentScreen(MainMenu,CurrAccount);
    }
    */
    // Score sc_st1;
    // Score sc_st2;
    // Score sc_st3;
    // sc_st1.No = 1;
    // sc_st1.first_name = "Bach";
    // sc_st1.mid_mark = 10;
    // sc_st2.No = 2;
    // sc_st2.first_name = "Nghia";
    // sc_st2.mid_mark = 10;
    // sc_st3.No = 3;
    // sc_st3.first_name = "Minh";
    // sc_st3.mid_mark = 10;
    // Scoreboard sco1,sco2,sco3;
    // sco1.score_list.push(sc_st1);
    // sco1.unlocked = false;
    // sco1.score_list.push(sc_st2);
    // sco2.score_list.push(sc_st3);
    // sco2.unlocked = true;
    // sco3.score_list.push(sc_st1);
    // sco3.unlocked = false;
    // Student stu1, stu2, stu3;
    // stu1.ID = 22125005;
    // stu1.FirstName = "Bach";
    // stu1.No = 1;
    // stu2.ID = 22125006;
    // stu2.FirstName = "Nghia";
    // stu2.No = 2;
    // stu3.No = 3;
    // stu3.FirstName = "Minh";
    // stu3.ID = 22125007;
    // Class class1, class2;
    // class1.class_name = "22CTT1";
    // class2.class_name = "22CTT2";
    // class1.stu_list.push(stu1);
    // class1.stu_list.push(stu2);
    // class2.stu_list.push(stu3);
    // Course course1, course2, course3;
    // course1.course_name = "INTRODUCTION TO COMPUTER SCIENCE I";
    // course2.course_name = "CALCULUS II";
    // course3.course_name = "GENERAL PHYSIC II";
    // course1.stu_list.push(stu1);
    // course1.stu_list.push(stu2);
    // course2.stu_list.push(stu3);
    // course3.stu_list.push(stu1);
    // course1.sco_board = sco1;
    // course2.sco_board = sco2;
    // course3.sco_board = sco3;
    // Semester s1,s2,s3;
    // s1.IDsemester = 1;
    // s2.IDsemester = 2;
    // s3.IDsemester = 3;
    // s1.start_day = "1/1/2023";
    // s2.start_day = "4/5/2023";
    // s3.start_day = "9/9/2023";
    // s1.course_list.push(course1);
    // s2.course_list.push(course2);
    // s3.course_list.push(course3);
    // Year y1, y2;
    // y1.IDyear = 2019;
    // y2.IDyear = 2020;
    // y1.classes_list.push(class1);
    // y1.classes_list.push(class2);
    // y2.classes_list.push(class2);
    // y1.sem_list.push(s1);
    // y1.sem_list.push(s2);
    // y1.sem_list.push(s3);
    // y2.sem_list.push(s1);
    // y2.sem_list.push(s2);
    // DLinkedList <Year> listyear;
    // listyear.push(y1);
    // listyear.push(y2);
    // if(Save_Data("SystemData", listyear)) cout << "Successfull!" << endl;

    // else cout << "Failed! " << endl;
    DLinkedList <Year> listyear;
    listyear.Head->data.sem_list.Head->data.course_list.Head

    return 0;
}
