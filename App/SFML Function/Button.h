#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button : public sf::Drawable, public sf::Transformable
{
public:
    Button(){}
    Button(sf::Sprite sp, unsigned int Size, float x, float y, float width, float height, const std::string& text, const std::function<void()>& onClick)
    {
        // Load the hover image
        image = sp;
        image.setPosition(x-50,y);

        // Load the font
        font_.loadFromFile("resources/font.ttf");

        // Create the rectangle shape
        shape_.setPosition(x, y);
        shape_.setSize(sf::Vector2f(width, height));
        shape_.setFillColor(sf::Color::White);
        shape_.setOutlineThickness(2);
        shape_.setOutlineColor(sf::Color::Black);

        // Create the text
        text_.setFont(font_);
        text_.setString(text);
        text_.setCharacterSize(Size);
        text_.setFillColor(sf::Color::Black);
        sf::FloatRect textBounds = text_.getLocalBounds();
        text_.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
        text_.setPosition(x + width / 2, y + height / 2);

        // Set the on-click callback
        onClick_ = std::function<void()>(onClick);
    }

    bool contains(float x, float y) const
    {
        return shape_.getGlobalBounds().contains(x, y);
    }

    void handleMouseMoved(float x, float y)
    {
        if (contains(x, y))
        {
            isdraw = true;
            shape_.setFillColor(sf::Color(200, 200, 200));
        }
        else
        {
            isdraw = false;
            shape_.setFillColor(sf::Color::White);
        }
    }

    void onClick()
    {
        onClick_();
    }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(shape_, states);
        target.draw(text_, states);
        if (isdraw) target.draw(image, states);
    }
    sf::Sprite image;
    bool isdraw;
    sf::RectangleShape shape_;
    sf::Text text_;
    sf::Font font_;
    std::function<void()> onClick_;
};

class ButtonLibrary
{
public:
    ButtonLibrary() : buttonCount_(0) {}

    void addButton(const Button& button)
    {
        buttons_[buttonCount_++] = button;
    }

    void handleEvent(sf::Event event)
    {
        if (event.type == sf::Event::MouseMoved){
            for(int i = 0; i < buttonCount_; ++i){
                buttons_[i].handleMouseMoved(event.mouseMove.x, event.mouseMove.y);
            }
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            for (int i = 0; i < buttonCount_; ++i)
            {
                if (buttons_[i].contains(event.mouseButton.x, event.mouseButton.y))
                {
                    buttons_[i].onClick();
                }
            }
        }
    }

    void draw(sf::RenderTarget& target) const
    {
        for (int i = 0; i < buttonCount_; ++i)
        {
            target.draw(buttons_[i]);
        }
    }

private:
    static const int MAX_BUTTONS = 100;
    Button buttons_[MAX_BUTTONS];
    int buttonCount_;
};
