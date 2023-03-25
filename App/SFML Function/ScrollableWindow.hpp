#ifndef SCROLLABLE_WINDOW_H
#define SCROLLABLE_WINDOW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class ScrollableWindow {
public:
    ScrollableWindow(sf::RenderWindow& window, sf::Font& font, int width, int height);
    void addLine(const std::string& line);
    void scrollUp();
    void scrollDown();
    void display();

private:
    sf::RenderWindow& m_window;
    sf::Font& m_font;
    int m_width;
    int m_height;
    int m_scrollPos;
    std::vector<std::string> m_lines;
    sf::RectangleShape m_scrollBar;
    sf::RectangleShape m_scrollThumb;
};

#endif
