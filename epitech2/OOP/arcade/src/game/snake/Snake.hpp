/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Snake
*/

#pragma once

#include "AGame.hpp"

class Snake : public AGame
{
    private:
        void move();
        void updateMap();
        void spawnApple();
        bool eatApple(std::pair<int, int>);
        bool eatItself(std::pair<int, int>);

    public:
        Snake();
        ~Snake();

        void update(float elapsedTime) final;
        void handleEvent(std::vector<Event> gameEvents) final;
        void display(std::shared_ptr<IGraphical> graphical) final;

    private:
        std::vector<std::pair<int, int>> _snake;
        std::vector<std::pair<int, int>> _apples;
        std::pair<int, int> _direction;
};
