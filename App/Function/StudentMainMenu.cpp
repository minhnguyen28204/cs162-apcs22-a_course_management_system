#include "StudentMainMenu.h"
#include "TextBox.h"
#include "TextField.h"
#include "ClickableText.hpp"
#include "Button.h"
#include <string>
#include "ChangePass.h"
using namespace std;

void SetText(sf::Text &m_text, string str, sf::Font& _font, unsigned int Size, float x, float y, sf::Color color){
    m_text.setString(str);
    m_text.setFont(_font);
    m_text.setCharacterSize(Size);
    m_text.setPosition(x,y);
    m_text.setColor(color);
}

void StudentScreen(sf::RenderWindow &window, User Who, bool& logout){
    sf::Texture object;
    object.loadFromFile("Image/MainMenu2.png");
    sf::Texture catPointer;
    catPointer.loadFromFile("Image/CatDab.png");
    sf::Sprite BackGround(object);
    sf::Sprite Pointer(catPointer);
    sf::Sprite Nun;

    sf::Font _font; _font.loadFromFile("resources/font.ttf");

    sf::Text Welcome;
    SetText(Welcome,"Welcome " + Who.FirstName + " " + Who.LastName,_font,24,20,20,sf::Color::Black);
    sf::Text Author;
    SetText(Author,"A project made by Group 3, APCS22, enjoy using it :3",_font,15,170,760,sf::Color::Black);

    bool MainMenu = true;
    bool ChangePass = false;
    bool ViewCourse = false;
    bool ViewGrade = false;

    //Check for logout
    Button LogOut(Nun,20,1100,720,80,50,"Logout",[&](){
        logout = true;
        window.close();
    });
    ButtonLibrary CheckLogOut;
    CheckLogOut.addButton(LogOut);


    ButtonLibrary MainButton;
    Button ViewC(Pointer,24,490,255,220,50,"View Courses",[&](){
        window.close();
    });
    Button ViewProfile(Pointer,24,490,360,220,50,"Profile",[&](){
        window.close();
    });
    Button Grade(Pointer,24,490,465,220,50,"Grade",[&](){
        window.close();
    });
    Button Exit(Pointer,24,490,570,220,50,"Exit",[&](){
        window.close();
    });
    MainButton.addButton(ViewC);
    MainButton.addButton(ViewProfile);
    MainButton.addButton(Grade);
    MainButton.addButton(Exit);




    //Change password textfield and button
    bool is_changed;
    bool clicked;
    ButtonLibrary ChangePassButtons;
    ButtonLibrary IsClickedButtons;
    TextBox oldpass(200,250,190,50,_font,"Old password",24);
    TextField OldPass(_font,24,sf::Color::Black,400,250,600,50,true);
    TextBox newpass(200,450,190,50,_font,"New password",24);
    TextField NewPass(_font,24,sf::Color::Black,400,450,600,50,true);
    TextBox ChangedSuccess(250,350,700,100,_font,"Password changed success",50);
    TextBox ChangedFail(250,350,700,100,_font,"Wrong current password",50);
    Button OK(Nun,30,550,500,100,50,"Ok",[&](){
        MainMenu = true;
        ChangePass = false;
    });
    Button Back(Nun,20,105,100,70,50,"Back",[&](){
        ChangePass = false;
        MainMenu = true;
    });
    Button ChangePassword(Pointer,24,490,150,220,50,"Change password",[&](){
        OldPass.clear_str();
        NewPass.clear_str();
        clicked = false;
        is_changed = false;
        ChangePass = true;
        MainMenu = false;
    });
    MainButton.addButton(ChangePassword);
    Button Enter(Nun,30,500,600,200,50,"OK",[&](){
        is_changed = ChangeUserPass(Who.ID,OldPass.getText(),NewPass.getText());
        clicked = true;
    });
    ChangePassButtons.addButton(Back);
    ChangePassButtons.addButton(Enter);
    IsClickedButtons.addButton(OK);

    bool temp=false;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type==sf::Event::Closed){
                window.close();
            }
            CheckLogOut.handleEvent(event);
            if (MainMenu) MainButton.handleEvent(event);
            if (ChangePass){
                if (!clicked){
                    ChangePassButtons.handleEvent(event);
                    OldPass.handleEvent(event);
                    NewPass.handleEvent(event);
                }
                else if (clicked){
                    IsClickedButtons.handleEvent(event);
                }
            }
        }
        window.clear();
        window.draw(BackGround);
        window.draw(Welcome);
        window.draw(Author);
        CheckLogOut.draw(window);
        if (MainMenu) MainButton.draw(window);
        if (ChangePass) {
            if (!clicked){
                ChangePassButtons.draw(window),
                OldPass.draw(window),
                oldpass.draw(window),
                newpass.draw(window),
                NewPass.draw(window);
            }
            if (is_changed && clicked){
                ChangedSuccess.draw(window);
                IsClickedButtons.draw(window);
            }
            else if (!is_changed && clicked){
                ChangedFail.draw(window);
                IsClickedButtons.draw(window);
            }
        }
        window.display();
    }
}
