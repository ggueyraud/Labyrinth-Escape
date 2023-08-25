#include "core/StateManager.hpp"
#include "core/AssetManager.hpp"
#include "core/Window.hpp"
#include "GameState.hpp"
#include "EditorState.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
    std::cout << sizeof(sf::View) << std::endl;
    sf::Clock clock;

    FontManager::getInstance().load("assets/arial_narrow_7.ttf");
    TextureManager::getInstance().load("assets/sprites/1.png");

    StateManager::getInstance().registerState<GameState>(StateType::Game);
    StateManager::getInstance().registerState<EditorState>(StateType::Editor);
    StateManager::getInstance().pushState(StateType::Editor);

    while(!Window::getInstance().isDone()) {
        Window::getInstance().update(clock.restart());
        Window::getInstance().render();
    }

    return 0;
}
