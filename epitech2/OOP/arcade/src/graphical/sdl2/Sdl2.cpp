/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl2.cpp
*/

#include <iostream>
#include <memory>
#include <vector>

#include <SDL2/SDL.h>
#include "Sdl2.hpp"

static std::unique_ptr<Sdl2> graphical;

void __attribute__((constructor)) init()
{
    // std::cout << "Library SDL2 initialized." << std::endl;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Error initializing SDL2: " << SDL_GetError() << std::endl;
        exit(84);
    }
}

void __attribute__((destructor)) cleanup()
{
    graphical.reset();
    SDL_Quit();
    // std::cout << "Library SDL2 cleaned up." << std::endl;
}

extern "C"
{
    const char *GraphicName()
    {
        return "Sdl2";
    }

    IGraphical *getInstance()
    {
        if (!graphical)
        {
            graphical = std::make_unique<Sdl2>();
        }
        return graphical.release();
    }
}

Sdl2::Sdl2()
{
    _window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!_window)
    {
        std::cerr << "Error initializing SDL2 window: " << SDL_GetError() << std::endl;
        exit(84);
    }
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (!_renderer)
    {
        std::cerr << "Error creating SDL2 renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(_window);
        exit(84);
    }
}

Sdl2::~Sdl2()
{
    if (_renderer)
    {
        SDL_DestroyRenderer(_renderer);
    }
    if (_window)
    {
        SDL_DestroyWindow(_window);
    }
}

void Sdl2::render()
{
    SDL_RenderPresent(_renderer);
}

void Sdl2::clear()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

void Sdl2::drawMap(const std::vector<std::vector<MapCell>> &cellMap)
{
    (void)cellMap;
    render();
}

void Sdl2::drawTitle(const std::string &title)
{
    (void)title;
}

std::vector<Event> Sdl2::getEvents()
{
    std::vector<Event> events;
    SDL_Event sdlEvent;

    while (SDL_PollEvent(&sdlEvent))
    {
        switch (sdlEvent.type)
        {
            case SDL_QUIT:
                events.push_back(Event(EventType::QUIT));
                break;
            case SDL_KEYDOWN:
                switch (sdlEvent.key.keysym.sym)
                {
                    case SDLK_UP:
                        events.push_back(Event(EventType::KEY_PRESSED, KeyCode::UP_ARROW));
                        break;
                    case SDLK_DOWN:
                        events.push_back(Event(EventType::KEY_PRESSED, KeyCode::DOWN_ARROW));
                        break;
                    case SDLK_LEFT:
                        events.push_back(Event(EventType::KEY_PRESSED, KeyCode::LEFT_ARROW));
                        break;
                    case SDLK_RIGHT:
                        events.push_back(Event(EventType::KEY_PRESSED, KeyCode::RIGHT_ARROW));
                        break;
                    case SDLK_SPACE:
                        events.push_back(Event(EventType::KEY_PRESSED, KeyCode::SPACE));
                        break;
                    case SDLK_TAB:
                        events.push_back(Event(EventType::SWITCH_GRAPHICS));
                        break;
                    case SDLK_ESCAPE:
                        events.push_back(Event(EventType::QUIT));
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    return events;
}