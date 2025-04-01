/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Not4069
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class Not4069 : public AComponent {
        public:
            Not4069();
            ~Not4069();
            void simulate(int tick, bool isSameTick) override;
    };
}