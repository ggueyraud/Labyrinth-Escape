//
// Created by guill on 24/10/2018.
//

#include "Entity.hpp"
#include "Animation.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

Animation::Animation(Entity* entity, sf::Time frameTime) :
m_entity(entity),
m_frameTime(frameTime){

}

void Animation::update(sf::Time dt){
    if(m_state == State::Play){
        m_currentTime += dt;

        if(m_currentTime > m_frameTime){
            m_currentFrame++;
            m_currentTime = sf::Time::Zero;

            if(m_currentFrame >= m_frames.size())
                m_currentFrame = 0;

            updateFrame();
        }
    }
}

void Animation::addFrame(const sf::IntRect& frameRect){
    m_frames.push_back(frameRect);

    if(m_frames.size() == 1)
        updateFrame();
}

void Animation::setState(const State& state){
    if(m_state == State::Stop){
        m_currentFrame = 0;
        //Sinon peut déplacer le joueur sans animation
        //m_currentTime = sf::Time::Zero;
        updateFrame();
    }

    m_state = state;

    if(m_state == State::Stop){
        m_currentFrame = 0;
        //m_currentTime = sf::Time::Zero;
        updateFrame();
    }
}

void Animation::updateFrame(){
    const auto frame = m_frames[m_currentFrame];

    m_entity->m_sprite.setTextureRect(frame);
}
