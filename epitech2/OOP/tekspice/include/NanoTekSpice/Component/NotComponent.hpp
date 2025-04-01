/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** NotComponent
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class NotComponent : public AComponent {
        public:
            NotComponent();
            ~NotComponent();
            void simulate(int tick, bool isSameTick) override;
    };
}