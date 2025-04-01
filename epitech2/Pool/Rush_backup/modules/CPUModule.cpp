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
// Implémentation pour Linux
#elif __APPLE__
// Implémentation pour macOS
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
        oss << "Usage: " << std::fixed << std::setprecision(2) << _usage << "%\n";
        for (size_t i = 0; i < _coreUsage.size(); ++i) {
            oss << "Core " << i << ": " << _coreUsage[i] << "%\n";
        }
        return oss.str();
    }

    double CPUModule::getCPUUsage() {
        // Implémentation de getCPUUsage()
        return 0.0; // Remplace par ton code
    }

    std::vector<double> CPUModule::getAllCoreUsage() {
        // Implémentation de getAllCoreUsage()
        return {}; // Remplace par ton code
    }
}
