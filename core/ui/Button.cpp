#include "Button.hpp"

namespace ui{
    Button::Button(Widget *parent) : AbstractButton(parent) {

    }

    Button::Button(const std::string &text, Widget *parent) : AbstractButton(text, parent) {

    }

    sf::Vector2f Button::getSize() const{
        return m_shape.getSize();
    }
}
