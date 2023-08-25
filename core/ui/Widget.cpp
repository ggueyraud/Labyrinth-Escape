#include "Widget.hpp"

namespace ui{
    Widget::Widget(Widget *parent) :
    m_parent(parent){

    }

    void Widget::setEnabled(bool enabled) {
        m_enabled = enabled;
    }

    void Widget::setVisible(bool visible) {
        m_visible = visible;
    }

    void Widget::setSize(float width, float height) {
        m_shape.setSize({width, height});
    }

    void Widget::setSize(const sf::Vector2f &size) {
        m_shape.setSize(size);
    }

    void Widget::addEvent(Widget::EventType onEvent, std::function<void()> callback) {
        m_events.emplace(onEvent, callback);
    }
}
