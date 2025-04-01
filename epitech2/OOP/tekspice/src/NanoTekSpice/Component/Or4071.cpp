/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Or4071
*/

#include "NanoTekSpice/Component/Or4071.hpp"

namespace NanoTekSpice {
    Or4071::Or4071() : AComponent(15, ComponentType::CT_4071) {
        _outputs[3] = Tristate();
        _outputs[4] = Tristate();
        _outputs[11] = Tristate();
        _outputs[10] = Tristate();
    }

    Or4071::~Or4071() {}

    void Or4071::simulate(int tick, bool isSameTick) {
        Tristate val1 = simulateLink(1, tick, isSameTick);
        Tristate val2 = simulateLink(2, tick, isSameTick);
        _outputs[3] = val1 | val2;

        val1 = simulateLink(5, tick, isSameTick);
        val2 = simulateLink(6, tick, isSameTick);
        _outputs[4] = val1 | val2;

        val1 = simulateLink(8, tick, isSameTick);
        val2 = simulateLink(9, tick, isSameTick);
        _outputs[10] = val1 | val2;

        val1 = simulateLink(12, tick, isSameTick);
        val2 = simulateLink(13, tick, isSameTick);
        _outputs[11] = val1 | val2;
    }
}