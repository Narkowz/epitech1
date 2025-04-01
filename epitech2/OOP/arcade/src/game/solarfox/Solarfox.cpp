/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Solarfox
*/

#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <set>

#include "Solarfox.hpp"

#define UP {0, -1}
#define RIGHT {1, 0}
#define DOWN {0, 1}
#define LEFT {-1, 0}

static std::unique_ptr<Solarfox> game;

void __attribute__((constructor)) init()
{
    game = std::make_unique<Solarfox>();
}

void __attribute__((destructor)) cleanup()
{
    game.reset();
}

extern "C"
{
    const char *GameName()
    {
        return "Solarfox";
    }

    IGame* getInstance()
    {
        if (!game)
        {
            game = std::make_unique<Solarfox>();
        }
        return game.release();
    }
}

void setPairTo(int first, int second, std::pair<int, int>& pair)
{
    pair.first = first;
    pair.second = second;
}

std::vector<std::pair<int, int>> generateObstacles(int width, int height, int count, std::pair<int, int> player)
{
    std::set<std::pair<int, int>> obstacles;
    std::srand(std::time(nullptr));

    while (obstacles.size() < static_cast<std::size_t>(count))
    {
        int x = std::rand() % width;
        int y = std::rand() % height;

        if (abs(x - player.first) > 3 && abs(y - player.second) > 3 && x >= 5 && y >= 5)
        {
            obstacles.insert({x, y});
        }
    }

    return std::vector<std::pair<int, int>>(obstacles.begin(), obstacles.end());
}

Solarfox::Solarfox()
    : AGame("Solarfox")
{
    _map = std::vector<std::vector<MapCell>>(HEIGHT, std::vector<MapCell>(WIDTH, MapCell(' ', MapCell::CellColor::DEFAULT)));

    if (_map.empty() || _map[0].empty())
    {
        std::cerr << "ERROR: _map is not initialized properly!" << std::endl;
        exit(1);
    }

    _player = {19, 9};
    setPairTo(-1, -1, _playerShots);
    setPairTo(-1, -1, _originalPlayerShots);
    _direction = DOWN;
    _isShooting = false;
    _enemy = {{0, 19}, {39, 19}, {19, 0}, {19, 39}};
    _enemyShots = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
    _enemyShotsDirection = {RIGHT, LEFT, DOWN, UP};
    _enemyDirection = {DOWN, UP, RIGHT, LEFT};
    _enemyIsShooting = {false, false, false, false};
    _obstacles = generateObstacles(WIDTH - 5, HEIGHT - 5, 10, _player);
}

Solarfox::~Solarfox() {}

void Solarfox::handleEvent(std::vector<Event> gameEvents)
{
    for (const Event & event : gameEvents)
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
                        if (_direction != std::pair<int, int>DOWN)
                        {
                            _direction = UP;
                        }
                        break;
                    case KeyCode::RIGHT_ARROW:
                        if (_direction != std::pair<int, int>LEFT)
                        {
                            _direction = RIGHT;
                        }
                        break;
                    case KeyCode::DOWN_ARROW:
                        if (_direction != std::pair<int, int>UP)
                        {
                            _direction = DOWN;
                        }
                        break;
                    case KeyCode::LEFT_ARROW:
                        if (_direction != std::pair<int, int>RIGHT)
                        {
                            _direction = LEFT;
                        }
                        break;
                    case KeyCode::SPACE:
                        _isShooting = true;
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

void Solarfox::update(float elapsedTime)
{
    if (elapsedTime - _lastUpdate > 0.16)
    {
        _lastUpdate = elapsedTime;
        _isUpdated = true;
        move();
        handlePlayerShots();
        handleEnemiesShots();
        updateMap();
    }
    else
    {
        _isUpdated = false;
    }
}

void Solarfox::move()
{
    std::pair<int, int> player = _player;

    player.first += _direction.first;
    player.second += _direction.second;

    if (gotHit(player))
    {
        _over = true;
    }
    else
    {
        _player = player;
    }

    for (size_t i = 0; i < _enemy.size(); i++)
    {
        if ((i < 2 && (_enemy[i].second == 39 || _enemy[i].second == 0))
        || (i >= 2 && (_enemy[i].first == 39 || _enemy[i].first == 0)))
        {
            _enemyDirection[i] = {-_enemyDirection[i].first, -_enemyDirection[i].second};
        }
        _enemy[i].first += _enemyDirection[i].first;
        _enemy[i].second += _enemyDirection[i].second;
    }
}

bool Solarfox::gotHit(std::pair<int, int> player)
{
    if (player.first >= 38 || player.first < 2 || player.second >= 38 || player.second < 2)
    {
        return true;
    }

    for (auto pos = _obstacles.begin(); pos != _obstacles.end(); pos++)
    {
        if (*pos == player)
        {
            return true;
        }
    }

    for (int pos = 0; pos < 4; pos++)
    {
        if (_enemyShots[pos] == player)
        {
            return true;
        }
    }

    return false;
}

void Solarfox::handlePlayerShots()
{
    if (_isShooting)
    {
        if (_playerShots == std::pair<int, int>{-1, -1})
        {
            int x = _player.first + _direction.first;
            int y = _player.second + _direction.second;

            setPairTo(x, y, _playerShots);
            setPairTo(x, y, _originalPlayerShots);
            setPairTo(_direction.first, _direction.second, _shotDirection);
        }
        else
        {
            int newX = _originalPlayerShots.first - _playerShots.first;
            int newY = _originalPlayerShots.second - _playerShots.second;

            if (abs(newX) >= 2 || abs(newY) >= 2)
            {
                _isShooting = false;
                setPairTo(-1, -1, _playerShots);
                setPairTo(-1, -1, _originalPlayerShots);
            }
            else
            {
                int dirX = _shotDirection.first + _playerShots.first;
                int dirY = _shotDirection.second + _playerShots.second;
                setPairTo(dirX, dirY, _playerShots);
            }
        }
    }
    for (auto it = _obstacles.begin(); it != _obstacles.end();)
    {
        if (*it == _playerShots)
        {
            _isShooting = false;
            setPairTo(-1, -1, _playerShots);
            setPairTo(-1, -1, _originalPlayerShots);
            it = _obstacles.erase(it);
            break;
        }
        else
        {
            ++it;
        }
    }
    for (auto it = _enemyShots.begin(); it != _enemyShots.end();)
    {
        if (*it == _playerShots)
        {
            _isShooting = false;
            setPairTo(-1, -1, _playerShots);
            setPairTo(-1, -1, _originalPlayerShots);
            it = _enemyShots.erase(it);
            break;
        }
        else
        {
            ++it;
        }
    }
}

void Solarfox::handleEnemiesShots()
{

    _enemyIsShooting[rand() % 4] = true;
    for (int i = 0; i < 4; i++)
    {
        if (_enemyIsShooting[i])
        {
            if (_enemyShots[i] == std::pair<int, int>{-1, -1})
            {
                int x = _enemy[i].first + _enemyShotsDirection[i].first;
                int y = _enemy[i].second + _enemyShotsDirection[i].second;
                if (i == 0)
                {
                    x += 1;
                }
                if (i == 2)
                {
                    y += 1;
                }
                setPairTo(x, y, _enemyShots[i]);
            }
            else
            {
                int newX = _enemyShots[i].first + _enemyShotsDirection[i].first;
                int newY = _enemyShots[i].second + _enemyShotsDirection[i].second;

                if (newX >= 38 || newY >= 38 || newX < 2 || newY < 2)
                {
                    _enemyIsShooting[i] = false;
                    setPairTo(-1, -1, _enemyShots[i]);
                }
                else
                {
                    setPairTo(newX, newY, _enemyShots[i]);
                }
            }
        }
    }
}

void Solarfox::updateMap()
{
    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            if (x < 2 || y < 2 || x >= 38 || y >= 38)
            {
                _map[y][x] = MapCell(' ', MapCell::CellColor::BLUE);

            }
            else
            {
                _map[y][x] = MapCell(' ', MapCell::CellColor::DEFAULT);
            }
        }
    }

    _map[_player.second][_player.first] = MapCell(' ', MapCell::CellColor::GREEN);
    for (const std::pair<int, int> & enemy : _enemy)
    {
        _map[enemy.second][enemy.first] = MapCell(' ', MapCell::CellColor::RED);
    }
    for (const std::pair<int, int> & obstacle : _obstacles)
    {
        _map[obstacle.second][obstacle.first] = MapCell('=', MapCell::CellColor::BLUE);
    }

    if (_playerShots != std::pair<int, int>{-1, -1} && _isShooting == true)
    {
        if (_playerShots.second < 38)
        {
            _map[_playerShots.second][_playerShots.first] = MapCell(' ', MapCell::CellColor::LIGHT_GREEN);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (_enemyShots[i] != std::pair<int, int>{-1, -1} && _enemyIsShooting[i] == true)
        {
            _map[_enemyShots[i].second][_enemyShots[i].first] = MapCell(' ', MapCell::CellColor::MAGENTA);
        }
    }
}

void Solarfox::display(std::shared_ptr<IGraphical> graphical)
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

        if (_obstacles.empty())
        {
            _over = true;
        }
    }
}
