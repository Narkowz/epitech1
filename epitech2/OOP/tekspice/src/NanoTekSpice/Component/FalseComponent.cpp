/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** FalseComponent
*/

#include "NanoTekSpice/Component/FalseComponent.hpp"

namespace NanoTekSpice {
    FalseComponent::FalseComponent() : AComponent(2, ComponentType::CT_FALSE)
    {
        _outputs[1] = Tristate(0);
    }

    FalseComponent::~FalseComponent() {}

    void FalseComponent::simulate(int, bool) {}
}