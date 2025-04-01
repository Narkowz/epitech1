/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** IGame
*/

#pragma once

#include <string>
#include <vector>
#include <memory>

#include "IGraphical.hpp"
#include "Event.hpp"

class IGame
{
    public :
        IGame() = default;
        virtual ~IGame() = default;

        virtual void update(float elapsedTime) = 0;
        virtual void handleEvent(std::vector<Event> gameEvents) = 0;
        virtual void display(std::shared_ptr<IGraphical> graphical) = 0;
        virtual bool isPaused() const = 0;
        virtual void setPaused(bool paused) = 0;
        virtual bool isOver() const = 0;
        virtual void restart() = 0;
        virtual bool isRunning() const = 0;
        virtual std::string getName() const = 0;
};
