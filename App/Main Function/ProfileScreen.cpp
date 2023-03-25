#include "ProfileScreen.h"
#include "TextBox.h"
#include "ScrollableWindow.hpp"

void Profile(int ID){
    ScrollableWindow window(1200,800,"Main Profile");
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Red);
    window.addDrawable(&circle);
    sf::RectangleShape rect;
    rect.setPosition(50,900);
    rect.setFillColor(sf::Color::Red);
    window.addDrawable(&rect);
    window.run();
}
