#ifndef LABYRINTHESCAPE_CHECKBOX_HPP
#define LABYRINTHESCAPE_CHECKBOX_HPP

#include "AbstractButton.hpp"

namespace ui{
    class CheckBox : public AbstractButton{
        public:
            CheckBox(Widget* parent = nullptr);
            CheckBox(const std::string& text, Widget* parent = nullptr);

            virtual sf::Vector2f getSize() const override;
        private:
            virtual void update() override;
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

            sf::RectangleShape m_checkBox;
    };
}

#endif //LABYRINTHESCAPE_CHECKBOX_HPP
