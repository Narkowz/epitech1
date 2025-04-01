/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** And4081
*/

#include "NanoTekSpice/Component/And4081.hpp"

namespace NanoTekSpice {
    And4081::And4081() : AComponent(15, ComponentType::CT_4081) {
        _outputs[3] = Tristate();
        _outputs[4] = Tristate();
        _outputs[11] = Tristate();
        _outputs[10] = Tristate();
    }

    And4081::~And4081() {}

    void And4081::simulate(int tick, bool isSameTick) {
        Tristate val1 = simulateLink(1, tick, isSameTick);
        Tristate val2 = simulateLink(2, tick, isSameTick);
        _outputs[3] = val1 & val2;

        val1 = simulateLink(5, tick, isSameTick);
        val2 = simulateLink(6, tick, isSameTick);
        _outputs[4] = val1 & val2;

        val1 = simulateLink(8, tick, isSameTick);
        val2 = simulateLink(9, tick, isSameTick);
        _outputs[10] = val1 & val2;

        val1 = simulateLink(12, tick, isSameTick);
        val2 = simulateLink(13, tick, isSameTick);
        _outputs[11] = val1 & val2;
    }
}