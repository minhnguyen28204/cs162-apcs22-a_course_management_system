#ifndef TEXT_FIELD_H
#define TEXT_FIELD_H

#include <SFML/Graphics.hpp>
#include <string>

class TextField
{
public:
    TextField(sf::Font& font, unsigned int size, sf::Color color, float x, float y, float width, float height, bool showText);

    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event event);
    std::string getText() const;

private:
    float pos_x, pos_y;
    sf::Font _font;
    sf::Color color;
    unsigned int Size;
    sf::RectangleShape m_background;
    sf::Text m_text;
    sf::RectangleShape m_cursor; // New member variable for the cursor
    bool m_selected;
    bool m_cursorVisible; // New member variable to keep track of cursor visibility
    sf::Clock m_cursorClock; // New member variable to keep track of elapsed time since last cursor toggle
    bool ShowTxt;
};

#endif // TEXT_FIELD_H
