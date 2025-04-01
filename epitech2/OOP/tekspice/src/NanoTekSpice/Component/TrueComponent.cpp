/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** TrueComponent
*/

#include "NanoTekSpice/Component/TrueComponent.hpp"

namespace NanoTekSpice {
    TrueComponent::TrueComponent() : AComponent(2, ComponentType::CT_TRUE) {
        _outputs[1] = Tristate(1);
    }

    TrueComponent::~TrueComponent() {}

    void TrueComponent::simulate(int, bool) {}
}