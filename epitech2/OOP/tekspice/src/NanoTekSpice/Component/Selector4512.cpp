/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Selector4512
*/

#include "NanoTekSpice/Component/Selector4512.hpp"

namespace NanoTekSpice {
    Selector4512::Selector4512() : AComponent(16, ComponentType::CT_4512) {
        _outputs[14] = Tristate();
    }

    Selector4512::~Selector4512() {}

    void Selector4512::simulate(int tick, bool isSameTick) {
        if (isSameTick) {
            return;
        }

        Tristate a = simulateLink(11, tick);
        Tristate b = simulateLink(12, tick);
        Tristate c = simulateLink(13, tick);
        Tristate inhibit = simulateLink(10, tick);
        Tristate enable = simulateLink(15, tick);

        int listPin [] = {1, 2, 3, 4, 5, 6, 7, 9};
        Tristate listValue[8];
        for (int i = 0; i < 8; i++) {
            listValue[i] = simulateLink(listPin[i], tick);
        }
        if (enable != Tristate(0)) {
            _outputs[14] = Tristate();
            return;
        }
        if (a == Tristate() || b == Tristate() || c == Tristate()) {
            _outputs[14] = Tristate();
            return;
        }
        if (inhibit == Tristate(1)) {
            _outputs[14] = Tristate();
            return;
        }
        int pinIndex = 0;
        pinIndex += a == Tristate(1) ? 1 : 0;
        pinIndex += b == Tristate(1) ? 2 : 0;
        pinIndex += c == Tristate(1) ? 4 : 0;

        _outputs[14] = listValue[pinIndex];
    }
}