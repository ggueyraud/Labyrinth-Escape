#include "CheckBox.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

namespace ui{
    CheckBox::CheckBox(Widget *parent) : AbstractButton(parent) {
        update();
    }

    CheckBox::CheckBox(const std::string &text, Widget *parent) : AbstractButton(text, parent) {
        update();
    }

    sf::Vector2f CheckBox::getSize() const{
        auto parentSize = AbstractButton::getSize();
        parentSize.x += m_shape.getSize().x + 4;

        return parentSize;
    }

    void CheckBox::update() {
        AbstractButton::update();

        m_shape.setSize({20, 20});
        m_checkBox.setSize({10, 10});
        m_checkBox.setPosition({5, 5});
        m_label.setPosition(24, 0);
    }

    void CheckBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        AbstractButton::draw(target, states);

        states.transform *= getTransform();

        if(isChecked())
            target.draw(m_checkBox, states);
    }
}
