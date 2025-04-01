/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Nand4011
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class Nand4011 : public AComponent {
        public:
            Nand4011();
            ~Nand4011();
            void simulate(int tick, bool isSameTick) override;
    };
}