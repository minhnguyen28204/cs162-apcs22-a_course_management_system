#include "ScrollableWindow.hpp"

ScrollableWindow::ScrollBar::ScrollBar(const sf::RenderWindow& window, const sf::View& view)
    : bar_(sf::Vector2f(10, window.getSize().y))
    , slider_(sf::Vector2f(10, window.getSize().y / view.getSize().y * window.getSize().y))
    , sliderLength_(slider_.getSize().y)
{
    bar_.setPosition(window.getSize().x - 10, 0);
    slider_.setPosition(window.getSize().x - 10, 0);
}

void ScrollableWindow::ScrollBar::update(const sf::View& view)
{
    float viewHeight = view.getSize().y;
    float windowHeight = bar_.getSize().y;
    float viewTop = view.getCenter().y - viewHeight / 2;
    float scrollRatio = viewTop / (windowHeight - viewHeight);
    slider_.setPosition(bar_.getPosition().x, scrollRatio * (windowHeight - sliderLength_));
}

void ScrollableWindow::ScrollBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(bar_, states);
    target.draw(slider_, states);
}

ScrollableWindow::ScrollableWindow(int width, int height, const std::string& title)
    : window_(sf::VideoMode(width, height), title)
    , view_(sf::FloatRect(0, 0, width, height))
    , scrollBar_(window_, view_) // pass window_ and view_ to the ScrollBar constructor
{
    window_.setView(view_);
}

void ScrollableWindow::addDrawable(sf::Drawable* drawable)
{
    drawables_.push_back(drawable);
}
void ScrollableWindow::run()
{
    while (window_.isOpen()) {
        handleEvents();

        window_.clear(sf::Color::White);
        for (auto drawable : drawables_) {
            window_.draw(*drawable);
        }
        window_.display();
    }
}

void ScrollableWindow::handleEvents()
{
    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window_.close();
        }
        else if (event.type == sf::Event::MouseWheelScrolled) {
            view_.move(0, -event.mouseWheelScroll.delta * 10);
            window_.setView(view_);
        }
    }
}
