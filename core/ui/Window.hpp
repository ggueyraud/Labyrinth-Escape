#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "Manager.hpp"
#include "Button.hpp"

namespace ui{
    class Window : public Widget{
        public:
            Window(Widget* parent = nullptr);
            // TODO : checker la pertinence des widgets à size decimal
            Window(const std::string& title, const sf::Vector2f& size = {100, 100}, Widget* parent = nullptr);

            void setTitle(const std::string& title);

            virtual void handleEvent(const sf::Event& e) override;

        private:
            virtual void update() override;
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
            sf::RectangleShape m_titleBar;
            Label m_windowLabel;

            bool m_drag = false;
            sf::Vector2i m_oldPos;

            Button m_closeButton;
            Manager m_manager;
    };
}

#endif // WINDOW_HPP_INCLUDED
