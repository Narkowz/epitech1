/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Xor4030
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class Xor4030 : public AComponent {
        public:
            Xor4030();
            ~Xor4030();
            void simulate(int tick, bool isSameTick) override;
    };
}