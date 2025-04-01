/*
** EPITECH PROJECT, 2025
** Federation.hpp
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation {
    namespace Starfleet {
        class Captain {
        public:
            Captain(std::string name);
            std::string getName();
            int getAge();
            void setAge(int age);

        private:
            std::string _name;
            int _age;
        };

        class Ensign {
        public:
            explicit Ensign(std::string name);

        private:
            std::string _name;
        };

        class Ship {
        public:
            Ship(int length, int width, std::string name, short maxWarp);
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            void promote(Captain *captain);

            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();

        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Captain *_captain;
            Destination _location;
            Destination _home;
        };
    }

    class Ship {
    public:
        Ship(int length, int width, std::string name);
        void setupCore(WarpSystem::Core *core);
        void checkCore();

        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();

    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;
    };
}

#endif /* !FEDERATION_HPP_ */
