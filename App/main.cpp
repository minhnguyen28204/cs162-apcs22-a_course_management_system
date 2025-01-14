#include <string>
#include <fstream>
#include "Import.h"
#include "Export.h"
#include "VoidOfStaff.h"
#include "DoublyLinkedList.hpp"
#include "LoginScreen.h"
#include "Class.h"
#include "Course.h"
#include "Year.h"
#include "Login/LoginScreen.h"
#include "VoidOfUser.h"
#include "Export.h"
#include "StudentMainMenu.h"
#include "AcademicMainMenu.h"
#include <SFML/Graphics.hpp>
#define y1 kdbfksdjfbkdjfb

int main(){
    while(1){
        bool Stop = false, isLogin = false;
        bool is_student;
        User CurrAccount;
        int ID;
        while(1){
            sf::RenderWindow window(sf::VideoMode(1200, 800), "Course Management System",sf::Style::Titlebar | sf::Style::Close);
            MenuFunc(window,isLogin,ID,Stop,CurrAccount,is_student);
            if (Stop) break;
        }
        if (!isLogin) return 0;
        sf::RenderWindow MainMenu(sf::VideoMode(1200,800), "Main Menu",sf::Style::Titlebar | sf::Style::Close);
        bool LogOut = false;
        if (is_student){
            StudentScreen(MainMenu,CurrAccount,LogOut);
        }
        else{
            AcademicScreen(MainMenu,CurrAccount,LogOut);
        }
        if (LogOut==false) break;
    }
    return 0;
}
