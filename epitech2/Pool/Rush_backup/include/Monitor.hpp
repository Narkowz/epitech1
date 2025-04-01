/*
** EPITECH PROJECT, 2025
** Monitor.hpp
** File description:
** Monitor
*/

#ifndef MONITOR_HPP_
#define MONITOR_HPP_

#include <vector>
#include <memory>
#include "IModule.hpp"
#include "IDisplay.hpp"

namespace Krell {
    class Monitor {
    public:
        Monitor();
        void addModule(std::shared_ptr<IModule> module);
        void setDisplay(std::shared_ptr<IDisplay> display);
        void run();

    private:
        std::vector<std::shared_ptr<IModule>> _modules;
        std::shared_ptr<IDisplay> _display;
    };
}

#endif /* !MONITOR_HPP_ */
