#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button : public sf::Drawable, public sf::Transformable
{
public:
    Button(){}
    Button(float x, float y, float width, float height, const std::string& text, const std::function<void()>& onClick)
    {
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
        text_.setCharacterSize(24);
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
            shape_.setFillColor(sf::Color(200, 200, 200));
        }
        else
        {
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
    }

    sf::RectangleShape shape_;
    sf::Text text_;
    sf::Font font_;
    std::function<void()> onClick_;
};

class ButtonLibrary
{
public:
    void addButton(const Button& button)
    {
        buttons_.push_back(button);
    }

    void handleEvent(sf::Event event)
    {
        if (event.type == sf::Event::MouseMoved){
            for(auto& button : buttons_){
                button.handleMouseMoved(event.mouseMove.x, event.mouseMove.y);
            }
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            for (auto& button : buttons_)
            {
                if (button.contains(event.mouseButton.x, event.mouseButton.y))
                {
                    button.onClick();
                }
            }
        }
    }

    void draw(sf::RenderTarget& target) const
    {
        for (const auto& button : buttons_)
        {
            target.draw(button);
        }
    }

private:
    std::vector<Button> buttons_;
};
