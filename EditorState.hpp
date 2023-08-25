#ifndef EDITORSTATE_HPP_INCLUDED
#define EDITORSTATE_HPP_INCLUDED

#include "core/Map.hpp"
#include "core/World.hpp"
#include "core/State.hpp"

#include "core/ui/Window.hpp"
#include "core/ui/Manager.hpp"

#include <SFML/System/Time.hpp>
#include "core/ui/Frame.hpp"

class EditorState : public State{
public:
    EditorState();

    virtual void handleEvent(const sf::Event& e) override;
    virtual void update(sf::Time dt) override;
    virtual void draw() override;

private:
    World m_world;
Map m_map;

    //UI
    ui::Manager m_uiManager;
    ui::Window m_window;

    ui::Frame mf;

    ui::Button m_musicBtn;

    //sf::Text m_layerText;
};

#endif // EDITORSTATE_HPP_INCLUDED
