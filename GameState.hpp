//
// Created by guill on 27/10/2018.
//

#ifndef LABYRINTHESCAPE_GAMESTATE_HPP
#define LABYRINTHESCAPE_GAMESTATE_HPP

#include "core/State.hpp"
#include "core/World.hpp"

#include "core/ui/Button.hpp"
#include "core/ui/CheckBox.hpp"
#include "core/ui/Layout.hpp"

#include <SFML/Graphics/Text.hpp>

#include <SFML/System/Time.hpp>

class GameState : public State{
public:
    GameState();

    virtual void handleEvent(const sf::Event& e) override;
    virtual void update(sf::Time dt) override;
    virtual void draw() override;
private:
    void updateStatistics(sf::Time dt);

    sf::Time m_statisticsUpdateTime;
    uint16_t m_statisticsNbFrames = 0;
    World m_world;
    ui::Layout m_lyt;
    ui::Button m_btn1, m_btn2, m_btn3;
    ui::CheckBox m_chk;
    sf::Text m_fpsText;
    bool m_displayFPS = true;
};


#endif //LABYRINTHESCAPE_GAMESTATE_HPP
