/*
** EPITECH PROJECT, 2025
** getCpu.cpp
** File description:
** getCPU
*/

#include "getCPU.hpp"
#include "../../MyGKrellm.hpp"

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
#endif

double getCPUUsage()
{
    CPUStats stats1 = getCPUStats();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    CPUStats stats2 = getCPUStats();

    unsigned long prevIdle = stats1.idle + stats1.iowait;
    unsigned long idle = stats2.idle + stats2.iowait;

    unsigned long prevNonIdle = stats1.user + stats1.nice + stats1.system + stats1.irq + stats1.softirq;
    unsigned long nonIdle = stats2.user + stats2.nice + stats2.system + stats2.irq + stats2.softirq;

    unsigned long prevTotal = prevIdle + prevNonIdle;
    unsigned long total = idle + nonIdle;

    unsigned long totalDiff = total - prevTotal;
    unsigned long idleDiff = idle - prevIdle;

    if (totalDiff == 0) return 0.0;
    return (totalDiff - idleDiff) * 100.0 / totalDiff;
}
