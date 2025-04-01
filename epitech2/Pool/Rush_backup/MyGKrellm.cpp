/*
** EPITECH PROJECT, 2025
** main.cpp
** File description:
** main
*/

#include "MyGKrellm.hpp"
#include "include/Monitor.hpp"
#include "modules/CPUModule.hpp"
#include "include/NcursesDisplay.hpp"
#include <memory>

int main() {
    // Crée une instance de Monitor
    Krell::Monitor monitor;

    // Ajoute le module CPU
    monitor.addModule(std::make_shared<Krell::CPUModule>());

    // Configure l'affichage nCurses
    monitor.setDisplay(std::make_shared<Krell::NcursesDisplay>());

    // Lance le programme
    monitor.run();

    return 0;
}