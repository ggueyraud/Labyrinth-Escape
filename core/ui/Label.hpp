#ifndef LABYRINTHESCAPE_LABEL_HPP
#define LABYRINTHESCAPE_LABEL_HPP

#include "Widget.hpp"

#include <SFML/Graphics/Text.hpp>

namespace ui{
    class Label : public Widget{
    public:
        Label(Widget* parent = nullptr);
        Label(const std::string& text, Widget* parent = nullptr);

        void setText(const std::string& text);
        inline std::string getText() const {
            return m_text.getString();
        }

        void center(const sf::Vector2f& size);

        virtual sf::Vector2f getSize() const override;
    private:
        virtual void handleEvent(const sf::Event& e) override {}
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        sf::Text m_text;
    };
}

#endif //LABYRINTHESCAPE_LABEL_HPP
