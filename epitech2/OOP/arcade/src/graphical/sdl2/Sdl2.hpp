/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Sdl2
*/

#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "IGraphical.hpp"

class Sdl2 : public IGraphical
{
    protected:
        SDL_Window *_window;
        SDL_Renderer *_renderer;

    public:
        Sdl2();
        ~Sdl2();
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
