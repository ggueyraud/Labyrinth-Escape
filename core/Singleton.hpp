//
// Created by guill on 26/10/2018.
//

#ifndef LABYRINTHESCAPE_SINGLETON_HPP
#define LABYRINTHESCAPE_SINGLETON_HPP

#include <SFML/System/NonCopyable.hpp>

template<class T>
class Singleton : sf::NonCopyable{
public:
    static T& getInstance(){
        static T instance;
        return instance;
    }
};


#endif //LABYRINTHESCAPE_SINGLETON_HPP
