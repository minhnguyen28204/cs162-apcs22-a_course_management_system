#ifndef TEXT_LIST_H
#define TEXT_LIST_H
#include <SFML/Graphics.hpp>
#include <string>

const int MAX_TEXTS = 15;

class TextList
{
public:
    TextList();
    void addText(std::string text);
    void setPosition(sf::Vector2f position);
    void setFont(sf::Font& font);
    void setCharacterSize(unsigned int size);
    void setFillColor(sf::Color color);
    void draw(sf::RenderWindow& window);
    int SizeOfList();
    sf::Text Elements(int x);
    void Equal(TextList other);
private:
    sf::Text m_texts[MAX_TEXTS];
    int m_numTexts;
    sf::Font m_font;
    sf::Color m_fillColor;
};

#endif
