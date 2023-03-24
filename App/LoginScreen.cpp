#include <bits/stdc++.h>
#include "LoginScreen.h"
#include "Button.h"
#include "TextField.h"
#include "TextBox.h"
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

void MenuFunc(sf::RenderWindow &window, std::string &UserID, std::string &PasswordID, bool &Stop){
    bool Menu = true;
    bool Login = false;
    bool GetPass = false;

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

    Button LoginButton(500,375,200,50,"Login",[&](){
        Menu = false;
        Login = true;
    });
    Button ExitButton(500,475,200,50,"Exit",[&](){
                        Stop = true;
                        window.close();
                      });
    MenuScreenButton.addButton(LoginButton);
    MenuScreenButton.addButton(ExitButton);

    TextField UserInput(_font,24,sf::Color::Black,300,375,600,50);
    TextField PasswordInput(_font,24,sf::Color::Black,300,475,600,50);

    Button EnterButton(500,575,200,50,"Login",[&](){
        UserID = UserInput.getText();
        PasswordID = PasswordInput.getText();
        window.close();
    });
    LoginScreenButton.addButton(EnterButton);

    TextBox User(150,375,130,50,_font,"School ID");
    TextBox Pass(150,475,130,50,_font,"Password");

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (Menu) MenuScreenButton.handleEvent(event);
            if (Login) UserInput.handleEvent(event);
            if (Login) PasswordInput.handleEvent(event);
            if (Login) LoginScreenButton.handleEvent(event);
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
        if (Login){
            User.draw(window);
            Pass.draw(window);
            UserInput.draw(window);
            PasswordInput.draw(window);
            LoginScreenButton.draw(window);
        }
        // Display the window
        window.display();
    }
    return;
}
