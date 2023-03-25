#include "Student.h"
#include "LoginScreen.h"
#include "CheckAccount.h"
#include "ProfileScreen.h"
#include "WrongPass.h"
#include "ScrollableWindow.hpp"

int main(){
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
    return 0;
}
