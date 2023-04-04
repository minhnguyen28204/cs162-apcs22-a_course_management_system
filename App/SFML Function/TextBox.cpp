#include "TextBox.h"

TextBox::TextBox(float x, float y, float width, float height, sf::Font& font, std::string str, int size)
{
    m_box.setPosition(x,y);
    sf::Vector2f Size(width,height);
    m_box.setSize(Size);
    m_box.setFillColor(sf::Color::White);
    m_box.setOutlineColor(sf::Color::Black);
    m_box.setOutlineThickness(1.0f);

    m_text.setFont(font);
    m_text.setString(str);
    m_text.setCharacterSize(size);
    m_text.setColor(sf::Color::Black);

    float centerX = x + width / 2.0f;
    float centerY = y + height / 2.0f;
    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    m_text.setPosition(centerX,centerY);
}

void TextBox::draw(sf::RenderWindow& window)
{
    window.draw(m_box);
    window.draw(m_text);
}
