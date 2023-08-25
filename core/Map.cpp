//
// Created by guill on 24/10/2018.
//

#include "AssetManager.hpp"
#include "Map.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <fstream>
#include <iostream>

#include "World.hpp"

Layer::Layer(const sf::Texture &texture, const sf::Vector2u& mapSize, const std::vector<uint8_t>& tiles) :
texture(texture),
vertices(sf::Quads, mapSize.x * mapSize.y * 4) {
    for(uint8_t y = 0; y < mapSize.y; y++){
        for(uint8_t x = 0; x < mapSize.x; x++){
            int tile = (int)tiles[x + y * mapSize.x];
            int tu = tile % (texture.getSize().x / 32);
            int tv = tile / (texture.getSize().x / 32);
            auto quad = &vertices[(x + y * mapSize.x) * 4];

            quad[0].position = sf::Vector2f(x * 32, y * 32);
            quad[1].position = sf::Vector2f((x + 1) * 32, y * 32);
            quad[2].position = sf::Vector2f((x + 1) * 32, (y + 1) * 32);
            quad[3].position = sf::Vector2f(x * 32, (y + 1) * 32);

            quad[0].texCoords = sf::Vector2f(tu * 32, tv * 32);
            quad[1].texCoords = sf::Vector2f((tu + 1) * 32, tv * 32);
            quad[2].texCoords = sf::Vector2f((tu + 1) * 32, (tv + 1) * 32);
            quad[3].texCoords = sf::Vector2f(tu * 32, (tv + 1) * 32);
        }
    }
}

bool Map::load(const std::string& filename) {
    std::ifstream file(filename);

    if(file) {
        std::string line;
        sf::Vector2u size;
        std::vector<std::string> tilesets;
        uint8_t layers;

        std::getline(file, line);
        std::getline(file, line);
        size.x = std::stoi(line);
        std::getline(file, line);
        size.y = std::stoi(line);
        std::getline(file, line);
        layers = std::stoi(line);

        //Chargement des tilesets utilisés
        for(uint8_t i = 0; i < layers; i++){
            std::getline(file, line);
            TextureManager::getInstance().load("assets/tilesets/" + line);
            tilesets.push_back("assets/tilesets/" + line);
        }

        //Chargement des collisions
        for(int y = 0; y < size.y; y++)
            for(int x = 0; x < size.x; x++){
                char a;
                file.get(a);

                //Collision détectée
                if(a == '0'){
                    sf::RectangleShape shape({32, 32});
                    shape.setFillColor({255, 0, 0, 100});
                    shape.setPosition(x * 32, y * 32);

                    m_world->addCollision(shape);
                }
            }

        //Chargement des tiles

        std::vector<uint8_t> tiles;

        while(getline(file, line, ';'))
            tiles.push_back(std::stoi(line));

        for(uint8_t z = 0; z < layers; z++){
            std::vector<uint8_t> layerTiles;

            for(uint8_t y = size.y * z; y < ( z + 1) * size.y; y++){
                for(uint8_t x = 0; x < size.x; x++)
                    layerTiles.push_back(tiles[x + y * size.x]);
            }

            Layer::Ptr layer(new Layer(TextureManager::getInstance().get(tilesets[z]), size, layerTiles));
            m_layers.push_back(std::move(layer));
        }

        file.close();

        return true;
    }

    return false;
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(const auto& layer : m_layers) {
        states.texture = &layer->texture;
        target.draw(layer->vertices, states);
    }
}
