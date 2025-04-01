/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Register4094
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class Register4094 : public AComponent {
        public:
            Register4094();
            ~Register4094();
            void simulate(int tick, bool isSameTick) override;
        private:
            int _savedValue;
            int _latchedValue;
            bool _lastClockUp;
    };
}