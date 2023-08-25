#include "Layout.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>

namespace ui{
    Layout::Layout(Widget *parent) : Widget(parent) {
        m_shape.setFillColor(sf::Color::Blue);
    }

    void Layout::addWidget(Widget *widget) {
        m_widgets.push_back(widget);

        update();
    }

    void Layout::removeWidget(Widget *widget) {

    }

    void Layout::update(){
        //Ajout de base de la bordure du haut du conteneur
        float height = m_spacing;
        sf::Vector2f biggestWidget;

        //Boucle pour trouver les dimensions les plus grandes
        for(uint8_t i = 0; i < m_widgets.size(); i++){
            auto widgetSize = m_widgets[i]->getSize();

            if(widgetSize.x > biggestWidget.x)
                biggestWidget.x = widgetSize.x;
            if(widgetSize.y > biggestWidget.y)
                biggestWidget.y = widgetSize.y;
        }



        for(uint8_t i = 0; i < m_widgets.size(); i++){
            m_widgets[i]->setSize(biggestWidget);
            m_widgets[i]->setPosition(m_spacing, (biggestWidget.y + m_spacing) * i);
            height += biggestWidget.y;
        }

        setSize(biggestWidget.x + (m_spacing * 2), height + m_spacing);
    }

    void Layout::draw(sf::RenderTarget& target, sf::RenderStates states) const{
        states.transform *= getTransform();
        target.draw(m_shape, states);

        for(const auto& child : m_widgets)
            target.draw(*child, states);
    }
}
