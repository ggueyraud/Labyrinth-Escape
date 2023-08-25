//
// Created by guill on 28/10/2018.
//

#ifndef LABYRINTHESCAPE_CHARACTER_HPP
#define LABYRINTHESCAPE_CHARACTER_HPP

#include "Entity.hpp"

class Enemy : public Entity{
public:
    enum class Type{
        Player,
        Ennemy
    };

    Enemy(Type type, const sf::Texture& texture);
private:
    Type m_type;
    uint8_t m_health = 3;
};


#endif //LABYRINTHESCAPE_CHARACTER_HPP
