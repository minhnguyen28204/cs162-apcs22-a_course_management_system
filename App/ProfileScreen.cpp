#include "ProfileScreen.h"
#include "TextBox.h"

void Profile(sf::RenderWindow &window, Student &User){
    sf::Font _font;
    _font.loadFromFile("resources/font.ttf");
    sf::Text Title;
    Title.setFont(_font);
    Title.setString("Welcome " + User.LastName);
    Title.setPosition(30,30);
    Title.setCharacterSize(24);
    Title.setColor(sf::Color::Black);

    sf::Texture pic;
    if (!pic.loadFromFile("Image/Profile.png")){
        return;
    }
    sf::Sprite background(pic);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type==sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.draw(background);
        window.draw(Title);
        window.display();
    }
}
