/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Adder4008
*/

#include "NanoTekSpice/Component/Adder4008.hpp"

namespace NanoTekSpice {
    Adder4008::Adder4008() : AComponent(17, ComponentType::CT_4008) {
        _outputs[10] = Tristate();
        _outputs[11] = Tristate();
        _outputs[12] = Tristate();
        _outputs[13] = Tristate();
        _outputs[14] = Tristate();
    }

    Adder4008::~Adder4008() {}

    void Adder4008::simulate(int tick, bool isSameTick) {
        Tristate carry = simulateLink(9, tick, isSameTick);

        int pins[8] = { 7, 6, 5, 4, 3, 2, 1, 15 };

        for (int i = 0; i < 4; i++) {
            Tristate a = simulateLink(pins[i * 2], tick, isSameTick);
            Tristate b = simulateLink(pins[i * 2 + 1], tick, isSameTick);
            
            _outputs[10 + i] = addWithCarry(a, b, carry);
            carry = getCarryOut(a, b, carry);
        }
        _outputs[14] = carry;
    }

    Tristate Adder4008::addWithCarry(Tristate a, Tristate b, Tristate carryIn) {
        Tristate sum = a ^ b ^ carryIn;
        return sum;
    }

    Tristate Adder4008::getCarryOut(Tristate a, Tristate b, Tristate carryIn) {
        Tristate carryOut = (a & b) | (a & carryIn) | (b & carryIn);
        return carryOut;
    }

}