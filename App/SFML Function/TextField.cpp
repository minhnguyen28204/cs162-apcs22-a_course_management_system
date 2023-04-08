#include "TextField.h"

TextField::TextField(sf::Font& font, unsigned int size, sf::Color _color, float x, float y, float width, float height, bool showText = true)
    : m_selected(false), m_cursorVisible(false)
{
    m_background.setSize(sf::Vector2f(width, height));
    m_background.setPosition(x, y);
    m_background.setFillColor(sf::Color::White);
    m_background.setOutlineThickness(1);
    m_background.setOutlineColor(sf::Color::Black);

    m_text.setFont(font);
    m_text.setCharacterSize(size);
    m_text.setFillColor(color);
    m_text.setPosition(x + 10, y + 10);

    m_cursor.setSize(sf::Vector2f(1, size));
    m_cursor.setFillColor(color);
    m_cursor.setPosition(x + 10, y + 10);

    pos_x = x;
    pos_y = y;
    _font = font;
    Size = size;
    color = _color;

    ShowTxt = showText;

    handleEvent(sf::Event()); // To initialize the text field with an empty string
}

void TextField::clear_str(){
    m_text.setString("");
}

void TextField::Tab_handle(){
    if (m_selected) m_selected = false;
    else m_selected = true;
}

bool TextField::cur_state(){
    return m_selected;
}

void TextField::draw(sf::RenderWindow& window)
{
    window.draw(m_background);
    if (ShowTxt==true) window.draw(m_text);
    else{
        sf::Text tmp;
        std::string temp = "";
        for(int i=0; i<m_text.getString().getSize(); i++) temp += "*";
        tmp.setString(temp);
        tmp.setFont(_font);
        tmp.setCharacterSize(Size);
        tmp.setColor(color);
        tmp.setPosition(pos_x+10,pos_y+10);
        window.draw(tmp);
    }

    if (m_selected && m_cursorVisible)
    {
        window.draw(m_cursor);
    }
}

void TextField::handleEvent(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
        if (m_background.getGlobalBounds().contains(mousePos))
        {
            m_selected = true;
        }
        else
        {
            m_selected = false;
        }
    }
    else if (event.type == sf::Event::TextEntered && m_selected)
    {
        if (event.text.unicode == '\b' && m_text.getString().getSize() > 0) // Handle backspace
        {
            m_text.setString(m_text.getString().substring(0, m_text.getString().getSize() - 1));
        }
        else if (event.text.unicode >= 32 && event.text.unicode <= 126 && m_text.getLocalBounds().width < m_background.getLocalBounds().width - 10) // Handle printable characters
        {
            m_text.setString(m_text.getString() + static_cast<char>(event.text.unicode));
        }
    }

    // Handle cursor blinking
    if (m_selected)
    {
        float elapsedTime = m_cursorClock.getElapsedTime().asSeconds();
        if (elapsedTime >= 0.5f)
        {
            m_cursorVisible = !m_cursorVisible;
            m_cursorClock.restart();
        }

        if (ShowTxt) m_cursor.setPosition(m_text.getPosition().x + m_text.getLocalBounds().width + 4, m_text.getPosition().y);
        else{
            sf::Text tmp;
            std::string temp = "";
            for(int i=0; i<m_text.getString().getSize(); i++) temp += "*";
            tmp.setString(temp);
            tmp.setFont(_font);
            tmp.setCharacterSize(Size);
            tmp.setColor(color);
            tmp.setPosition(pos_x+10,pos_y+10);
            m_cursor.setPosition(tmp.getPosition().x + tmp.getLocalBounds().width + 4, tmp.getPosition().y);
        }
    }
    else
    {
        m_cursorVisible = false;
    }
}

std::string TextField::getText() const
{
    return m_text.getString();
}
