/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Nor4001
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class Nor4001 : public AComponent {
        public:
            Nor4001();
            ~Nor4001();
            void simulate(int tick, bool isSameTick) override;
    };
}