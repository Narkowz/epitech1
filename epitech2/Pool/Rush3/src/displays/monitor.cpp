/*
** EPITECH PROJECT, 2025
** Monitor.cpp
** File description:
** Monitor
*/

#include "../include/monitor.hpp"
#include <thread>
#include <chrono>

namespace Krell {
    Monitor::Monitor() {}

    void Monitor::addModule(std::shared_ptr<IModule> module)
    {
        _modules.push_back(module);
    }

    void Monitor::setDisplay(std::shared_ptr<IDisplay> display)
    {
        _display = display;
    }

    void Monitor::run()
    {
        while (true) {
            for (const auto& module : _modules) {
                module->updateData();
            }
            _display->display(_modules);
            _display->handleEvents();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
}
