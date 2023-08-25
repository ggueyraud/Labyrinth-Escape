#include "Window.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include "../Window.hpp"
#include <iostream>

namespace ui{
    Window::Window(Widget* parent) : Widget(parent),
    m_windowLabel("Titre de la fenêtre"),
    m_closeButton("x"){
        setSize(200, 100);

        //m_manager.addWidget(&m_closeButton);
        //m_manager.addWidget(&m_windowLabel);

        //Si le clique le bouton de fermeture de la fenêtre est détecté
        //alors on masque la fenêtre
        m_closeButton.addEvent(Widget::EventType::Click, [this](){
            setVisible(false);
        });

        //Titlebar configuration
        m_titleBar.setFillColor(sf::Color::Blue);
        m_titleBar.setSize({200, 30});

        update();
    }

    Window::Window(const std::string& title, const sf::Vector2f& size, Widget* parent) : Widget(parent){
        setSize(size);
    }

    void Window::setTitle(const std::string& title){
        m_windowLabel.setText(title);
    }

    void Window::handleEvent(const sf::Event& e){
        m_manager.handleEvent(e);

        m_closeButton.handleEvent(e);

        const auto mp = ::Window::getInstance().getMousePosition();
        const auto titleBarBounds = m_titleBar.getGlobalBounds();

        std::cout << "Window pos [x: " << titleBarBounds.left << "; y : " << titleBarBounds.top << "]" << std::endl;

        //Si le curseur de la personne est dans la titlebar
        if(mp.x >= titleBarBounds.left &&
           mp.x < titleBarBounds.left + titleBarBounds.width &&
           mp.y >= titleBarBounds.top &&
           mp.y < titleBarBounds.top + titleBarBounds.height){
            // La fenêtre est sélectionnée
            if(m_drag){
                if(e.type == sf::Event::MouseButtonReleased &&
                   e.mouseButton.button == sf::Mouse::Left && m_drag){
                    m_drag = false;
                }else if(e.type == sf::Event::MouseMoved){
                    const auto titleBarBounds = m_titleBar.getGlobalBounds();

                    setPosition(
                        e.mouseMove.x - m_oldPos.x,
                        e.mouseMove.y - m_oldPos.y
                    );

                    update();
                }
            }else{
                if(e.type == sf::Event::MouseButtonPressed &&
                   e.mouseButton.button == sf::Mouse::Left){
                    m_drag = true;
                    m_oldPos = sf::Vector2i(e.mouseButton.x - (int)getPosition().x, e.mouseButton.y - (int)getPosition().y);
                }
            }
        }
    }

    void Window::update(){
        const auto size = getSize();
        const auto position = getPosition();

        m_titleBar.setPosition(position);

        std::cout << "Window pos [x: " << m_titleBar.getPosition().x << "; y : " << m_titleBar.getPosition().y << "]" << std::endl;

        /*m_titleBar.setPosition({
            position.x,
            position.y - m_titleBar.getGlobalBounds().height
        });*/

        /*setPosition(
            position.x,
            position.y + m_titleBar.getGlobalBounds().height
        );*/

        m_closeButton.setPosition(
            size.x - m_closeButton.getSize().x - 5,
            5
        );
    }

    void Window::draw(sf::RenderTarget& target, sf::RenderStates states) const{
        states.transform *= getTransform();

        target.draw(m_shape, states);
        target.draw(m_titleBar);
        target.draw(m_windowLabel, states);
        target.draw(m_closeButton, states);

        //m_manager.draw();
    }
}
