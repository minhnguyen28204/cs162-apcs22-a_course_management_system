#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <string>

class TextBox {
public:
    TextBox(float x, float y, float width, float height, sf::Font& font, std::string str, int Size);
    TextBox();
    void SetDetail(float x, float y, float width, float height, sf::Font& font, std::string str, int Size);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape m_box;
    sf::Text m_text;
};

#endif

