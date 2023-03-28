#include <SFML/Graphics.hpp>
#include <string>

class PasswordField : public sf::RectangleShape {
private:
    sf::Font _font;
    unsigned int _textSize;
    sf::Color _textColor;
    sf::Vector2f _dimensions;
    std::string _text;
    bool _showText;

public:
    PasswordField(const sf::Vector2f& position, const sf::Vector2f& dimensions, const sf::Font& font, unsigned int textSize, const sf::Color& textColor)
        : _font(font)
        , _textSize(textSize)
        , _textColor(textColor)
        , _dimensions(dimensions)
        , _text("")
        , _showText(false)
    {
        setPosition(position);
        setFillColor(sf::Color::White);
        setSize(dimensions);
    }

    void setText(const std::string& text) { _text = text; }
    std::string getText() const { return _text; }
    void setShowText(bool showText) { _showText = showText; }

    void draw(sf::RenderTarget& target)
    {
        std::string displayText = _text;
        if (_showText == false) {
            displayText = std::string(_text.length(), '*');
        }

        sf::Text text(displayText, _font, _textSize);
        text.setFillColor(_textColor);
        text.setPosition(sf::Vector2f(0, 0));
        text.setStyle(sf::Text::Regular);

        sf::RenderTexture texture;
        texture.create(_dimensions.x, _dimensions.y);
        texture.clear(sf::Color::Transparent);

        texture.draw(text);
        texture.display();
        sf::Sprite sprite(texture.getTexture());

        target.draw(sprite);
    }

    void handleEvent(const sf::Event& event)
    {
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == '\b' && _text.size() > 0) {
                _text.erase(_text.size() - 1);
            }
            else if (event.text.unicode < 128) {
                _text += static_cast<char>(event.text.unicode);
            }
        }
    }
};

