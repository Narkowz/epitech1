/*
** EPITECH PROJECT, 2025
** Borg.cpp
** File description:
** Brog
*/

#include "Borg.hpp"
#include <iostream>

namespace Borg {
    Ship::Ship() : _side(300), _maxWarp(9), _core(nullptr), _location(UNICOMPLEX), _home(UNICOMPLEX)
    {
        std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
        std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
        std::cout << "Resistance is futile." << std::endl;
    }

    void Ship::setupCore(WarpSystem::Core *core)
    {
        _core = core;
    }

    void Ship::checkCore()
    {
        if (_core && _core->checkReactor()->isStable())
            std::cout << "Everything is in order." << std::endl;
        else
            std::cout << "Critical failure imminent." << std::endl;
    }

    bool Ship::move(int warp, Destination d)
    {
        if (warp <= _maxWarp && d != _location && _core && _core->checkReactor()->isStable()) {
            _location = d;
            return true;
        }
        return false;
    }

    bool Ship::move(int warp)
    {
        return move(warp, _home);
    }

    bool Ship::move(Destination d)
    {
        return move(_maxWarp, d);
    }

    bool Ship::move()
    {
        return move(_maxWarp, _home);
    }
}

