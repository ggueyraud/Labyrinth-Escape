//
// Created by guill on 27/10/2018.
//

#ifndef LABYRINTHESCAPE_WINDOW_HPP
#define LABYRINTHESCAPE_WINDOW_HPP

#include "Singleton.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>

class Window : public Singleton<Window>{
public:
    Window();

    inline bool isDone() const {
        return m_isDone;
    }
    inline sf::Vector2u getSize() const {
        return m_size;
    }
    inline sf::Vector2f getMousePosition() const {
        return m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
    }
    inline sf::Vector2f getMousePosition(const sf::View& view) const{
        return m_window.mapPixelToCoords(
                sf::Mouse::getPosition(m_window),
                view
        );
    }
    void setView(const sf::View& v){
        m_window.setView(v);
    }
    inline const sf::View& getDefaultView() const {
        return m_window.getDefaultView();
    }

    void update(sf::Time dt);
    void render();
    void draw(const sf::Drawable& drawable);

private:
    void create();
    void toggleFullscreen(bool windowed = false);

    enum Style{
        Default = sf::Style::Default,
        WindowedFullScreen = sf::Style::Close,
        Fullscreen = sf::Style::Fullscreen
    };

    uint8_t m_fps = 60;
    bool m_isDone = false;
    sf::Vector2u m_size = {800, 600};
    std::string m_title = "LabyrinthEscape";
    sf::RenderWindow m_window;
    Style m_style = Style::Default;
};


#endif //LABYRINTHESCAPE_WINDOW_HPP
