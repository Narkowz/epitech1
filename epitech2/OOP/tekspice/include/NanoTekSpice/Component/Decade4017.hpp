/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Decade4017
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class Decade4017 : public AComponent {
        public:
            Decade4017();
            ~Decade4017();
            void simulate(int tick, bool isSameTick) override;
        private:
            int _value;
            int _carryOutCounter;
            bool _lastClockUp; 
    };
}