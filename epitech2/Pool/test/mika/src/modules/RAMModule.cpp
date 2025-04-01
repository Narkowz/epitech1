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

    std::ifstream file("/proc/meminfo");
    if (!file)
        return stats;

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("MemTotal") == 0) std::sscanf(line.c_str(), "MemTotal: %llu kB", &stats.total);
        else if (line.find("MemFree") == 0) std::sscanf(line.c_str(), "MemFree: %llu kB", &stats.free);
        else if (line.find("MemAvailable") == 0) std::sscanf(line.c_str(), "MemAvailable: %llu kB", &stats.available);
        else if (line.find("Buffers") == 0) std::sscanf(line.c_str(), "Buffers: %llu kB", &stats.buffers);
        else if (line.find("Cached") == 0) std::sscanf(line.c_str(), "Cached: %llu kB", &stats.cached);
    }

    stats.total /= 1024;
    stats.free /= 1024;
    stats.available /= 1024;
    stats.buffers /= 1024;
    stats.cached /= 1024;
    stats.used = (stats.total - stats.available);

    return stats;
}

#elif __APPLE__
#include <sys/sysctl.h>
#include <mach/mach.h>

Krell::RAMModule::MemoryStats Krell::RAMModule::getMemoryStats() const {
    MemoryStats stats = {0, 0, 0, 0};

    size_t size = sizeof(stats.total);
    if (sysctlbyname("hw.memsize", &stats.total, &size, NULL, 0) != 0)
        std::cerr << "ERROR" << std::endl;

    vm_statistics64_data_t vm_stats;
    mach_msg_type_number_t count = HOST_VM_INFO64_COUNT;
    vm_size_t page_size;
    host_page_size(mach_host_self(), &page_size);

    if (host_statistics64(mach_host_self(), HOST_VM_INFO, (host_info64_t)&vm_stats, &count) == KERN_SUCCESS) {
        stats.free = vm_stats.free_count * page_size;
        stats.available = stats.free + (vm_stats.inactive_count * page_size);
        stats.used = stats.total - stats.free;
    } else
        std::cerr << "ERROR" << std::endl;

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
        oss << "Total Memory: " << (_stats.total / (1024.0)) << " MB\n"
            << "Used Memory: " << (_stats.used / 1024) << " GB (" 
            << ((_stats.total > 0) ? ((_stats.used + _stats.shared) * 100.0 / _stats.total) : 0.0) << "%)\n"
            << "Free Memory: " << (_stats.free) << " MB\n"
            << "Available Memory: " << (_stats.available / (1024.0)) << " GB (" 
            << ((_stats.total > 0) ? (_stats.available * 100.0 / _stats.total) : 0.0)<< "%)\n";
#elif __APPLE__
        oss << "Total Memory: " << _stats.total / (1024.0 * 1024.0) << " MB\n"
            << "Used Memory: " << _stats.used / (1024.0 * 1024.0) << " MB\n"
            << "Free Memory: " << _stats.free / (1024.0 * 1024.0) << " MB\n"
            << "Available Memory: " << _stats.available / (1024.0 * 1024.0) << " MB";
#endif
        return oss.str();
    }
}
