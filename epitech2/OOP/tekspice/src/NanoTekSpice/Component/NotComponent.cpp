/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** NotComponent
*/

#include "NanoTekSpice/Component/NotComponent.hpp"

namespace NanoTekSpice {
    NotComponent::NotComponent() : AComponent(4, ComponentType::CT_NOT) {
        _outputs[2] = Tristate();
    }

    NotComponent::~NotComponent() {}

    void NotComponent::simulate(int tick, bool isSameTick) {
        if (isSameTick) {
            return;
        }
        _outputs[2] = !simulateLink(1, tick);
    }
}