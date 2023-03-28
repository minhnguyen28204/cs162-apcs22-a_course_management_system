#include "WrongPass.h"
#include "Button.h"

void WP(sf::RenderWindow &window, bool &Stop){
    sf::Texture pic; pic.loadFromFile("Image/Background.png");
    sf::Font _font; _font.loadFromFile("resources/font.ttf");
    sf::Sprite background(pic);

    sf::Text Info;
    Info.setCharacterSize(35);
    Info.setFont(_font);
    Info.setColor(sf::Color::Black);
    Info.setString("Wrong Password");
    Info.setPosition(460,375);

    Button TryAgain(500,475,200,50,"Try Again",[&](){
        Stop = false;
        window.close();
    });
    Button ExitButton(500,575,200,50,"Exit",[&](){
        Stop = true;
        window.close();
    });
    ButtonLibrary Butt;
    Butt.addButton(TryAgain);
    Butt.addButton(ExitButton);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                Stop = true;
                window.close();
            }
            Butt.handleEvent(event);
        }
        window.clear();
        window.draw(background);
        window.draw(Info);
        Butt.draw(window);
        window.display();
    }
}
