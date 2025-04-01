/*
** EPITECH PROJECT, 2025
** ncursesDisplay.cpp
** File description:
** ncursesDisplay
*/

#include "include/ncursesDisplay.hpp"
#include <iostream>
#include <sstream>

namespace Krell {
    ncursesDisplay::ncursesDisplay() {
        initscr(); // Initialise nCurses
        start_color(); // Active les couleurs
        noecho(); // Désactive l'affichage des entrées clavier
        curs_set(0); // Cache le curseur
        nodelay(stdscr, TRUE); // Mode non bloquant
        initColors(); // Initialise les couleurs
    }

    ncursesDisplay::~ncursesDisplay() {
        endwin(); // Termine nCurses
    }

    void ncursesDisplay::display(const std::vector<std::shared_ptr<IModule>>& modules) {
    clear(); // Efface l'écran

    int row = 2;
    int col = 5;
    int maxCols = 5; // Nombre de colonnes

    for (const auto& module : modules) {
        attron(COLOR_PAIR(BLUE));
        mvprintw(row, col, "%s", module->getName().c_str());
        attroff(COLOR_PAIR(BLUE));

        // Affiche les données du module
        std::istringstream iss(module->getData());
        std::string line;
        int coreRow = row + 2;
        while (std::getline(iss, line)) {
            mvprintw(coreRow, col, "%s", line.c_str());
            coreRow++;
        }

        // Passe à la colonne suivante
        col += 40; // Espacement entre les colonnes
        if (col > maxCols * 20) { // Si on dépasse le nombre de colonnes, passe à la ligne suivante
            col = 5;
            row += 15; // Espacement entre les lignes
        }
    }

    refresh(); // Met à jour l'écran
}

    void ncursesDisplay::handleEvents() {
        if (getch() != ERR) { // Si une touche est pressée
            endwin();
            exit(0); // Quitte le programme
        }
    }

    void ncursesDisplay::initColors() {
        start_color();
        init_pair(GREEN, COLOR_GREEN, COLOR_BLACK); // Texte vert sur fond noir
        init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK); // Texte jaune sur fond noir
        init_pair(RED, COLOR_RED, COLOR_BLACK); // Texte rouge sur fond noir
        init_pair(BLUE, COLOR_BLUE, COLOR_BLACK); // Texte bleu sur fond noir
    }
}
