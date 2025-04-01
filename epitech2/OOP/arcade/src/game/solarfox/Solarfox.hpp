/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Solarfox
*/

#pragma once

#include "AGame.hpp"

class Solarfox : public AGame
{
    private:
        void move();
        void handlePlayerShots();
        void handleEnemiesShots();
        void updateMap();
        bool gotHit(std::pair<int, int>);

    public:
        Solarfox();
        ~Solarfox();

        void update(float elapsedTime) final;
        void handleEvent(std::vector<Event> gameEvents) final;
        void display(std::shared_ptr<IGraphical> graphical) final;

    private:
        std::pair<int, int> _player;
        std::pair<int, int> _playerShots;
        std::pair<int, int> _originalPlayerShots;
        std::pair<int, int> _shotDirection;
        std::pair<int, int> _direction;
        bool _isShooting;
        std::vector<bool> _enemyIsShooting;
        std::vector<std::pair<int, int>> _enemy;
        std::vector<std::pair<int, int>> _enemyDirection;
        std::vector<std::pair<int, int>> _enemyShots;
        std::vector<std::pair<int, int>> _enemyShotsDirection;
        std::vector<std::pair<int, int>> _obstacles;
};
