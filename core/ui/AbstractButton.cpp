#include "AbstractButton.hpp"
#include "../Window.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

namespace ui{
    AbstractButton::AbstractButton(Widget *parent) : Widget(parent) {

    }

    AbstractButton::AbstractButton(const std::string& text, Widget *parent) : Widget(parent),
    m_label(text, parent){
        update();
    }

    void AbstractButton::setChecked(bool checked) {
        m_checked = checked;
    }

    sf::Vector2f AbstractButton::getSize() const {
        auto labelSize = m_label.getSize();

        return {labelSize.x, labelSize.y};
    }

    void AbstractButton::update() {
        auto labelSize = m_label.getSize();
        m_shape.setSize({labelSize.x + 10, labelSize.y + 6});
        m_label.center(m_shape.getSize());
        m_shape.setFillColor(m_drawColor);
    }

    //TODO : empêcher l'update du widget à chaque fois que la méthode est appelée
    void AbstractButton::handleEvent(const sf::Event &e) {
        auto mp = Window::getInstance().getMousePosition();
        m_drawColor = m_backgroundColor;

        if(mp.x >= getPosition().x &&
           mp.x <= getPosition().x + getSize().x &&
           mp.y >= getPosition().y &&
           mp.y <= getPosition().y + getSize().y) {
            m_drawColor = m_hoverColor;

            if(e.type == sf::Event::MouseButtonPressed &&
               e.mouseButton.button == sf::Mouse::Left) {
                m_drawColor = m_clickColor;
                m_checked = !m_checked;

                auto found = m_events.find(Widget::EventType::Click);
                if(found != m_events.end())
                    found->second();

            }else if(e.type == sf::Event::MouseButtonReleased &&
                     e.mouseButton.button == sf::Mouse::Left){
                //Fix le hover après un click
            }
        }

        update();
    }

    void AbstractButton::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        states.transform *= getTransform();

        target.draw(m_shape, states);
        target.draw(m_label, states);
    }
}
