/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** TrueComponent
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class TrueComponent : public AComponent {
        public:
            TrueComponent();
            ~TrueComponent();
            void simulate(int tick, bool isSameTick) override;
    };
}