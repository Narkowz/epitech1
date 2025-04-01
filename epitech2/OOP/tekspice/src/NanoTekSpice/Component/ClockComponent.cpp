/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** ClockComponent
*/

#include "NanoTekSpice/Component/ClockComponent.hpp"

namespace NanoTekSpice {
    ClockComponent::ClockComponent() : AComponent(2, ComponentType::CT_CLOCK) {
        _outputs[1] = Tristate();
        _tempValue = Tristate();
    }
    
    ClockComponent::~ClockComponent() {}

    void ClockComponent::simulate(int, bool isSameTick) {
        if (isSameTick) {
            return;
        }
        if (_recentlytUpdated) {
            _recentlytUpdated = false;
            _outputs[1] = _tempValue;
            return;
        }
        _outputs[1] = !_outputs[1];
    }

    void ClockComponent::setValue(Tristate value, int) {
        _tempValue = value;
        _recentlytUpdated = true;
    }
}