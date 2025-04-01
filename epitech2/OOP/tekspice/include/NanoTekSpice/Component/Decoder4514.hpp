/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Decoder4514
*/

#pragma once

#include "NanoTekSpice/Component/AComponent.hpp"

namespace NanoTekSpice {
    class Decoder4514 : public AComponent {
        public:
            Decoder4514();
            ~Decoder4514();
            void simulate(int tick, bool isSameTick) override;
        private:
            bool _lastStrobeDown;
            int _lastLatchedValue;
    };
}