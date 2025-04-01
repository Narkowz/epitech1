/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Snake
*/

#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "Snake.hpp"

#define UP {0, -1}
#define RIGHT {1, 0}
#define DOWN {0, 1}
#define LEFT {-1, 0}
#define NB_APPLES 10

static std::unique_ptr<Snake> game;

void __attribute__((constructor)) init()
{
    game = std::make_unique<Snake>();
    // std::cout << "Library snake initialized." << std::endl;
}

void __attribute__((destructor)) cleanup()
{
    game.reset();
    // std::cout << "Library snake cleaned up." << std::endl;
}

extern "C"
{
    const char *GameName()
    {
        return "Snake";
    }

    IGame* getInstance()
    {
        if (!game)
        {
            game = std::make_unique<Snake>();
        }
        return game.release();
    }
}

Snake::Snake()
    : AGame("Snake")
{
    // std::cout << "Initializing Snake game..." << std::endl;

    _map = std::vector<std::vector<MapCell>>(HEIGHT, std::vector<MapCell>(WIDTH, MapCell(' ', MapCell::CellColor::DEFAULT)));

    if (_map.empty() || _map[0].empty())
    {
        std::cerr << "ERROR: _map is not initialized properly!" << std::endl;
        exit(1);
    }

    _snake = {{2, 19}, {3, 19}, {4, 19}, {5, 19}};

    spawnApple();

    _direction = RIGHT;
}

Snake::~Snake() {}

void Snake::update(float elapsedTime)
{

    if (elapsedTime - _lastUpdate > 0.16)
    {
        _lastUpdate = elapsedTime;
        _isUpdated = true;
        move();
        updateMap();
    }
    else
    {
        _isUpdated = false;
    }

}

void Snake::updateMap()
{
    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            _map[y][x] = MapCell(' ', MapCell::CellColor::DEFAULT);
        }
    }

    _map[_snake.back().second][_snake.back().first] = MapCell(' ', MapCell::CellColor::GREEN);
    for (size_t i = 0; i < _snake.size() - 1; i++)
    {
        _map[_snake[i].second][_snake[i].first] = MapCell(' ', MapCell::CellColor::LIGHT_GREEN);
    }

    for (const auto& apple : _apples)
    {
        _map[apple.second][apple.first] = MapCell(' ', MapCell::CellColor::RED);
    }
}

void Snake::handleEvent(std::vector<Event> gameEvents)
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
                        _direction = UP;
                        break;
                    case KeyCode::RIGHT_ARROW:
                        _direction = RIGHT;
                        break;
                    case KeyCode::DOWN_ARROW:
                        _direction = DOWN;
                        break;
                    case KeyCode::LEFT_ARROW:
                        _direction = LEFT;
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

void Snake::display(std::shared_ptr<IGraphical> graphical)
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

void Snake::move()
{
    std::pair<int, int> head = _snake.back();

    head.first = head.first + _direction.first;
    head.second = head.second + _direction.second;

    if (head.first > 39 || head.first < 0 || head.second > 39 || head.second < 0)
    {
        _over = true;
        return;
    }

    if (eatItself(head))
    {
        _over = true;
        return;
    }

    if (eatApple(head))
    {
        _snake.push_back(head);
    }
    else
    {
        _snake.erase(_snake.begin());
        _snake.push_back(head);
    }
}

void Snake::spawnApple()
{
    srand(time(0));

    for (int i = 0; i < NB_APPLES; ++i)
    {
        bool appleSpawned = false;

        while (!appleSpawned)
        {
            int x = rand() % 40;
            int y = rand() % 40;

            bool collisionWithSnake = false;

            for (const auto& segment : _snake)
            {
                if (segment.first == x && segment.second == y)
                {
                    collisionWithSnake = true;
                    break;
                }
            }

            if (!collisionWithSnake)
            {
                _apples.push_back({x, y});
                appleSpawned = true;
            }
        }
    }
}

bool Snake::eatApple(std::pair<int, int> head)
{
    for (auto it = _apples.begin(); it != _apples.end(); ++it)
    {
        if (*it == head)
        {
            _apples.erase(it);

            bool appleSpawned = false;

            while (!appleSpawned)
            {
                int x = rand() % 40;
                int y = rand() % 40;

                bool collisionWithSnake = false;

                for (const auto& segment : _snake)
                {
                    if (segment.first == x && segment.second == y)
                    {
                        collisionWithSnake = true;
                        break;
                    }
                }

                if (!collisionWithSnake)
                {
                    _apples.push_back({x, y});
                    appleSpawned = true;
                }
            }
            return true;
        }
    }
    return false;
}

bool Snake::eatItself(std::pair<int, int> head)
{
    for (auto it = _snake.begin(); it != _snake.end(); ++it)
    {
        if (*it == head)
        {
            _snake.erase(it);
            return true;
        }
    }
    return false;
}
