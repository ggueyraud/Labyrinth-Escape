#include "Entity.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

Entity::Entity(const sf::Texture &texture) :
m_sprite(texture){

}

Entity::Entity(const sf::Texture &texture, const sf::IntRect &rect) :
m_sprite(texture, rect){

}

void Entity::setVelocity(float vx, float vy) {
    m_velocity.x = vx;
    m_velocity.y = vy;
}

void Entity::setVelocity(const sf::Vector2f &velocity) {
    m_velocity = velocity;
}

void Entity::addAnimation(const std::string &name, Animation::Ptr animation) {
    if(!m_currentAnimation)
        m_currentAnimation = animation.get();

    m_animations.emplace(name, std::move(animation));
}

void Entity::playAnimation(const std::string &name) {
    auto found = m_animations.find(name);

    if(found->second.get() != m_currentAnimation){
        if(m_currentAnimation){
            m_currentAnimation->setState(Animation::State::Stop);
        }

        if(found != m_animations.end()){
            m_currentAnimation = found->second.get();

            m_currentAnimation->m_currentFrame = 0;
            m_currentAnimation->updateFrame();

            m_currentAnimation->setState(Animation::State::Play);
        }
    }else{
        m_currentAnimation->setState(Animation::State::Play);
    }
}

void Entity::update(sf::Time dt) {
    if(m_currentAnimation)
        m_currentAnimation->update(dt);
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(m_collisionShape, states);
    target.draw(m_sprite, states);
}
