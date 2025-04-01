/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** OrComponent
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class OrComponent : public AComponent {
        public:
            OrComponent();
            ~OrComponent();
            void simulate(int tick, bool isSameTick) override;
    };
}