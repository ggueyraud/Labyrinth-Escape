#ifndef LABYRINTHESCAPE_SLIDER_HPP
#define LABYRINTHESCAPE_SLIDER_HPP

#include "Button.hpp"

namespace ui{
    class Slider : public Widget {
    public:
        Slider(Widget* parent = nullptr);

        void setValue(uint8_t value);
        inline uint8_t getValue() const {
            return m_value;
        }
    private:
        virtual void update() override;
        virtual void handleEvent(const sf::Event& e) override;
        uint8_t m_value;
        Button m_button;
    };
}


#endif //LABYRINTHESCAPE_SLIDER_HPP
