/*
** EPITECH PROJECT, 2025
** display.cpp
** File description:
** display
*/

#include "display.hpp"

void initNcurses()
{
    initscr();                                                                  // Initialise la fenetre ncurses
    noecho();                                                                   // Désactive l'affichage des touches
    curs_set(0);                                                                // Désactive le curseur
    nodelay(stdscr, TRUE);                                                      // Désactive le delais de getch
    start_color();                                                              // Active les couleurs
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);                                 // Initialise la couleur verte
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);                               // Initialise la couleur jaune
    init_pair(RED, COLOR_RED, COLOR_BLACK);                                     // Initialise la couleur rouge
    init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);                                   // Initialise la couleur bleu
}

void display()
{
    initNcurses();
    while (true) {
        clear();                                                                // Clear l'affichage
        displaySystem();                                                        // Affiche les infos systeme
        displayCPU();                                                           // Affiche les infos CPU
    // displayRAM();
    // displayNetwork();
    // displayDate();
    // displayHostname();
    // displayUsername();
    // displayKernel();
    // displayUptime();
    // displayBattery();
    // displayTemperature();
    // displayDisk();
    // displayProcesses();
    // displayTop();
    // displayGraph();
    // displayHelp();
    // displayExit();
    refresh(); // refresh l'affichage pour qu'il s'affiche
    }
    endwin();
}
