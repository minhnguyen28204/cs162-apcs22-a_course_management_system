#include <bits/stdc++.h>
#include "LoginScreen.h"
#include "Button.h"
#include "TextField.h"
#include "TextBox.h"
#include "PasswordField.hpp"
#include "CheckAccount.h"
#include <stdio.h>
#include <conio.h>
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

using namespace std;

#define ENTER 13
#define LEFT 75
#define UP 72
#define RIGHT 77
#define DOWN 80

void MenuFunc(sf::RenderWindow &window,bool& isLogin, int& ID,bool &Stop, User &Who, bool &is_student){
    bool Menu = true;
    bool Login = false;
    bool GetPass = false;
    bool clicked = false;
    bool is_login = false;
    string UserID;
    string PasswordID;

    sf::Sprite temp;
    sf::Font _font;
    if (!_font.loadFromFile("resources/font.ttf")){
        return;
    }

    sf::Texture Logo;
    if (!Logo.loadFromFile("Image/Background.png")){
        return;
    }
    sf::Sprite SLogo;
    SLogo.setTexture(Logo);

    ButtonLibrary MenuScreenButton;
    ButtonLibrary LoginScreenButton;

    TextField UserInput(_font,24,sf::Color::Black,300,375,600,50,true);
    TextField PasswordInput(_font,24,sf::Color::Black,300,475,600,50,false);

    Button LoginButton(temp,24,500,400,200,50,"Login",[&](){
        Menu = false;
        Login = true;
        UserInput.clear_str();
        PasswordInput.clear_str();
        clicked = false;
    });
    Button ExitButton(temp,24,500,550,200,50,"Exit",[&](){
        Stop = true;
        window.close();
    });
    MenuScreenButton.addButton(LoginButton);
    MenuScreenButton.addButton(ExitButton);

    Button EnterButton(temp,24,500,575,200,50,"Login",[&](){
        clicked = true;
        UserID = UserInput.getText();
        PasswordID = PasswordInput.getText();
        Checking(UserID,PasswordID,isLogin,ID,Stop,Who,is_student);
        is_login = isLogin;
    });
    LoginScreenButton.addButton(EnterButton);

    Button OK(temp,30,550,500,100,50,"Ok",[&](){
        clicked = false;
        if (is_login) window.close();
    });
    ButtonLibrary LoginInfo;
    LoginInfo.addButton(OK);

    TextBox User(150,375,130,50,_font,"School ID",24);
    TextBox Pass(150,475,130,50,_font,"Password",24);
    TextBox LoginSuccess(250,350,700,100,_font,"Login Successfully!",50);
    TextBox LoginFail(250,350,700,100,_font,"Wrong user or password",50);


    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (Menu) MenuScreenButton.handleEvent(event);
            if (clicked){
                LoginInfo.handleEvent(event);
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter){
                    clicked = false;
                    if (is_login) window.close();
                }
            }
            if (Login && !clicked) {
                UserInput.handleEvent(event);
                PasswordInput.handleEvent(event);
                LoginScreenButton.handleEvent(event);
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter){
                    UserID = UserInput.getText();
                    PasswordID = PasswordInput.getText();
                    Checking(UserID,PasswordID,isLogin,ID,Stop,Who,is_student);
                    is_login = isLogin;
                    clicked = true;
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab){
                    if (UserInput.cur_state() || PasswordInput.cur_state()){
                        UserInput.Tab_handle();
                        PasswordInput.Tab_handle();
                    }
                }
            }
            if (event.type == sf::Event::Closed){
                Stop = true;
                window.close();
            }
        }

        // Clear the window
        window.clear(sf::Color::White);
        window.draw(SLogo);
        if (Menu){
            MenuScreenButton.draw(window);
        }
        if (Login && !clicked){
            User.draw(window);
            Pass.draw(window);
            UserInput.draw(window);
            PasswordInput.draw(window);
            LoginScreenButton.draw(window);
        }
        if (is_login && clicked){
            LoginSuccess.draw(window);
            LoginInfo.draw(window);
        }
        if (!is_login && clicked){
            LoginFail.draw(window);
            LoginInfo.draw(window);
        }
        // Display the window
        window.display();
    }
    return;
}
