/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Adder4008
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class Adder4008 : public AComponent {
        public:
            Adder4008();
            ~Adder4008();
            void simulate(int tick, bool isSameTick) override;
        private:
            Tristate addWithCarry(Tristate a, Tristate b, Tristate carryIn);
            Tristate getCarryOut(Tristate a, Tristate b, Tristate carryIn);
    };
}