#include "EditorState.hpp"

#include <iostream>

#include <SFML/Window/Event.hpp>
#include "core/Window.hpp"

#include "core/MusicPlayer.hpp"

EditorState::EditorState() : m_map(&m_world){
    //m_uiManager.addWidget(&m_window);
    //m_uiManager.addWidget(&mf);

    /*m_musicBtn.addEvent(ui::Widget::EventType::Click, [this](){
        auto &musicPlayer = MusicPlayer::getInstance();

        if(musicPlayer.getStatus() == sf::Music::Playing)
            musicPlayer.pause();
        else
            musicPlayer.play("assets/musics/bensound-instinct.ogg");
    });

    m_uiManager.addWidget(&m_musicBtn);*/
}

void EditorState::update(sf::Time dt){
    m_world.update(dt);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        auto mp = Window::getInstance().getMousePosition();
        sf::RectangleShape shape({32, 32});
        shape.setFillColor({255, 0, 0, 100});
        shape.setPosition(((int)mp.x / 32) * 32, ((int)mp.y / 32) * 32);
        m_world.addCollision(shape);
    }
}

void EditorState::handleEvent(const sf::Event& e){
    m_uiManager.handleEvent(e);
    m_world.handleEvent(e);

    if(e.type == sf::Event::MouseButtonPressed){
        if(e.mouseButton.button == sf::Mouse::Right){

        }else if(e.mouseButton.button == sf::Mouse::Left){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
                auto mp = Window::getInstance().getMousePosition();
                m_world.getPlayer().setPosition(((int)mp.x / 32) * 32, ((int) mp.y / 32) * 32);
            }
        }
    }
}

void EditorState::draw(){
    m_world.draw();

    m_uiManager.draw();
}
