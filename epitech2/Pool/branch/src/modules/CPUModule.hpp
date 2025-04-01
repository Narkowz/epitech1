/*
** EPITECH PROJECT, 2025
** CPUModule.hpp
** File description:
** CPUModule
*/

#ifndef CPUMODULE_HPP_
#define CPUMODULE_HPP_

#include "../include/IModule.hpp"
#include <string>
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

namespace Krell {
    class CPUModule : public IModule {
    public:
        CPUModule();
        void updateData() override;
        std::string getName() const override;
        std::string getData() const override;
        bool isExpanded() const override {
        return _isExpanded;
    }

    void toggleExpanded() override {
        _isExpanded = !_isExpanded;
    }

    private:
        std::string _name;
        double _usage;
        std::vector<double> _coreUsage;

        double getCPUUsage();
        std::vector<double> getAllCoreUsage();
        double calculateCoreUsage(const CPUStats& prev, const CPUStats& curr);
        bool _isExpanded = true;
    };
}

#endif /* !CPUMODULE_HPP_ */
