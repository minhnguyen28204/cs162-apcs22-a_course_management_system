#include "ClickableText.hpp"

ClickableText::ClickableText(std::string str,unsigned int Size, sf::Font& _font, float x, float y, sf::Color co1, sf::Color co2) : is_on(false)
{
    c1 = co1;
    c2 = co2;
    m_text.setString(str);
    m_text.setCharacterSize(Size);
    m_text.setFont(_font);
    m_text.setColor(c1);
    m_text.setPosition(x,y);
}

void ClickableText::draw(sf::RenderWindow &window){
    window.draw(m_text);
}

void ClickableText::handleEvent(const sf::RenderWindow &window)  {
    if (m_text.getLocalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))){
        m_text.setColor(c2);
    }
    else m_text.setColor(c1);
}
