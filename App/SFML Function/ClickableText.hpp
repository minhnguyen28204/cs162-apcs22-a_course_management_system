#ifndef CLICKABLETEXT_HPP
#define CLICKABLETEXT_HPP

#include <SFML/Graphics.hpp>
#include <string>

struct ClickableText{
private:
    sf::Text m_text;
    sf::Color c1, c2;
    bool is_on;

public:
    ClickableText(std::string str,unsigned int Size, sf::Font& _font, float x, float y, sf::Color color1, sf::Color color2);
    void draw(sf::RenderWindow &window);
    void handleEvent(const sf::RenderWindow &window) ;
};

#endif // CLICKABLETEXT_HPP
