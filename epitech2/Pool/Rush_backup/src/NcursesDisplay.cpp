/*
** EPITECH PROJECT, 2025
** NcursesDisplay.cpp
** File description:
** NcursesDisplay
*/

#include "../include/NcursesDisplay.hpp"
#include <iostream>

namespace Krell {
    NcursesDisplay::NcursesDisplay() {
        initscr(); // Initialise nCurses
        start_color(); // Active les couleurs
        noecho(); // Désactive l'affichage des entrées clavier
        curs_set(0); // Cache le curseur
        nodelay(stdscr, TRUE); // Mode non bloquant
        initColors(); // Initialise les couleurs
    }

    NcursesDisplay::~NcursesDisplay() {
        endwin(); // Termine nCurses
    }

    void NcursesDisplay::display(const std::vector<std::shared_ptr<IModule>>& modules) {
        clear(); // Efface l'écran

        int row = 2;
        for (const auto& module : modules) {
            attron(COLOR_PAIR(1));
            mvprintw(row, 5, "%s", module->getName().c_str());
            attroff(COLOR_PAIR(1));

            mvprintw(row + 1, 5, "%s", module->getData().c_str());
            row += 3;
        }

        refresh(); // Met à jour l'écran
    }

    void NcursesDisplay::handleEvents() {
        if (getch() != ERR) { // Si une touche est pressée
            endwin();
            exit(0); // Quitte le programme
        }
    }

    void NcursesDisplay::initColors() {
        start_color();
        init_pair(1, COLOR_YELLOW, COLOR_BLACK); // Texte jaune sur fond noir
    }
}
