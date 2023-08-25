#ifndef LABYRINTHESCAPE_MANAGER_HPP
#define LABYRINTHESCAPE_MANAGER_HPP

#include "Widget.hpp"

#include <vector>

namespace ui{
    class Manager {
        public:
            void addWidget(Widget* widget);
            void clear();

            void handleEvent(const sf::Event& e);
            void update();

            void draw() const;

        private:
            std::vector<Widget*> m_widgets;
    };
}

#endif //LABYRINTHESCAPE_MANAGER_HPP
