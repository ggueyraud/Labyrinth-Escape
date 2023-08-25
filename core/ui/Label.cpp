#include "../AssetManager.hpp"
#include "Label.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

namespace ui{
    Label::Label(Widget *parent) : Widget(parent),
    m_text("", FontManager::getInstance().get("assets/arial_narrow_7.ttf"), 16) {
        m_text.setOutlineThickness(1);
        m_text.setOutlineColor(sf::Color::Black);
    }

    Label::Label(const std::string &text, Widget *parent) : Label(parent) {
        m_text.setString(text);
    }

    void Label::setText(const std::string &text) {
        m_text.setString(text);
    }

    void Label::center(const sf::Vector2f& size) {
        auto bounds = m_text.getLocalBounds();

        setPosition({
            (size.x - bounds.width) / 2,
            0
        });
    }

    sf::Vector2f Label::getSize() const {
        auto bound = m_text.getLocalBounds();
        return { bound.width, bound.height };
    }

    void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        states.transform *= getTransform();

        target.draw(m_text, states);
    }
}
