/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Logger
*/

#include "NanoTekSpice/Component/Logger.hpp"

namespace NanoTekSpice {
    Logger::Logger() : AComponent(11, ComponentType::CT_LOGGER) {
        _lastClockUp = false;
    }

    Logger::~Logger() {}

    void Logger::simulate(int tick, bool isSameTick) {
        if (isSameTick) {
            return;
        }

        Tristate inhib = simulateLink(10, tick);
        Tristate clock = simulateLink(9, tick);

        Tristate values[8] = {
            simulateLink(1, tick),
            simulateLink(2, tick),
            simulateLink(3, tick),
            simulateLink(4, tick),
            simulateLink(5, tick),
            simulateLink(6, tick),
            simulateLink(7, tick),
            simulateLink(8, tick)
        };

        char val = 0;

        for (int i = 0; i < 8; i++) {
            if (values[i] == Tristate())
                return;
            val += values[i] == Tristate(1) ? 1 << i : 0;
        }
        
        if (inhib == Tristate(1) || clock != Tristate(1)) {
            _lastClockUp = false;
            return;
        }
        if (_lastClockUp)
            return;

        if (inhib == Tristate(0)) {
            std::ofstream outfile;
            outfile.open("./log.bin", std::ios_base::app);
            outfile << val;
            outfile.close();
            _lastClockUp = true;
        }
    }
}