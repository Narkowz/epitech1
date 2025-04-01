/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** ClockComponent
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class ClockComponent : public AComponent {
        private:
            Tristate _tempValue;
            bool _recentlytUpdated = false;
        public:
            ClockComponent();
            ~ClockComponent();
            void simulate(int tick, bool isSameTick) override;
            void setValue(Tristate value, int) override;
    };
}