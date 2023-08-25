#ifndef LABYRINTHESCAPE_BUTTON_HPP
#define LABYRINTHESCAPE_BUTTON_HPP

#include "AbstractButton.hpp"

namespace ui{
    class Button : public AbstractButton {
        public:
            Button(Widget* parent = nullptr);
            Button(const std::string& text, Widget* parent = nullptr);

            virtual sf::Vector2f getSize() const override;

    //    virtual void handleEvent(const sf::Event& e) override;
    };
}

#endif //LABYRINTHESCAPE_BUTTON_HPP
