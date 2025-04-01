/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** InputComponent
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class InputComponent : public AComponent {
        private:
            Tristate _tempValue;
            bool _recentlytUpdated = false;
        public:
            InputComponent();
            ~InputComponent();
            void simulate(int tick, bool isSameTick) override;
            void setValue(Tristate value, int) override;
    };
}