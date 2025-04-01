/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** XorComponent
*/

#include "NanoTekSpice/Component/XorComponent.hpp"

namespace NanoTekSpice {
    XorComponent::XorComponent() : AComponent(4, ComponentType::CT_XOR) {
        _outputs[3] = Tristate();
    }

    XorComponent::~XorComponent() {}

    void XorComponent::simulate(int tick, bool isSameTick) {
        if (isSameTick) {
            return;
        }
        Tristate val1 = simulateLink(1, tick);
        Tristate val2 = simulateLink(2, tick);
        _outputs[3] = val1 ^ val2;
    }
}