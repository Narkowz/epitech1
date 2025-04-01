/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** OrComponent
*/

#include "NanoTekSpice/Component/OrComponent.hpp"

namespace NanoTekSpice {
    OrComponent::OrComponent() : AComponent(4, ComponentType::CT_OR) {
        _outputs[3] = Tristate();
    }

    OrComponent::~OrComponent() {}

    void OrComponent::simulate(int tick, bool isSameTick) {
        Tristate val1 = simulateLink(1, tick, isSameTick);
        Tristate val2 = simulateLink(2, tick, isSameTick);
        _outputs[3] = val1 | val2;
    }
}