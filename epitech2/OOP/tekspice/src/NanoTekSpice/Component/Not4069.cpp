/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Not4069
*/

#include "NanoTekSpice/Component/Not4069.hpp"

namespace NanoTekSpice {
    Not4069::Not4069() : AComponent(15, ComponentType::CT_4069) {
        _outputs[2] = Tristate();
        _outputs[4] = Tristate();
        _outputs[6] = Tristate();
        _outputs[8] = Tristate();
        _outputs[10] = Tristate();
        _outputs[12] = Tristate();
    }

    Not4069::~Not4069() {}

    void Not4069::simulate(int tick, bool isSameTick) {
        Tristate val1 = simulateLink(1, tick, isSameTick);
        _outputs[2] = !val1;

        val1 = simulateLink(3, tick, isSameTick);
        _outputs[4] = !val1;

        val1 = simulateLink(5, tick, isSameTick);
        _outputs[6] = !val1;

        val1 = simulateLink(9, tick, isSameTick);
        _outputs[8] = !val1;

        val1 = simulateLink(11, tick, isSameTick);
        _outputs[10] = !val1;

        val1 = simulateLink(13, tick, isSameTick);
        _outputs[12] = !val1;
    }
}