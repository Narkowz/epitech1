/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** OutputComponent
*/

#include "NanoTekSpice/Component/OutputComponent.hpp"

namespace NanoTekSpice {
    OutputComponent::OutputComponent() : AComponent(2, ComponentType::CT_OUTPUT) {
        _outputs[2] = Tristate();
    }

    OutputComponent::~OutputComponent() {}

    void OutputComponent::simulate(int tick, bool isSameTick) {
        if (isSameTick) {
            return;
        }
        _outputs[2] = simulateLink(1, tick);
    }
}