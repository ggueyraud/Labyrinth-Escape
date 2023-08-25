//
// Created by guill on 24/10/2018.
//

#ifndef LABYRINTHESCAPE_MAP_HPP
#define LABYRINTHESCAPE_MAP_HPP

#include <SFML/Graphics/VertexArray.hpp>

#include <memory>

struct Layer {
    using Ptr = std::unique_ptr<Layer>;

    Layer(const sf::Texture& texture, const sf::Vector2u& mapSize, const std::vector<uint8_t>& tiles);

    sf::VertexArray vertices;
    const sf::Texture& texture;
};
class World;

class Map : public sf::Drawable{
public:
    Map(World* world):
        m_world(world){
        load("assets/maps/1.map");
    }

    Layer* getLayer(uint8_t i){
        return m_layers[i].get();
    }

private:
    bool load(const std::string& filename);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    World* m_world = nullptr;

    std::vector<Layer::Ptr> m_layers;
};


#endif //LABYRINTHESCAPE_MAP_HPP
