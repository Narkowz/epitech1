/*
** EPITECH PROJECT, 2025
** RAMModule.hpp
** File description:
** RAMModule
*/

#ifndef RAMMODULE_HPP_
#define RAMMODULE_HPP_

#include "../include/IModule.hpp"

namespace Krell {
    class RAMModule : public IModule {
    public:
        RAMModule();
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
        struct MemoryStats {
            unsigned long total;
            unsigned long used;
            unsigned long free;
            unsigned long shared;
            unsigned long buffers;
            unsigned long cached;
            unsigned long available;
        } _stats;

        MemoryStats getMemoryStatsFromFree() const;
        MemoryStats getMemoryStats() const;
        bool _isExpanded = true;
    };
}

#endif /* !RAMMODULE_HPP_ */
