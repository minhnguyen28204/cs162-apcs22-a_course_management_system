#include <string>
#include <fstream>
#include "DoublyLinkedList.hpp"
#include "LoginScreen.h"
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
    bool Stop = false, isLogin = false;
    int ID;
    while(1){
        bool Stop = false, isLogin = false;
        int ID;
        while(1){
            sf::RenderWindow window(sf::VideoMode(1200, 800), "Course Management System",sf::Style::Titlebar | sf::Style::Close);
            User CurrentUser;
            MenuFunc(window,isLogin,ID,Stop);
            if (Stop) break;
        }
        if (!isLogin) return 0;
        User CurrAccount;
        getUser(ID,CurrAccount);
        sf::RenderWindow MainMenu(sf::VideoMode(1200,800), "Main Menu",sf::Style::Titlebar | sf::Style::Close);
        bool Dangxuat = false;
        if (CurrAccount.IsStudent){

            StudentScreen(MainMenu,CurrAccount,Dangxuat);
        }
        if (Dangxuat==false) break;
    }
    return 0;
}
