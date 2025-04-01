/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml.cpp
*/

#include <iostream>
#include <memory>
#include <vector>

#include "Sfml.hpp"

static std::unique_ptr<Sfml> graphical;

void __attribute__((constructor)) init()
{
    // std::cout << "Library Sfml initialized." << std::endl;
}

void __attribute__((destructor)) cleanup()
{
    graphical.reset();
    // std::cout << "Library Sfml cleaned up." << std::endl;
}

extern "C"
{
    const char *GraphicName()
    {
        return "Sfml";
    }

    IGraphical *getInstance()
    {
        if (!graphical)
        {
            graphical = std::make_unique<Sfml>();
        }
        return graphical.release();
    }
}

Sfml::Sfml()
{
    _window.create(sf::VideoMode(800, 600), "SFML Window");
    if (!_window.isOpen())
    {
        std::cerr << "Error initializing SFML window" << std::endl;
        exit(84);
    }
}

Sfml::~Sfml()
{
    if (_window.isOpen())
    {
        _window.close();
    }
}

void Sfml::render()
{
    _window.display();
}

void Sfml::clear()
{
    _window.clear();
}

void Sfml::drawMap(const std::vector<std::vector<MapCell>> &cellMap)
{
    (void)cellMap;
    render();
}

void Sfml::drawTitle(const std::string &title)
{
    (void)title;
}

std::vector<Event> Sfml::getEvents()
{
    std::vector<Event> events;
    sf::Event sfEvent;

    while (_window.pollEvent(sfEvent))
    {
        switch (sfEvent.type)
        {
            case sf::Event::Closed:
                events.push_back(Event(EventType::QUIT));
                break;
            case sf::Event::KeyPressed:
                switch (sfEvent.key.code)
                {
                    case sf::Keyboard::Up:
                        events.push_back(Event(EventType::KEY_PRESSED, KeyCode::UP_ARROW));
                        break;
                    case sf::Keyboard::Down:
                        events.push_back(Event(EventType::KEY_PRESSED, KeyCode::DOWN_ARROW));
                        break;
                    case sf::Keyboard::Left:
                        events.push_back(Event(EventType::KEY_PRESSED, KeyCode::LEFT_ARROW));
                        break;
                    case sf::Keyboard::Right:
                        events.push_back(Event(EventType::KEY_PRESSED, KeyCode::RIGHT_ARROW));
                        break;
                    case sf::Keyboard::Space:
                        events.push_back(Event(EventType::KEY_PRESSED, KeyCode::SPACE));
                        break;
                    case sf::Keyboard::Tab:
                        events.push_back(Event(EventType::SWITCH_GRAPHICS));
                        break;
                    case sf::Keyboard::Escape:
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