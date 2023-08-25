//
// Created by guill on 28/10/2018.
//

#include "Enemy.hpp"

Enemy::Enemy(Enemy::Type type, const sf::Texture &texture) : Entity(texture),
m_type(type){

}