/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** FlipFlop4013
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class FlipFlop4013 : public AComponent {
        public:
            FlipFlop4013();
            ~FlipFlop4013();
            void simulate(int tick, bool isSameTick) override;
        private:
            bool _lastClockUp;
            bool _lastClockUp2;
    };
}