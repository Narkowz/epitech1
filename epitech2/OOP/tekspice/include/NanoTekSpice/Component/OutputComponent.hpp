/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** OutputComponent
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class OutputComponent : public AComponent {
        public:
            OutputComponent();
            ~OutputComponent();
            void simulate(int tick, bool isSameTick) override;
    };
}