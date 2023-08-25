//
// Created by guill on 24/10/2018.
//

#ifndef LABYRINTHESCAPE_WORLD_HPP
#define LABYRINTHESCAPE_WORLD_HPP

#include "Map.hpp"
#include "Player.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

class World : sf::NonCopyable{
public:
    World();

    void handleEvent(const sf::Event& e);
    void update(sf::Time dt);
    void draw();

    void addCollision(const sf::RectangleShape& collision);

    void handleCollisions();
    Player& getPlayer();

private:
    std::vector<sf::RectangleShape> m_collisions;
    Player m_player;
    Map m_map;
};


#endif //LABYRINTHESCAPE_WORLD_HPP
