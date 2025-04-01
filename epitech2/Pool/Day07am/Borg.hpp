/*
** EPITECH PROJECT, 2025
** Borg.hpp
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg {
    class Ship {
    public:
        Ship();
        void setupCore(WarpSystem::Core *core);
        void checkCore();

        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();

    private:
        int _side;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;
    };
}

#endif /* !BORG_HPP_ */
