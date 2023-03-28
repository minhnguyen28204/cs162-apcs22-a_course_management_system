#include "StudentMainMenu.h"

void StudentScreen(sf::RenderWindow &window, User Who){
    sf::Texture object;
    object.loadFromFile("Image/MainMenu.png");
    sf::Sprite BackGround(object);
    sf::Font _font; _font.loadFromFile("resources/font.ttf");


    sf::Text TopLeftCorner;
    TopLeftCorner.setString("Welcome " + Who.FirstName + " " + Who.LastName);
    TopLeftCorner.setPosition(50,50);
    TopLeftCorner.setFont(_font);
    TopLeftCorner.setCharacterSize(24);
    TopLeftCorner.setColor(sf::Color::Black);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type==sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.draw(BackGround);
        window.draw(TopLeftCorner);
        window.display();
    }
}
