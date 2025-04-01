/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** AndComponent
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class AndComponent : public AComponent {
        public:
            AndComponent();
            ~AndComponent();
            void simulate(int tick, bool isSameTick) override;
    };
}