/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Counter4040
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class Counter4040 : public AComponent {
        public:
            Counter4040();
            ~Counter4040();
            void simulate(int tick, bool isSameTick) override;
        private:
            int _value;
            bool _lastClockUp;
    };
}