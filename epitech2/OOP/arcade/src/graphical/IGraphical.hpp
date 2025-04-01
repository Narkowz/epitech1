/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** IGraphical
*/

#pragma once

#include "Event.hpp"
#include "MapCell.hpp"

class IGraphical
{
    public:
        IGraphical() = default;
        virtual ~IGraphical() = default;

        virtual void render() = 0;
        virtual void clear() = 0;
        virtual std::vector<Event> getEvents() = 0;
        virtual void drawMap(const std::vector<std::vector<MapCell>> &cellMap) = 0;
        virtual void drawGameOver(const std::vector<std::vector<MapCell>> &cellMap, const std::string &score) = 0;
        virtual void drawTitle(const std::string &title) = 0;
        virtual void drawScore(const std::string &score) = 0;
        virtual void drawBestScore(const std::vector<std::string> &bestScores) = 0;
};
