//
// Created by guill on 27/10/2018.
//

#include "Window.hpp"
#include "StateManager.hpp"

#include <SFML/Window/Event.hpp>

Window::Window() {
    create();
}

void Window::update(sf::Time dt) {
    sf::Event e;

    while(m_window.pollEvent(e)){
        StateManager::getInstance().handleEvent(e);

        if(e.type == sf::Event::Closed)
            m_isDone = true;
        else if(e.type == sf::Event::Resized){
            m_size = {e.size.width, e.size.height};
            m_window.setView(sf::View({0, 0, static_cast<float>(m_size.x), static_cast<float>(m_size.y)}));
        }else if(e.type == sf::Event::KeyPressed){
            if(e.key.code == sf::Keyboard::F11)
                toggleFullscreen(m_style == Style::Fullscreen ? true : false);
        }
    }

    StateManager::getInstance().update(dt);
}

void Window::render() {
    m_window.clear();

    StateManager::getInstance().draw();

    m_window.display();
}

void Window::draw(const sf::Drawable &drawable) {
    m_window.draw(drawable);
}

void Window::create() {
    m_window.create({m_size.x, m_size.y}, m_title, m_style);
    m_window.setFramerateLimit(m_fps);
}

void Window::toggleFullscreen(bool windowed) {
    m_style = windowed ? WindowedFullScreen : Fullscreen;
    m_size = {sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height};

    m_window.close();
    create();
}