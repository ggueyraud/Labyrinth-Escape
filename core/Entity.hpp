#ifndef LABYRINTHESCAPE_ENTITY_HPP
#define LABYRINTHESCAPE_ENTITY_HPP

#include "Animation.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <unordered_map>

class Entity : public sf::Drawable, public sf::Transformable{
    friend class Animation;
    friend class World;
public:
    Entity(const sf::Texture& texture);
    Entity(const sf::Texture& texture, const sf::IntRect& rect);

    void setVelocity(float vx, float vy);
    void setVelocity(const sf::Vector2f& velocity);
    inline sf::Vector2f getVelocity() const {
        return m_velocity;
    }

        sf::Vector2f getSize() const{
        return {m_collisionShape.getGlobalBounds().width, m_collisionShape.getGlobalBounds().height};
        }

    void addAnimation(const std::string& name, Animation::Ptr animation);
    void playAnimation(const std::string& name);

    virtual void update(sf::Time dt);

protected:
    std::unordered_map<std::string, Animation::Ptr> m_animations;
    Animation* m_currentAnimation = nullptr;
    sf::RectangleShape m_collisionShape;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Sprite m_sprite;
    sf::Vector2f m_velocity;
};


#endif //LABYRINTHESCAPE_ENTITY_HPP
