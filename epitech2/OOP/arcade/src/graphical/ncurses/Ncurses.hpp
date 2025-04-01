/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Ncurses
*/

#pragma once

#include <iostream>
#include <vector>
#include <ncurses.h>

#include "IGraphical.hpp"

class Ncurses : public IGraphical
{
    protected:
        WINDOW *_window;
        WINDOW *_gameBox;

    public:
        Ncurses();
        ~Ncurses();
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
