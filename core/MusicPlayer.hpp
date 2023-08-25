//
// Created by guill on 28/10/2018.
//

#ifndef LABYRINTHESCAPE_MUSICPLAYER_HPP
#define LABYRINTHESCAPE_MUSICPLAYER_HPP

#include "Singleton.hpp"

#include <SFML/Audio/Music.hpp>

class MusicPlayer : public Singleton<MusicPlayer>{
    public:
        void play(const std::string& filename, bool loop = false);
        void pause();
        void stop();

        void setVolume(float volume);
        inline float getVolume() const {
            return m_volume;
        }

        inline sf::Music::Status getStatus() const{
            return m_music.getStatus();
        }
    private:
        sf::Music m_music;
        float m_volume;
};


#endif //LABYRINTHESCAPE_MUSICPLAYER_HPP
