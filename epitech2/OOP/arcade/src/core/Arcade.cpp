/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Arcade
*/

#include <chrono>
#include <iostream>

#include "Arcade.hpp"
#include "PathExceptions.hpp"

Arcade::Arcade(const std::string& graphicPath)
{
    loadLibs();
    if (graphicPath.empty() || _gamePaths.empty())
    {
        throw PathException("No graphical or game library", HERE);
    }
    loadGraphic(graphicPath);
    loadGame(_gamePaths[0]); // Taking the 1st game by default
}

Arcade::~Arcade()
{
    if (_currentGame)
    {
        _currentGame.reset();
    }
    if (_currentGraphic)
    {
        _currentGraphic.reset();
    }
    if (_gameLoader)
    {
        _gameLoader.reset();
    }
    if (_graphicLoader)
    {
        _graphicLoader.reset();
    }
}

void Arcade::run()
{
    if (_currentGraphic == nullptr || _currentGame == nullptr)
    {
        return;
    }

    auto startTime = std::chrono::high_resolution_clock::now();
    while (_currentGame->isRunning())
    {
        auto nowTime = std::chrono::high_resolution_clock::now();
        float elapsedTime = std::chrono::duration<float>(nowTime - startTime).count();

        _currentGame->handleEvent(_currentGraphic->getEvents());
        _currentGame->update(elapsedTime);
        _currentGame->display(_currentGraphic);
    }
}

void Arcade::loadLibs()
{
    for (const auto& entry : std::filesystem::directory_iterator("lib/"))
    {
        if (entry.path().extension() != ".so")
        {
            continue;
        }

        const std::string path = entry.path().string();
        try
        {
            DLLoader<IGame> gameLoader(path);
            std::string name = gameLoader.getName("GameName");
            if (!name.empty())
            {
                _gameNames.push_back(name);
                _gamePaths.push_back(path);
                continue;
            }
        }
        catch (const std::exception&) {}

        try
        {
            DLLoader<IGraphical> graphicLoader(path);
            std::string name = graphicLoader.getName("GraphicName");
            if (!name.empty())
            {
                _graphicNames.push_back(name);
                _graphicPaths.push_back(path);
            }
        }
        catch (const std::exception&)
        {
            std::cerr << "Invalid Library: " << path << std::endl;
        }
    }
}

void Arcade::loadGraphic(const std::string& path)
{
    try
    {
        if (_currentGraphic)
        {
            _currentGraphic.reset();
        }
        _graphicLoader = std::make_unique<DLLoader<IGraphical>>(path);
        _currentGraphic = std::shared_ptr<IGraphical>(_graphicLoader->getInstance());
    }
    catch (const std::exception& e)
    {
        throw PathException("Failed to load graphical library", HERE);
    }
}

void Arcade::loadGame(const std::string& path)
{
    try
    {
        if (_currentGame)
        {
            _currentGame.reset();
        }
        _gameLoader = std::make_unique<DLLoader<IGame>>(path);
        _currentGame = std::shared_ptr<IGame>(_gameLoader->getInstance());
    }
    catch (const std::exception& e)
    {
        throw PathException("Failed to load game library", HERE);
    }
}
