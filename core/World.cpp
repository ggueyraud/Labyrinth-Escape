//
// Created by guill on 24/10/2018.
//

#include "World.hpp"
#include "Window.hpp"
#include "AssetManager.hpp"
#include "Map.hpp"

World::World() : m_map(this){}

void World::handleEvent(const sf::Event& e){
    m_player.processEvents(e);
}

void World::update(sf::Time dt) {
    sf::Vector2f playerPos = m_player.getPosition();

    m_player.update(dt);
    const sf::FloatRect rect(m_player.getPosition(), m_player.getSize());

    for(const auto& collision : m_collisions)
        if(collision.getGlobalBounds().intersects(rect)){
            m_player.setPosition(playerPos);
            break;
        }
}

void World::draw() {
    Window::getInstance().draw(m_map);
    Window::getInstance().draw(m_player);

    for(const auto& collision : m_collisions)
        Window::getInstance().draw(collision);
}

void World::addCollision(const sf::RectangleShape& collision){
    m_collisions.push_back(collision);
}

Player& World::getPlayer(){
    return m_player;
}
