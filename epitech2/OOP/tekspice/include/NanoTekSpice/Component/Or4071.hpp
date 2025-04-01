/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Or4071
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class Or4071 : public AComponent {
        public:
            Or4071();
            ~Or4071();
            void simulate(int tick, bool isSameTick) override;
    };
}