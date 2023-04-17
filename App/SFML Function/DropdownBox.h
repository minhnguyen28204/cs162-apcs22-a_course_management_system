#include <SFML/Graphics.hpp>
#include <vector>

class DropdownBox {
public:
    DropdownBox(sf::Vector2f position, sf::Vector2f size, std::vector<std::string> items) :
        m_showList(false),
        m_items(items)
    {
        // create the dropdown box rectangle
        m_dropdownBox.setSize(size);
        m_dropdownBox.setOutlineThickness(1);
        m_dropdownBox.setOutlineColor(sf::Color::Black);
        m_dropdownBox.setFillColor(sf::Color::White);
        m_dropdownBox.setPosition(position);

        // create the selected item text
        m_selectedItem.setFont(m_font);
        m_selectedItem.setCharacterSize(20);
        m_selectedItem.setString(items[0]);
        m_selectedItem.setPosition(position + sf::Vector2f(5, 5));

        // create the item background rectangle
        m_itemBackground.setSize(sf::Vector2f(size.x - 2, size.y - 2));
        m_itemBackground.setFillColor(sf::Color::White);
        m_itemBackground.setOutlineThickness(1);
        m_itemBackground.setOutlineColor(sf::Color::Black);

        // create the item texts
        for (int i = 0; i < items.size(); i++) {
            sf::Text itemText(items[i], m_font, 20);
            itemText.setPosition(position + sf::Vector2f(5, size.y + (i + 1) * size.y));
            m_itemTexts.push_back(itemText);
        }
    }

    void update(sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        // check if the dropdown box was clicked
        if (m_dropdownBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            m_showList = !m_showList;
        }

        // check if an item was clicked
        if (m_showList) {
            for (int i = 0; i < m_itemTexts.size(); i++) {
                if (m_itemTexts[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_selectedItem.setString(m_items[i]);
                    m_showList = false;
                }
            }
        }
    }

    void draw(sf::RenderWindow& window){
        // draw the dropdown box
        window.draw(m_dropdownBox);
        window.draw(m_selectedItem);

        // draw the item list if it's visible
        if (m_showList) {
            for (sf::Text itemText : m_itemTexts) {
                m_itemBackground.setPosition(itemText.getPosition() - sf::Vector2f(2, 2));
                window.draw(m_itemBackground);
                window.draw(itemText);
            }
        }
    }

    void setPosition(sf::Vector2f position) {
        m_dropdownBox.setPosition(position);
        m_selectedItem.setPosition(position + sf::Vector2f(5, 5));

        for (int i = 0; i < m_itemTexts.size(); i++) {
            m_itemTexts[i].setPosition(position + sf::Vector2f(5, m_dropdownBox.getSize().y + (i + 1) * m_dropdownBox.getSize().y));
        }
    }

    std::string getSelectedItem() {
        return m_selectedItem.getString();
    }

private:
    sf::RectangleShape m_dropdownBox;
    sf::Text m_selectedItem;
    bool m_showList;
    sf::RectangleShape m_itemBackground;
    std::vector<sf::Text> m_itemTexts;
    std::vector<std::string> m_items;
    sf::Font m_font;
};
