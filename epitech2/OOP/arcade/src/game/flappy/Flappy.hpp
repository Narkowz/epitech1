/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Flappy
*/

#pragma once

#include "AGame.hpp"

class Flappy : public AGame
{
    private:
        void fly();
        void movePipes();
        void spawnPipe();
        void updateMap();
        void collisions();

    public:
        Flappy();
        ~Flappy();

        void update(float elapsedTime) final;
        void handleEvent(std::vector<Event> gameEvents) final;
        void display(std::shared_ptr<IGraphical> graphical) final;

    private:
        std::vector<std::pair<int, int>> _bird;
        std::vector<std::pair<int, int>> _pipes;
        bool _isJumping;
};
