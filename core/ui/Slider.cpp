#include "Slider.hpp"

namespace ui{
    Slider::Slider(Widget *parent) : Widget(parent) {

    }

    void Slider::setValue(uint8_t value) {
        m_value = value;
    }

    void Slider::update() {
        //TODO : à implémenter
    }

    void Slider::handleEvent(const sf::Event &e) {
        //TODO : à implémenter
    }
}
