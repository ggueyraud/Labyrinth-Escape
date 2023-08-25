//
// Created by guill on 24/10/2018.
//

#ifndef LABYRINTHESCAPE_ANIMATION_HPP
#define LABYRINTHESCAPE_ANIMATION_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <cstdint>
#include <vector>
#include <memory>

class Entity;

class Animation{
    friend class Entity;
public:
    using Ptr = std::unique_ptr<Animation>;

    enum class State{
        Play,
        Pause,
        Stop
    };

    Animation(Entity* entity, sf::Time frameTime);

    void update(sf::Time dt);

    void addFrame(const sf::IntRect& frameRect);
    void setState(const State& state);

    void updateFrame();
private:
    std::vector<sf::IntRect> m_frames;
    State m_state = State::Play;

    uint8_t m_currentFrame = 0;
    sf::Time    m_frameTime,
                m_currentTime;
    Entity* m_entity = nullptr;
};


#endif //LABYRINTHESCAPE_ANIMATION_HPP
