//
// Created by guill on 27/10/2018.
//

#include <SFML/System/Time.hpp>
#include "StateManager.hpp"

#include <cassert>


void StateManager::handleEvent(const sf::Event &e) {
    for(const auto& state : m_states)
        state->handleEvent(e);

//    applyPendingChanges();
}

void StateManager::update(sf::Time dt) {
    for(const auto& state : m_states)
        state->update(dt);
}

void StateManager::draw() {
    for(const auto& state : m_states)
        state->draw();
}

void StateManager::pushState(StateType stateType) {
    m_states.push_back(createState(stateType));
}

void StateManager::popState() {
    m_states.pop_back();
}

void StateManager::clearStates() {
    m_states.clear();
}

State::Ptr StateManager::createState(StateType stateType) {
    auto found = m_factories.find(stateType);
    assert(found != m_factories.end());

    return found->second();
}