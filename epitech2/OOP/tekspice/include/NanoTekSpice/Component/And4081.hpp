/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** And4081
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class And4081 : public AComponent {
        public:
            And4081();
            ~And4081();
            void simulate(int tick, bool isSameTick) override;
    };
}