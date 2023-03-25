#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class ScrollableWindow {
public:
    ScrollableWindow(int width, int height, const std::string& title);
    void addDrawable(sf::Drawable* drawable);
    void run();
private:
    sf::RenderWindow window_;
    sf::View view_;
    std::vector<sf::Drawable*> drawables_;

    void handleEvents();
};
