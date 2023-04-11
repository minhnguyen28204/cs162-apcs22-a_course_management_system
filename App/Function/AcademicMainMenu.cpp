#include "AcademicMainMenu.h"
#include "Button.h"
#include "Vector.h"

sf::Texture ob;
sf::Texture cat;
sf::Sprite background;
sf::Sprite cursor;
sf::Sprite Non;
sf::Font _Font;
sf::Text welcome;
sf::Text author;
ButtonLibrary CheckLogOut;
ButtonLibrary MainMenu;
bool is_MainMenu;
Vector<ButtonLibrary> Page;
int curpage = 0;

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
    Page[curpage].draw(window);
    window.display();
}

//Handle event query from the window
void HandleEvent(sf::Event event){
    CheckLogOut.handleEvent(event);
    Page[curpage].handleEvent(event);
}

//Main function
void AcademicScreen(sf::RenderWindow &window, User Who, bool &logout){
    is_MainMenu = true;
    SetBackGround();
    SetwelcomeText(Who);
    Button Logout(Non,20,1100,720,80,50,"Logout",[&](){
        logout = true;
        window.close();
    });
    Button ViewClass(cursor,24,490,150,220,50,"View Class",[&](){

    });
    Button ViewCourse(cursor,24,490,260,220,50,"View Course",[&](){

    });
    Button AddSchoolYear(cursor,24,490,370,220,50,"Add school year",[&](){

    });
    MainMenu.addButton(ViewClass);
    MainMenu.addButton(ViewCourse);
    MainMenu.addButton(AddSchoolYear);
    Page.push_back(MainMenu);
    Button BackPage(cursor,20,100,600,150,50,"Previous Page",[&](){
        if (curpage > 0) curpage--;
    });
    Button NextPage(cursor,20,950,600,150,50,"Next Page",[&](){
        if (curpage < Page.getSize()-1) curpage++;
    });
    CheckLogOut.addButton(Logout);
    CheckLogOut.addButton(BackPage);
    CheckLogOut.addButton(NextPage);

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
