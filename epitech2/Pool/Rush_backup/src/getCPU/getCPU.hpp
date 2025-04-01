/*
** EPITECH PROJECT, 2025
** getCPU.hpp
** File description:
** getCPU
*/

#ifndef GETCPU_HPP_
#define GETCPU_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

struct CPUStats {
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
};

CPUStats getCPUStats();
double getCPUUsage();
std::vector<CPUStats> readAllCoreStats();
double calculateCoreUsage(const CPUStats& prev, const CPUStats& curr);


#endif /* !GETCPU_HPP_ */
