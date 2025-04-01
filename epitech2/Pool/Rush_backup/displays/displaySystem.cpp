/*
** EPITECH PROJECT, 2025
** displaySystem.cpp
** File description:
** displaySystem
*/

#include "displaySystem.hpp"

void displaySystem()
{
    int row = 2;                                                                // Position verticale de départ pour l'affichage
    char hostname[500];                                                         // Créer un buffer pour stocker le hostname

    gethostname(hostname, 500);                                                 // Récupère le hostname
    attron(COLOR_PAIR(BLUE));                                                      // Active la couleur Jaune
    mvprintw(row, 5, "System");                                                 // Print cette ligne
    attroff(COLOR_PAIR(BLUE));                                                     // Désactive la couleur Jaune
    mvprintw(row + 2, 5, "Hostname: %s", hostname);                             // Print le hostname
    mvprintw(row + 3, 5, "Username: %s", getlogin());                           // Print le nom d'utilisateur
    mvprintw(row + 4, 5, "OS: %s", getOS() == MACOS ? "MacOS" : "Linux");       // Print le nom de l'OS
    std::this_thread::sleep_for(std::chrono::milliseconds(500));                // Laisse un delais pour pas enculer le proc
}
