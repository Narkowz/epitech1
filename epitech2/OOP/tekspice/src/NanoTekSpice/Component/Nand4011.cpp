/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Nand4011
*/

#include "NanoTekSpice/Component/Nand4011.hpp"

namespace NanoTekSpice {
    Nand4011::Nand4011() : AComponent(15, ComponentType::CT_4011) {
        _outputs[3] = Tristate();
        _outputs[4] = Tristate();
        _outputs[11] = Tristate();
        _outputs[10] = Tristate();
    }

    Nand4011::~Nand4011() {}

    void Nand4011::simulate(int tick, bool isSameTick) {
        Tristate val1 = simulateLink(1, tick, isSameTick);
        Tristate val2 = simulateLink(2, tick, isSameTick);
        _outputs[3] = !(val1 & val2);

        val1 = simulateLink(5, tick, isSameTick);
        val2 = simulateLink(6, tick, isSameTick);
        _outputs[4] = !(val1 & val2);

        val1 = simulateLink(8, tick, isSameTick);
        val2 = simulateLink(9, tick, isSameTick);
        _outputs[10] = !(val1 & val2);

        val1 = simulateLink(12, tick, isSameTick);
        val2 = simulateLink(13, tick, isSameTick);
        _outputs[11] = !(val1 & val2);
    }
}