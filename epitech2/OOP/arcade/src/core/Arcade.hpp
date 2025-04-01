/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Arcade
*/

#pragma once

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <filesystem>

#include "IGame.hpp"
#include "Event.hpp"
#include "DlLoader.hpp"
#include "IGraphical.hpp"

class Arcade
{
    private:
        std::vector<std::string> _gamePaths;
        std::vector<std::string> _gameNames;
        int _currentGameIndex = 0;
        std::vector<std::string> _graphicPaths;
        std::vector<std::string> _graphicNames;
        int _currentGraphicIndex = 0;

        std::shared_ptr<IGame> _currentGame;
        std::shared_ptr<IGraphical> _currentGraphic;

        std::shared_ptr<DLLoader<IGame>> _gameLoader;
        std::shared_ptr<DLLoader<IGraphical>> _graphicLoader;

        void loadLibs();
        void loadGame(const std::string& path);
        void loadGraphic(const std::string& path);

    public:
        Arcade(const std::string& graphicPath);
        ~Arcade();
        void run();
        void switchGame(int index);
        void switchGraphical(int index);
};
