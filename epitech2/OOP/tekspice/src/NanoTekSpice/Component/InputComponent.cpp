/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** InputComponent
*/

#include "NanoTekSpice/Component/InputComponent.hpp"

namespace NanoTekSpice {
    InputComponent::InputComponent() : AComponent(2, ComponentType::CT_INPUT) {
        _outputs[1] = Tristate();
        _tempValue = Tristate();
        _recentlytUpdated = false;
    }
    
    InputComponent::~InputComponent() {}

    void InputComponent::simulate(int, bool isSameTick) {
        if (isSameTick) {
            return;
        }
        if (_recentlytUpdated) {
            _recentlytUpdated = false;
            _outputs[1] = _tempValue;
            return;
        }
    }

    void InputComponent::setValue(Tristate value, int) {
        _tempValue = value;
        _recentlytUpdated = true;
    }
}