#include "ListOfText.hpp"

TextList::TextList()
{
    m_numTexts = 0;
    m_fillColor = sf::Color::White;
}

int TextList::SizeOfList(){
    return m_numTexts;
}

sf::Text TextList::Elements(int x){
    return m_texts[x];
}

void TextList::Equal(TextList other){
    m_numTexts = other.SizeOfList();
    for(int i=0; i<m_numTexts; i++){
        m_texts[i] = other.Elements(i);
    }
}

void TextList::addText(std::string text)
{
    if (m_numTexts >= MAX_TEXTS) {
        return;
    }

    sf::Text newText;
    newText.setString(text);
    newText.setFont(m_font);
    newText.setCharacterSize(24);
    newText.setFillColor(m_fillColor);
    m_texts[m_numTexts] = newText;
    m_numTexts++;
}

void TextList::setPosition(sf::Vector2f position)
{
    float yOffset = 0.0f;
    for (int i = 0; i < m_numTexts; i++)
    {
        sf::Text& text = m_texts[i];
        text.setPosition(position.x, position.y + yOffset);
        yOffset += text.getGlobalBounds().height + 30;
    }
}

void TextList::setFont(sf::Font& font)
{
    m_font = font;
    for (int i = 0; i < m_numTexts; i++)
    {
        sf::Text& text = m_texts[i];
        text.setFont(m_font);
    }
}

void TextList::setCharacterSize(unsigned int size)
{
    for (int i = 0; i < m_numTexts; i++)
    {
        sf::Text& text = m_texts[i];
        text.setCharacterSize(size);
    }
}

void TextList::setFillColor(sf::Color color)
{
    m_fillColor = color;
    for (int i = 0; i < m_numTexts; i++)
    {
        sf::Text& text = m_texts[i];
        text.setFillColor(m_fillColor);
    }
}

void TextList::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < m_numTexts; i++)
    {
        sf::Text& text = m_texts[i];
        window.draw(text);
    }
}
