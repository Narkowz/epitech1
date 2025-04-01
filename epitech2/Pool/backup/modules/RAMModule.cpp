/*
** EPITECH PROJECT, 2025
** RAMModule.cpp
** File description:
** RAMModule
*/

#include "RAMModule.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

#ifdef __linux__
Krell::RAMModule::MemoryStats Krell::RAMModule::getMemoryStatsFromFree() const {
    MemoryStats stats = {0, 0, 0, 0, 0, 0, 0};
    
    FILE* fp = popen("free", "r");
    if (fp == nullptr) {
        std::cerr << "Erreur lors de l'exec de la commande free." << std::endl;
        return stats;
    }

    char line[256];
    fgets(line, sizeof(line), fp);
    fgets(line, sizeof(line), fp);

    std::istringstream iss(line);
    std::string label;
    
    iss >> label >> stats.total >> stats.used >> stats.free >> stats.shared >> stats.buffers >> stats.cached >> stats.available;

    fclose(fp);

    stats.total /= 1024;
    stats.used /= 1024;
    stats.shared /= 1024;

    return stats;
}

#elif __APPLE__
#include <sys/sysctl.h>
#include <mach/mach.h>

Krell::RAMModule::MemoryStats Krell::RAMModule::getMemoryStats() const {
    MemoryStats stats = {0, 0, 0, 0, 0, 0, 0};
    mach_msg_type_number_t count;
    vm_size_t page_size;
    vm_statistics_data_t vm_stats;
    host_page_size(mach_host_self(), &page_size);
    count = HOST_VM_INFO_COUNT;
    
    if (host_statistics(mach_host_self(), HOST_VM_INFO, (host_info_t)&vm_stats, &count) == KERN_SUCCESS) {
        stats.total = vm_stats.active_count + vm_stats.inactive_count + vm_stats.free_count;
        stats.free = vm_stats.free_count;
        stats.available = vm_stats.free_count + vm_stats.inactive_count;
        stats.used = stats.total - stats.free;
    }
    return stats;
}
#endif

namespace Krell {
    RAMModule::RAMModule() : _name("RAM") {}

    void RAMModule::updateData() {
#ifdef __linux__
        _stats = getMemoryStatsFromFree();
#elif __APPLE__
        _stats = getMemoryStats();
#endif
    }

    std::string RAMModule::getName() const {
        return _name;
    }

    std::string RAMModule::getData() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2);
        double usedPercentage = (_stats.total > 0) ? (_stats.used / _stats.total) * 100.0 : 0.0;
        double availablePercentage = (_stats.total > 0) ? (_stats.available / _stats.total) * 100.0 : 0.0;
#ifdef __linux__
        oss << "Total Memory: " << (_stats.total / 1024.0) << " GB\n"
            << "Used Memory: " << (_stats.used / 1024.0) << " GB (" 
            << ((_stats.total > 0) ? ((_stats.used + _stats.shared) * 100.0 / _stats.total) : 0.0) << "%)\n"
            << "Free Memory: " << (_stats.free / 1024.0) << " GB\n"
            << "Available Memory: " << (_stats.available / 1024.0) << " GB (" 
            << ((_stats.total > 0) ? (_stats.available * 100.0 / _stats.total) : 0.0) << "%)\n";
#elif __APPLE__
        oss << "Total Memory: " << _stats.total / 1024.0 << " GB\n"
            << "Used Memory: " << _stats.used / 1024.0 << " GB\n"
            << "Free Memory: " << _stats.free / 1024.0 << " GB\n"
            << "Available Memory: " << _stats.available / 1024.0 << " GB";
#endif
        return oss.str();
    }
}
