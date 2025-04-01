/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** diplay_cpu
*/

//#include "../MyGKrellm.hpp"
//#include <mach/mach.h>
#include "displayCPU.hpp"

void displayCore()
{
    std::vector<CPUStats> prevStats = readAllCoreStats();                       // Récupere les stats du CPU
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::vector<CPUStats> currStats = readAllCoreStats();
    for (size_t i = 0; i < currStats.size(); ++i) {                             // Pour chaque core
        double usage = calculateCoreUsage(prevStats[i], currStats[i]);          // Calcul l'utilisation du core
        mvprintw(10 + i, 35, "Core %d Usage: ", i);                             // Print le n° core
        if (usage < 33) {                                                       // Si l'utilisation est inférieur à 33%
            attron(COLOR_PAIR(GREEN));                                          // Active la couleur verte
            mvprintw(10 + i, 35 + 16, "%.2f%%", usage);                         // Print l'utilisation
            attroff(COLOR_PAIR(GREEN));                                         // Désactive la couleur verte
        }
        if (usage > 33 && usage < 66) {
            attron(COLOR_PAIR(YELLOW));
            mvprintw(10 + i, 35 + 16, "%.2f%%", usage);
            attroff(COLOR_PAIR(YELLOW));
        }
        if (usage > 66) {
            attron(COLOR_PAIR(RED));
            mvprintw(10 + i, 35 + 16, "%.2f%%", usage);
            attroff(COLOR_PAIR(RED));
        }
    }
}

void displayCPU()
{
    int row = 8;                                                                // Position verticale de départ pour l'affichage
    double cpuusage = getCPUUsage();                                            // Récupere le % d'utilisation du CPU
    attron(COLOR_PAIR(1));                                                      // Active la couleur Jaune
    mvprintw(row, 5, "Stats CPU");                                              // Print cette ligne
    attroff(COLOR_PAIR(1));                                                     // Désactive la couleur Jaune
    mvprintw(row + 2, 5, "Total CPU Usage   : %.2f%%", cpuusage);               // Print l'utilisation du cpu
    std::this_thread::sleep_for(std::chrono::milliseconds(500));                // Laisse un delais pour pas enculer le proc
    displayCore();
}
