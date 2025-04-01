/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** AndComponent
*/

#include "NanoTekSpice/Component/AndComponent.hpp"

namespace NanoTekSpice {
    AndComponent::AndComponent() : AComponent(4, ComponentType::CT_AND) {
        _outputs[3] = Tristate();
    }

    AndComponent::~AndComponent() {}

    void AndComponent::simulate(int tick, bool isSameTick) {
        Tristate val1 = simulateLink(1, tick, isSameTick);
        Tristate val2 = simulateLink(2, tick, isSameTick);

        _outputs[3] = (val1 & val2);
    }
}