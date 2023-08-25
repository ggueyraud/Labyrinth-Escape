//
// Created by Guillaume on 18/02/2019.
//

#include "Frame.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

namespace ui{
    Frame::Frame(Widget *parent) : Widget(parent), m_s({20, 20}){
        m_s.setFillColor(sf::Color::Red);
    }

    void Frame::draw(sf::RenderTarget& target, sf::RenderStates states) const{
        //target.setView(m_view);

        target.draw(m_s, states);
    }
}