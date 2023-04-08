#ifndef TEXTLIST_H
#define TEXTLIST_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class TextList {
public:
    TextList();
    void addText(const std::string& text, const sf::Font& font, const unsigned int& charSize, const sf::Color& color);
    void removeText(int index);
    std::string getText(int index) const;
    void draw(sf::RenderWindow& window, const sf::Vector2f& position);

private:
    std::vector<sf::Text> m_textList;
};

#endif
