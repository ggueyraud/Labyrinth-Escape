//
// Created by guill on 29/10/2018.
//

#ifndef LABYRINTHESCAPE_PLAYER_HPP
#define LABYRINTHESCAPE_PLAYER_HPP

#include "Entity.hpp"

namespace sf {
    class Event;
}

class Player : public Entity{
    public:
        enum class Direction{
            Up,
            Right,
            Down,
            Left
        };

        Player();

        void processEvents(const sf::Event& e);

        virtual void update(sf::Time dt) override;

    private:
        bool m_isWalking = false;
        bool m_isRunning = false;
        Direction m_direction = Direction::Down;
};


#endif //LABYRINTHESCAPE_PLAYER_HPP
