/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml.hpp
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "IGraphical.hpp"

class Sfml : public IGraphical
{
    protected:
        sf::RenderWindow _window;

    public:
        Sfml();
        ~Sfml();
        void render() final;
        void clear() final;
        std::vector<Event> getEvents() final;
        void drawMap(const std::vector<std::vector<MapCell>> &cellMap) final;
        void drawGameOver(const std::vector<std::vector<MapCell>> &cellMap, const std::string &score) final
        {
            (void)cellMap;
            (void)score;
        }
        void drawTitle(const std::string &title) final;
        void drawScore(const std::string &score) final
        {
            (void)score;
        }
        void drawBestScore(const std::vector<std::string> &bestScores) final
        {
            (void)bestScores;
        }
};
