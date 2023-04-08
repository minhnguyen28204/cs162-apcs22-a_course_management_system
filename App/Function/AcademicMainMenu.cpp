#include "AcademicMainMenu.h"
#include "Button.h"

sf::Texture ob;
sf::Texture cat;
sf::Sprite background;
sf::Sprite cursor;
sf::Sprite Non;
sf::Font _Font;
sf::Text welcome;
sf::Text author;
ButtonLibrary CheckLogOut;

void setText(sf::Text &m_text, string str, sf::Font& _Font, unsigned int Size, float x, float y, sf::Color color){
    m_text.setString(str);
    m_text.setFont(_Font);
    m_text.setCharacterSize(Size);
    m_text.setPosition(x,y);
    m_text.setColor(color);
}

void SetBackGround(){
    ob.loadFromFile("Image/MainMenu.png");
    cat.loadFromFile("Image/CatDab.png");
    background.setTexture(ob);
    cursor.setTexture(cat);
    _Font.loadFromFile("resources/font.ttf");
}

void SetwelcomeText(User Who){
    setText(welcome,"Welcome " + Who.FirstName + " " + Who.LastName,_Font,24,20,20,sf::Color::Black);
    setText(author,"A project made by Group 3, APCS22, enjoy using it :3",_Font,15,170,760,sf::Color::Black);
}

//Draw window
void DrawWindow(sf::RenderWindow &window){
    window.clear();
    window.draw(background);
    window.draw(welcome);
    window.draw(author);
    CheckLogOut.draw(window);
    window.display();
}

//Handle event query from the window
void HandleEvent(sf::Event event){
    CheckLogOut.handleEvent(event);
}

//Main function
void AcademicScreen(sf::RenderWindow &window, User Who, bool &logout){
    SetBackGround();
    SetwelcomeText(Who);
    Button Logout(Non,20,1100,720,80,50,"Logout",[&](){
        logout = true;
        window.close();
    });
    CheckLogOut.addButton(Logout);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            HandleEvent(event);
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        DrawWindow(window);
    }
}
