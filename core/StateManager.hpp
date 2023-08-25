//
// Created by guill on 27/10/2018.
//

#ifndef LABYRINTHESCAPE_STATEMANAGER_HPP
#define LABYRINTHESCAPE_STATEMANAGER_HPP

#include "Singleton.hpp"
#include "State.hpp"
#include "../StateType.hpp"

#include <functional>
#include <vector>
#include <unordered_map>

class StateManager : public Singleton<StateManager>{
public:
    void handleEvent(const sf::Event& e);
    void update(sf::Time dt);
    void draw();

    template <class T>
        void registerState(StateType stateType);

    void pushState(StateType stateType);
    void popState();
    void clearStates();

    inline bool isEmpty() const {
        return m_states.empty();
    }
private:
    State::Ptr createState(StateType stateType);

    std::vector<State::Ptr> m_states;
    std::unordered_map<StateType, std::function<State::Ptr()>> m_factories;
};

template <class T>
void StateManager::registerState(StateType stateType) {
    m_factories[stateType] = [this] () {
        return State::Ptr(new T);
    };
}


#endif //LABYRINTHESCAPE_STATEMANAGER_HPP
