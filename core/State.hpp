//
// Created by guill on 27/10/2018.
//

#ifndef LABYRINTHESCAPE_STATE_HPP
#define LABYRINTHESCAPE_STATE_HPP

#include <memory>

namespace sf{
    class Event;
    class Time;
}

class State {
public:
    using Ptr = std::unique_ptr<State>;

    virtual void handleEvent(const sf::Event& e) = 0;
    virtual void update(sf::Time dt) = 0;
    virtual void draw() = 0;
};


#endif //LABYRINTHESCAPE_STATE_HPP
