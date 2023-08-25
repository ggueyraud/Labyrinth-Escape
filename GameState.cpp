//
// Created by guill on 27/10/2018.
//

#include "core/AssetManager.hpp"
#include "core/Window.hpp"
#include "core/MusicPlayer.hpp"
#include "GameState.hpp"

#include <SFML/Window/Touch.hpp>

#include <iostream>

GameState::GameState() :
m_fpsText("fps : ", FontManager::getInstance().get("assets/arial_narrow_7.ttf"), 20),
m_btn1("My button"),
m_btn2("My button 2"),
m_btn3("My button 3"),
m_chk("Show FPS"){
    MusicPlayer::getInstance().play("assets/musics/bensound-instinct.ogg");
    m_btn1.addEvent(ui::Widget::EventType::Click, [](){

    });

    m_lyt.setPosition(100, 100);
    m_lyt.addWidget(&m_btn1);
    m_lyt.addWidget(&m_btn2);
    m_lyt.addWidget(&m_btn3);

    m_chk.addEvent(ui::Widget::EventType::Click, [this](){
        m_displayFPS = !m_displayFPS;
    });
    m_chk.setChecked(true);
    m_chk.setPosition(600, 10);
}

void GameState::handleEvent(const sf::Event &e) {
//    m_btn.handleEvent(e);
    m_chk.handleEvent(e);

    m_world.handleEvent(e);
}

void GameState::update(sf::Time dt) {
    m_world.update(dt);

    //m_player.update(dt);

    updateStatistics(dt);
}

void GameState::updateStatistics(sf::Time dt) {
    m_statisticsUpdateTime += dt;
    m_statisticsNbFrames++;

    if(m_statisticsUpdateTime >= sf::seconds(1.0f)){
        m_fpsText.setString("fps : " + std::to_string(m_statisticsNbFrames));
        m_statisticsUpdateTime = sf::Time::Zero;
        m_statisticsNbFrames = 0;
    }
}

void GameState::draw() {
    m_world.draw();

    if(m_displayFPS)
        Window::getInstance().draw(m_fpsText);
    Window::getInstance().draw(m_lyt);
    Window::getInstance().draw(m_chk);
}
