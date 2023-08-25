//
// Created by guill on 26/10/2018.
//

#ifndef LABYRINTHESCAPE_ASSETMANAGER_HPP
#define LABYRINTHESCAPE_ASSETMANAGER_HPP

#include "Singleton.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <string>
#include <unordered_map>
#include <memory>
#include <iostream>

template<class Resource>
class AssetManager : public Singleton<AssetManager<Resource>>{
    public:
        const Resource& get(const std::string&) const;
        void load(const std::string& filename);

    private:
        std::unordered_map<std::string, std::unique_ptr<Resource>> m_resources;
};

using TextureManager = AssetManager<sf::Texture>;
using FontManager = AssetManager<sf::Font>;
using SoundManager = AssetManager<sf::SoundBuffer>;

template<class Resource>
void AssetManager<Resource>::load(const std::string& filename){
    std::unique_ptr<Resource> ptr(new Resource);

    if(!ptr->loadFromFile(filename))
        std::cout << "Impossible de charger : " << filename << std::endl;
//        LogManager::getInstance().write(LogManager::LogType::Error, "Impossible to load file: " + filename);

    m_resources.emplace(filename, std::move(ptr));
}

template<class Resource>
const Resource& AssetManager<Resource>::get(const std::string& filename) const{
    return *m_resources.at(filename);
}


#endif //LABYRINTHESCAPE_ASSETMANAGER_HPP
