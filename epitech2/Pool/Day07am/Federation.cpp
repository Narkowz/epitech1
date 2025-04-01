/*
** EPITECH PROJECT, 2025
** Federation.hpp
** File description:
** Federation
*/

#include "Federation.hpp"
#include <iostream>

namespace Federation {
    namespace Starfleet {
        Captain::Captain(std::string name) : _name(name), _age(0)
        {

        }

        std::string Captain::getName()
        {
            return _name;
        }

        int Captain::getAge()
        {
            return _age;
        }

        void Captain::setAge(int age)
        {
            _age = age;
        }

        Ensign::Ensign(std::string name) : _name(name)
        {
            std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
        }

        Ship::Ship(int length, int width, std::string name, short maxWarp)
            : _length(length), _width(width), _name(name), _maxWarp(maxWarp),
              _core(nullptr), _captain(nullptr), _location(EARTH), _home(EARTH)
        {
            std::cout << "The ship USS " << _name << " has been finished." << std::endl;
            std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
            std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
        }

        void Ship::setupCore(WarpSystem::Core *core)
        {
            _core = core;
            std::cout << "USS " << _name << ": The core is set." << std::endl;
        }

        void Ship::checkCore()
        {
            if (_core && _core->checkReactor()->isStable())
                std::cout << "USS " << _name << ": The core is stable at the time." << std::endl;
            else
                std::cout << "USS " << _name << ": The core is unstable at the time." << std::endl;
        }

        void Ship::promote(Captain *captain)
        {
            _captain = captain;
            std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
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

    Ship::Ship(int length, int width, std::string name)
        : _length(length), _width(width), _name(name), _maxWarp(1),
          _core(nullptr), _location(VULCAN), _home(VULCAN)
    {
        std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
        std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    }

    void Ship::setupCore(WarpSystem::Core *core)
    {
        _core = core;
        std::cout << _name << ": The core is set." << std::endl;
    }

    void Ship::checkCore()
    {
        if (_core && _core->checkReactor()->isStable())
            std::cout << _name << ": The core is stable at the time." << std::endl;
        else
            std::cout << _name << ": The core is unstable at the time." << std::endl;
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
