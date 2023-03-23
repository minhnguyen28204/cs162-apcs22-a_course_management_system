#include <bits/stdc++.h>
#include "LoginScreen.h"
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

void MenuFunc(){
    // Create the window
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Button Library Example",sf::Style::Titlebar | sf::Style::Close);


    bool Menu = true;
    bool Login = false;

    ButtonLibrary LoginScreenButton;

    sf::Texture Logo;
    if (!Logo.loadFromFile("Image/Background.png")){
        return;
    }

    sf::Sprite SLogo;
    SLogo.setTexture(Logo);


    // Create the "Login" button
    Button loginButton(500, 375, 200, 50, "Login", [&]() {
        // TODO: Implement the login functionality
        Login = true;
        Menu = false;
    });
    LoginScreenButton.addButton(loginButton);

    // Create the "Exit" button
    Button exitButton(500, 475, 200, 50, "Exit", [&window]() {
        window.close();
    });
    LoginScreenButton.addButton(exitButton);

    // Create the "Student" button
    Button Student_Choose(350,375,200,50,"Student", [&](){});

    // Create the "Academic Staff" button
    Button Aca_Choose(650,375,200,50,"Academic Staff", [&](){});

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
        // Handle events
            if (event.type == sf::Event::MouseMoved)
            {
                loginButton.handleMouseMoved(event.mouseMove.x, event.mouseMove.y);
                exitButton.handleMouseMoved(event.mouseMove.x, event.mouseMove.y);
                Student_Choose.handleMouseMoved(event.mouseMove.x, event.mouseMove.y);
                Aca_Choose.handleMouseMoved(event.mouseMove.x, event.mouseMove.y);
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (loginButton.contains(event.mouseButton.x, event.mouseButton.y))
                {
                    loginButton.onClick();
                }
                if (exitButton.contains(event.mouseButton.x, event.mouseButton.y)){
                    exitButton.onClick();
                }
            }
            else if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Clear the window
        window.clear(sf::Color::White);
        window.draw(SLogo);
        // Draw the button
        if (Menu){
            window.draw(loginButton);
            window.draw(exitButton);
        }
        if (Login){
            window.draw(Student_Choose);
            window.draw(Aca_Choose);
            window.draw(exitButton);
        }

        // Display the window
        window.display();
    }
    return;
}
