/*
** EPITECH PROJECT, 2025
** CPUModule.cpp
** File description:
** CPUModule
*/

#include "CPUModule.hpp"
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <iomanip>

#ifdef __linux__
CPUStats getCPUStats()
{
    CPUStats stats = {0, 0, 0, 0, 0, 0, 0};
    std::ifstream stat("/proc/stat");
    std::string line;
    if (std::getline(stat, line)) {
        std::istringstream iss(line);
        std::string cpuLabel;
        iss >> cpuLabel >> stats.user >> stats.nice >> stats.system >> stats.idle
            >> stats.iowait >> stats.irq >> stats.softirq;
    }
    return stats;
}

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
#include <sys/sysctl.h>
#include <mach/mach.h>

CPUStats getCPUStats()
{
    CPUStats stats = {0, 0, 0, 0, 0, 0, 0};
    host_cpu_load_info_data_t cpuInfo;
    mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
    if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuInfo, &count) == KERN_SUCCESS) {
        stats.user = cpuInfo.cpu_ticks[CPU_STATE_USER];
        stats.system = cpuInfo.cpu_ticks[CPU_STATE_SYSTEM];
        stats.idle = cpuInfo.cpu_ticks[CPU_STATE_IDLE];
        stats.nice = cpuInfo.cpu_ticks[CPU_STATE_NICE];
    }
    return stats;
}

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



namespace Krell {
    CPUModule::CPUModule() : _name("CPU"), _usage(0.0) {}

    void CPUModule::updateData() {
        _usage = getCPUUsage();
        _coreUsage = getAllCoreUsage();
    }

    std::string CPUModule::getName() const {
        return _name;
    }

    std::string CPUModule::getData() const {
        std::ostringstream oss;
        oss << "Total CPU Usage: " << std::fixed << std::setprecision(2) << _usage << "%\n";
        for (size_t i = 0; i < _coreUsage.size(); ++i) {
            oss << "Core " << i << ": " << _coreUsage[i] << "%\n";
        }
        return oss.str();
    }

    double CPUModule::calculateCoreUsage(const CPUStats& prev, const CPUStats& curr) {
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

    double CPUModule::getCPUUsage()
    {
        CPUStats prevStats = getCPUStats();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        CPUStats currStats = getCPUStats();

        return calculateCoreUsage(prevStats, currStats);
    }

    std::vector<double> CPUModule::getAllCoreUsage() {
        std::vector<CPUStats> prevStats = readAllCoreStats();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::vector<CPUStats> currStats = readAllCoreStats();

        std::vector<double> coreUsage;
        for (size_t i = 0; i < currStats.size(); ++i) {
            coreUsage.push_back(calculateCoreUsage(prevStats[i], currStats[i]));
        }
        return coreUsage;
    }
}
