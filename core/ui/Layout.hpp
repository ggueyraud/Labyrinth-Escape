#ifndef LABYRINTHESCAPE_LAYOUT_HPP
#define LABYRINTHESCAPE_LAYOUT_HPP

#include "Widget.hpp"

namespace ui{
    class Layout : public Widget {
        public:
            Layout(Widget* parent = nullptr);
            void addWidget(Widget* widget);
            void removeWidget(Widget* widget);

            virtual void handleEvent(const sf::Event& e) override{}

        private:
            virtual void update() override;
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

            uint8_t m_spacing = 3;
            std::vector<Widget*> m_widgets;
    };
}

#endif //LABYRINTHESCAPE_LAYOUT_HPP
