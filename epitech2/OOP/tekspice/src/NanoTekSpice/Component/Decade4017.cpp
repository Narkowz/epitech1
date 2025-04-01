/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Decade4017
*/

#include "NanoTekSpice/Component/Decade4017.hpp"

namespace NanoTekSpice {
    Decade4017::Decade4017() : AComponent(17, ComponentType::CT_4017) {
        _outputs[1] = Tristate();
        _outputs[2] = Tristate();
        _outputs[3] = Tristate();
        _outputs[4] = Tristate();
        _outputs[5] = Tristate();
        _outputs[6] = Tristate();
        _outputs[7] = Tristate();
        _outputs[9] = Tristate();
        _outputs[10] = Tristate();
        _outputs[11] = Tristate();
        _outputs[12] = Tristate();
        _value = 0;
        _carryOutCounter = -1;
    }

    Decade4017::~Decade4017() {}

    void Decade4017::simulate(int tick, bool isSameTick) {
        if (isSameTick) {
            return;
        }

        Tristate inhib = simulateLink(13, tick);
        Tristate clock = simulateLink(14, tick);
        Tristate reset = simulateLink(15, tick);

        if (reset == Tristate(1)) {
            _value = 0;
            _lastClockUp = false;
            _carryOutCounter = 0;
        } else {
            if (clock == Tristate(1) && inhib != Tristate(1) && _lastClockUp == false) {
                _value++;
                if (_value == 10) {
                    _value = 0;
                    _carryOutCounter = 0;
                }
            }
            _lastClockUp = clock == Tristate(1) && inhib != Tristate(1);
        }
        int outputPins[10] = { 3, 2, 4, 7, 10, 1, 5, 6, 9, 11 };
        for (int i = 0; i < 10; i++) {
            _outputs[outputPins[i]] = Tristate(i == _value);
        }
        _outputs[12] = Tristate(_carryOutCounter != -1);
        if (_carryOutCounter != -1) {
            _carryOutCounter++;
            if (_carryOutCounter >= 10) {
                _carryOutCounter = -1;
            } else {
                _outputs[12] = Tristate(1);
            }
        }
    }
}