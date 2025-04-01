/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** XorComponent
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class XorComponent : public AComponent {
        public:
            XorComponent();
            ~XorComponent();
            void simulate(int tick, bool isSameTick) override;
    };
}