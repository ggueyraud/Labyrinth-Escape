#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include <SFML/Graphics/View.hpp>
#include "Widget.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
namespace ui{
    class Frame : public Widget{
        public:
            Frame(Widget *parent = nullptr);

            virtual void handleEvent(const sf::Event& e) override{}
        private:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
            sf::RectangleShape m_s;
            sf::View m_view;
    };
}

#endif // FRAME_HPP_INCLUDED
