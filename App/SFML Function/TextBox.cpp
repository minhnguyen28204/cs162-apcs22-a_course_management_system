#include "textbox.h"

TextBox::TextBox(float x, float y, float width, float height, sf::Font& font, std::string str)
{
    m_box.setPosition(x,y);
    sf::Vector2f Size(width,height);
    m_box.setSize(Size);
    m_box.setFillColor(sf::Color::White);
    m_box.setOutlineColor(sf::Color::Black);
    m_box.setOutlineThickness(1.0f);

    m_text.setFont(font);
    m_text.setString(str);
    m_text.setCharacterSize(24);
    m_text.setColor(sf::Color::Black);
    m_text.setPosition(x + 10.0f, y + 10.0f);
}

void TextBox::draw(sf::RenderWindow& window)
{
    window.draw(m_box);
    window.draw(m_text);
}
