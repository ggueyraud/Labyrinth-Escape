#ifndef LABYRINTHESCAPE_WIDGET_HPP
#define LABYRINTHESCAPE_WIDGET_HPP

#include <SFML/Graphics/RectangleShape.hpp>

#include <SFML/Window/Event.hpp>

#include <SFML/System/NonCopyable.hpp>

#include <functional>
#include <unordered_map>

namespace ui{
    class Widget : public sf::Drawable, public sf::Transformable, sf::NonCopyable {
    public:
        enum class EventType{
            Click
        };

        Widget(Widget* parent = nullptr);

        void setEnabled(bool enabled);
        inline bool isEnabled() const {
            return m_enabled;
        }

        void setVisible(bool visible);
        inline bool isVisible() const {
            return m_visible;
        }

        void setSize(float width, float height);
        void setSize(const sf::Vector2f& size);
        inline virtual sf::Vector2f getSize() const {
            return m_shape.getSize();
        }

        void addEvent(EventType onEvent, std::function<void()> callback);

        //TODO : à passer en privée
        virtual void handleEvent(const sf::Event& e) = 0;

    protected:
        sf::RectangleShape m_shape;
        std::unordered_map<EventType, std::function<void()>> m_events;

    private:
        virtual void update() {}
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

        bool    m_enabled = true,
                m_visible = true;
        Widget* m_parent = nullptr;
    };
}

#endif //LABYRINTHESCAPE_WIDGET_HPP
