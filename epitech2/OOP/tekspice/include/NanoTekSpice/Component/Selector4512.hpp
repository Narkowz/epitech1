/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Selector4512
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class Selector4512 : public AComponent {
        public:
            Selector4512();
            ~Selector4512();
            void simulate(int tick, bool isSameTick) override;
    };
}