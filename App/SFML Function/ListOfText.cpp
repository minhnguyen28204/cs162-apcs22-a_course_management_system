#include "ListOfText.hpp"

TextList::TextList() {}

void TextList::addText(const std::string& text, const sf::Font& font, const unsigned int& charSize, const sf::Color& color) {
    sf::Text newText(text, font, charSize);
    newText.setFillColor(color);
    m_textList.push_back(newText);
}

void TextList::removeText(int index) {
    if (index >= 0 && index < m_textList.size()) {
        m_textList.erase(m_textList.begin() + index);
    }
}

std::string TextList::getText(int index) const {
    if (index >= 0 && index < m_textList.size()) {
        return m_textList[index].getString();
    }
    return "";
}

void TextList::draw(sf::RenderWindow& window, const sf::Vector2f& position) {
    for (unsigned int i = 0; i < m_textList.size(); i++) {
        sf::Text text = m_textList[i];
        text.setPosition(position.x, position.y + i * text.getCharacterSize());
        window.draw(text);
    }
}
