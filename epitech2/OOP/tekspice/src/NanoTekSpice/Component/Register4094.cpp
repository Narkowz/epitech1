/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Register4094
*/

#include "NanoTekSpice/Component/Register4094.hpp"

namespace NanoTekSpice {
    Register4094::Register4094() : AComponent(16, ComponentType::CT_4094) {
        _outputs[4] = Tristate();
        _outputs[5] = Tristate();
        _outputs[6] = Tristate();
        _outputs[7] = Tristate();
        _outputs[11] = Tristate();
        _outputs[12] = Tristate();
        _outputs[13] = Tristate();
        _outputs[14] = Tristate();
        _outputs[9] = Tristate();
        _outputs[10] = Tristate();
        _savedValue = 0;
        _latchedValue = 0;
        _lastClockUp = false;
    }

    Register4094::~Register4094() {}

    void Register4094::simulate(int tick, bool isSameTick) {
        if (isSameTick) {
            return;
        }

        Tristate strobe = simulateLink(1, tick);
        Tristate data = simulateLink(2, tick);
        Tristate clock = simulateLink(3, tick);
        Tristate enable = simulateLink(15, tick);

        if (clock == Tristate(1) && !_lastClockUp) {
            _latchedValue = ((_latchedValue << 1) & 0xFF) | (data == Tristate(1) ? 1 : 0);
        }
        
        if (strobe == Tristate(1)) {
            _savedValue = _latchedValue;
        }

        if (enable == Tristate(1)) {
            int tempSavedValue = _savedValue;
            int outPins[] = { 4, 5, 6, 7, 14, 13, 12, 11};
            for (int i = 0; i < 8; i++) {
                _outputs[outPins[i]] = Tristate(tempSavedValue & 1);
                tempSavedValue = tempSavedValue >> 1;
            }
        }

        _outputs[9] = Tristate((_latchedValue >> 7) & 1);
        _outputs[10] = Tristate((_latchedValue >> 6) & 1);
        _lastClockUp = clock == Tristate(1);
    }
}