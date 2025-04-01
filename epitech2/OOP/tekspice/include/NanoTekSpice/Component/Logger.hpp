/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Logger
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

#include <fstream>

namespace NanoTekSpice {
    class Logger : public AComponent {
        public:
            Logger();
            ~Logger();
            void simulate(int tick, bool isSameTick) override;
        private:
            bool _lastClockUp;
    };
}