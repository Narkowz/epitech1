/*
** EPITECH PROJECT, 2025
** getCore.cpp
** File description:
** getCore
*/

#include "getCPU.hpp"

#ifdef __linux__
std::vector<CPUStats> readAllCoreStats()
{
    std::vector<CPUStats> stats;                                                // Crée un vecteur de CPUStats
    std::ifstream stat("/proc/stat");                                           // Ouvre le fichier /proc/stat
    std::string line;                                                           // Crée une chaine de caractère pour stocker les lignes du fichier

    while (std::getline(stat, line)) {                                          // Tant qu'on peut lire une ligne
        if (line.substr(0, 3) == "cpu" && line != "cpu") {                      // Ignore la ligne "cpu"
            CPUStats coreStats = {0, 0, 0, 0, 0, 0, 0};                         // Crée une structure CPUStats
            std::istringstream iss(line);                                       // Crée un flux pour lire la ligne
            std::string cpuLabel;                                               // Crée une chaine de caractère pour stocker le label du CPU
            iss >> cpuLabel >> coreStats.user >> coreStats.nice >> coreStats.system >> coreStats.idle 
                >> coreStats.iowait >> coreStats.irq >> coreStats.softirq;
            stats.push_back(coreStats);                                         // Ajoute les stats du CPU au vecteur
        }
    }

    return stats;
}

#elif __APPLE__
#include <mach/mach.h>
#include <mach/processor_info.h>
#include <mach/host_info.h>

std::vector<CPUStats> readAllCoreStats()
{
    std::vector<CPUStats> stats;                                                // Crée un vecteur de CPUStats
    processor_cpu_load_info_t cpuLoadInfo;                                      // Crée une structure pour stocker les informations du CPU
    mach_msg_type_number_t cpuMsgCount;                                         // Crée un compteur pour le nombre de messages
    natural_t processorCount;                                                   // Crée un compteur pour le nombre de processeurs

    // Récupère les informations du CPU
    if (host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &processorCount,
                            reinterpret_cast<processor_info_array_t*>(&cpuLoadInfo), &cpuMsgCount) == KERN_SUCCESS) { // Si on peut récupérer les informations
        for (natural_t i = 0; i < processorCount; ++i) {                        // Pour chaque processeur
            CPUStats coreStats = {                                              // Crée une structure CPUStats
                cpuLoadInfo[i].cpu_ticks[CPU_STATE_USER],                       // Stocke les informations du CPU
                cpuLoadInfo[i].cpu_ticks[CPU_STATE_NICE],
                cpuLoadInfo[i].cpu_ticks[CPU_STATE_SYSTEM],
                cpuLoadInfo[i].cpu_ticks[CPU_STATE_IDLE],
                0,                                                              // iowait n'est pas disponible sur macOS
                0,                                                              // irq n'est pas disponible sur macOS
                0                                                               // softirq n'est pas disponible sur macOS
            };
            stats.push_back(coreStats);                                         // Ajoute les stats du CPU au vecteur
        }
    }

    return stats;
}
#endif

double calculateCoreUsage(const CPUStats& prev, const CPUStats& curr)
{
    unsigned long prevIdle = prev.idle + prev.iowait;
    unsigned long idle = curr.idle + curr.iowait;

    unsigned long prevNonIdle = prev.user + prev.nice + prev.system + prev.irq + prev.softirq;
    unsigned long nonIdle = curr.user + curr.nice + curr.system + curr.irq + curr.softirq;

    unsigned long prevTotal = prevIdle + prevNonIdle;
    unsigned long total = idle + nonIdle;

    unsigned long totalDiff = total - prevTotal;
    unsigned long idleDiff = idle - prevIdle;

    if (totalDiff == 0)
        return 0.0;
    return (totalDiff - idleDiff) * 100.0 / totalDiff;
}
