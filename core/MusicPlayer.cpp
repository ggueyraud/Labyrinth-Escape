//
// Created by guill on 28/10/2018.
//

#include "MusicPlayer.hpp"

void MusicPlayer::play(const std::string &filename, bool loop) {
    if(!m_music.openFromFile(filename))
        return;

    m_music.setLoop(loop);
    m_music.play();
}

void MusicPlayer::pause() {
    m_music.pause();
}

void MusicPlayer::stop() {
    m_music.stop();
}

void MusicPlayer::setVolume(float volume) {
    m_volume = volume;
    m_music.setVolume(m_volume);
}