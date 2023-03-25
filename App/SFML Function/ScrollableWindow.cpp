#include "ScrollableWindow.hpp"

ScrollableWindow::ScrollableWindow(int width, int height, const std::string& title)
    : window_(sf::VideoMode(width, height), title)
    , view_(sf::FloatRect(0, 0, width, height))
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

        window_.clear();
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
