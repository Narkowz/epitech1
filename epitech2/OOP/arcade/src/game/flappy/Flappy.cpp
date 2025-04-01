/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Flappy
*/

#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "Flappy.hpp"

static std::unique_ptr<Flappy> game;

void __attribute__((constructor)) init()
{
    game = std::make_unique<Flappy>();
    // std::cout << "Library flappy initialized." << std::endl;
}

void __attribute__((destructor)) cleanup()
{
    game.reset();
    // std::cout << "Library flappy cleaned up." << std::endl;
}

extern "C"
{
    const char *GameName()
    {
        return "Flappy";
    }

    IGame* getInstance()
    {
        if (!game)
        {
            game = std::make_unique<Flappy>();
        }
        return game.release();
    }
}

Flappy::Flappy()
    : AGame("Flappy")
{
    _map = std::vector<std::vector<MapCell>>(HEIGHT, std::vector<MapCell>(WIDTH, MapCell(' ', MapCell::CellColor::DEFAULT)));

    if (_map.empty() || _map[0].empty())
    {
        std::cerr << "ERROR: _map is not initialized properly!" << std::endl;
        exit(1);
    }

    _bird = {{5, 20}, {6, 20}, {5, 21}, {6, 21}};

    _isJumping = false;
}

Flappy::~Flappy()
{
}

void Flappy::update(float elapsedTime)
{
    if (elapsedTime - _lastUpdate > 0.16)
    {
        _lastUpdate = elapsedTime;
        _isUpdated = true;
        spawnPipe();
        fly();
        movePipes();
        collisions();
        updateMap();
    }
    else
    {
        _isUpdated = false;
    }
}

void Flappy::handleEvent(std::vector<Event> gameEvents)
{
    for (const auto& event : gameEvents)
    {
        switch (event.getType())
        {
        case EventType::QUIT:
            _running = false;
            break;
        case EventType::KEY_PRESSED:
            switch (event.getKeyCode())
            {
                case KeyCode::UP_ARROW:
                    _isJumping = true;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
        }
    }
}

void Flappy::display(std::shared_ptr<IGraphical> graphical)
{
    if (_over || !_isUpdated)
    {
        graphical->render();
    }
    else
    {
        graphical->clear();
        graphical->drawMap(_map);
        graphical->drawTitle(_name);
        graphical->render();
    }
}

void Flappy::fly()
{
    if (_isJumping)
    {
        for (auto& bird : _bird)
        {
            bird.second = bird.second - 2;
            _isJumping = false;
        }
    }
    else
    {
        for (auto& bird : _bird)
        {
            bird.second = bird.second + 2;
        }
    }
}

void Flappy::updateMap()
{
    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            _map[y][x] = MapCell(' ', MapCell::CellColor::DEFAULT);
        }
    }

    for (auto& pipe : _pipes)
    {
        _map[pipe.second][pipe.first] = MapCell(' ', MapCell::CellColor::GREEN);
    }

    for (auto& bird : _bird)
    {
        int x = bird.first, y = bird.second;

        if (y > 39 || y < 0)
        {
            _over = true;
        }
        else
        {
            _map[y][x] = MapCell(' ', MapCell::CellColor::RED);
        }
    }
}

void Flappy::spawnPipe()
{
    static int tick = 0;

    if ((tick % 6) != 0)
    {
        tick++;
        return;
    }

    srand(time(0));

    const int x_pipe = 39;
    int y_pipe = (rand() % 14) + 13;

    for (int y = y_pipe - 5; y >= 0; y--)
    {
        for (int x = 0; x < 3; x++)
        {
            _pipes.push_back({x_pipe - x, y});
        }
    }

    for (int y = y_pipe + 5; y <= 39; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            _pipes.push_back({x_pipe - x, y});
        }
    }

    tick++;
}

void Flappy::movePipes()
{
    for (auto it = _pipes.begin(); it != _pipes.end(); )
    {
        it->first -= 3;

        if (it->first < 0)
        {
            it = _pipes.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Flappy::collisions()
{
    for (auto& bird : _bird)
    {
        for (const auto& pipe : _pipes)
        {
            if (bird == pipe)
            {
                _over = true;
                return;
            }
        }
    }
}

