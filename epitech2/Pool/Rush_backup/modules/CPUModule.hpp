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

namespace Krell {
    class CPUModule : public IModule {
    public:
        CPUModule();
        void updateData() override;
        std::string getName() const override;
        std::string getData() const override;

    private:
        std::string _name;
        double _usage;
        std::vector<double> _coreUsage;

        double getCPUUsage();
        std::vector<double> getAllCoreUsage();
    };
}

#endif /* !CPUMODULE_HPP_ */
