/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** FalseComponent
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class FalseComponent : public AComponent {
        public:
            FalseComponent();
            ~FalseComponent();
            void simulate(int tick, bool isSameTick) override;
    };
}