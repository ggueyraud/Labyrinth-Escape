//
// Created by guill on 29/10/2018.
//

#include "AssetManager.hpp"
#include "Player.hpp"

#include <iostream>
#include <SFML/Window/Event.hpp>

Player::Player() : Entity(TextureManager::getInstance().get("assets/sprites/1.png")) {
    m_collisionShape.setFillColor({0, 0, 255, 100});
    m_collisionShape.setSize({32, 10});
    m_collisionShape.setPosition(0, 26);

    setOrigin(0, 26);

    Animation::Ptr walkUpAnimation(new Animation(this, sf::seconds(0.2)));
    walkUpAnimation->addFrame({0, 108, 33, 36});
    walkUpAnimation->addFrame({33, 108, 33, 36});
    walkUpAnimation->addFrame({0, 108, 33, 36});
    walkUpAnimation->addFrame({66, 108, 33, 36});
    addAnimation("walkUp", std::move(walkUpAnimation));

    Animation::Ptr walkRightAnimation(new Animation(this, sf::seconds(0.2)));
    walkRightAnimation->addFrame({0, 72, 33, 36});
    walkRightAnimation->addFrame({33, 72, 33, 36});
    walkRightAnimation->addFrame({0, 72, 33, 36});
    walkRightAnimation->addFrame({66, 72, 33, 36});
    addAnimation("walkRight", std::move(walkRightAnimation));

    Animation::Ptr walkLeftAnimation(new Animation(this, sf::seconds(0.2)));
    walkLeftAnimation->addFrame({0, 36, 33, 36});
    walkLeftAnimation->addFrame({33, 36, 33, 36});
    walkLeftAnimation->addFrame({0, 36, 33, 36});
    walkLeftAnimation->addFrame({66, 36, 33, 36});
    addAnimation("walkLeft", std::move(walkLeftAnimation));

    Animation::Ptr walkDownAnimation(new Animation(this, sf::seconds(0.2)));
    walkDownAnimation->addFrame({0, 0, 33, 36});
    walkDownAnimation->addFrame({33, 0, 33, 36});
    walkDownAnimation->addFrame({0, 0, 33, 36});
    walkDownAnimation->addFrame({66, 0, 33, 36});
    addAnimation("walkDown", std::move(walkDownAnimation));

    setVelocity(50, 50);
}

void Player::processEvents(const sf::Event& e) {
    if(e.type == sf::Event::KeyReleased){
        switch (e.key.code) {
            case sf::Keyboard::Z:
            case sf::Keyboard::Up:
            case sf::Keyboard::D:
            case sf::Keyboard::Right:
            case sf::Keyboard::S:
            case sf::Keyboard::Down:
            case sf::Keyboard::Q:
            case sf::Keyboard::Left:
                m_isWalking = false;
                if(m_currentAnimation)
                    m_currentAnimation->setState(Animation::State::Stop);
                break;
            case sf::Keyboard::A:
                setVelocity(50, 50);
                break;
        }
    }
}

void Player::update(sf::Time dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        m_isWalking = true;
        move(0, -getVelocity().y * dt.asSeconds());
        playAnimation("walkUp");
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        m_isWalking = true;
        move(getVelocity().x * dt.asSeconds(), 0);
        playAnimation("walkRight");
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        m_isWalking = true;
        move(0, getVelocity().y * dt.asSeconds());
        playAnimation("walkDown");
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        m_isWalking = true;
        move(-getVelocity().x * dt.asSeconds(), 0);
        playAnimation("walkLeft");
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        setVelocity(100, 100);
        m_isRunning = true;
    }

    //if(sf::Keyboard::isKeyReleased(sf::Keyboard::A))

    if(m_isWalking){
        Entity::update(dt);
    }
}
