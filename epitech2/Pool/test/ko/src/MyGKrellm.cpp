/*
** EPITECH PROJECT, 2025
** main.cpp
** File description:
** main
*/

#include "MyGKrellm.hpp"
#include "include/monitor.hpp"
#include "modules/CPUModule.hpp"
#include "modules/SYSModule.hpp"
#include "modules/RAMModule.hpp"
#include "include/ncursesDisplay.hpp"
#include "SFMLDisplay.hpp"
#include "modules/NETModule.hpp"
#include <memory>

int main() {
    // Crée une instance de Monitor
    Krell::Monitor monitor;

    // Ajoute le module CPU
    monitor.addModule(std::make_shared<Krell::SYSModule>());
    monitor.addModule(std::make_shared<Krell::CPUModule>());
    monitor.addModule(std::make_shared<Krell::RAMModule>());
    monitor.addModule(std::make_shared<Krell::NETModule>());

    // Configure l'affichage nCurses
    monitor.setDisplay(std::make_shared<Krell::SFMLDisplay>());

    // Lance le programme
    monitor.run();

    return 0;
}