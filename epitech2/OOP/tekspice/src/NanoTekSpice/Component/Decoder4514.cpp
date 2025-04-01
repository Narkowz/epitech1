/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Decoder4514
*/

#include "NanoTekSpice/Component/Decoder4514.hpp"

namespace NanoTekSpice {
    Decoder4514::Decoder4514() : AComponent(24, ComponentType::CT_4514) {
        _outputs[4] = Tristate();
        _outputs[5] = Tristate();
        _outputs[6] = Tristate();
        _outputs[7] = Tristate();
        _outputs[8] = Tristate();
        _outputs[9] = Tristate();
        _outputs[10] = Tristate();
        _outputs[11] = Tristate();
        _outputs[13] = Tristate();
        _outputs[14] = Tristate();
        _outputs[15] = Tristate();
        _outputs[16] = Tristate();
        _outputs[17] = Tristate();
        _outputs[18] = Tristate();
        _outputs[19] = Tristate();
        _outputs[20] = Tristate();
        _lastLatchedValue = 0;
        _lastStrobeDown = false;
    }

    Decoder4514::~Decoder4514() {}

    void Decoder4514::simulate(int tick, bool isSameTick) {
        if (isSameTick) {
            return;
        }

        Tristate inhib = simulateLink(23, tick);
        Tristate strobe = simulateLink(1, tick);
        Tristate a = simulateLink(2, tick);
        Tristate b = simulateLink(3, tick);
        Tristate c = simulateLink(21, tick);
        Tristate d = simulateLink(22, tick);
        int outputPins[] = { 11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15 };

        if (inhib == Tristate(1)) {
            for (int i = 0; i < 16; i++)
                _outputs[outputPins[i]] = Tristate(0);
            return;
        }

        if (a == Tristate() || b == Tristate() || c == Tristate() || d == Tristate()) {
            for (int i = 0; i < 16; i++)
                _outputs[outputPins[i]] = Tristate();
            return;
        }

        if (strobe == Tristate(0) && !_lastStrobeDown) {
            _lastLatchedValue  = a == Tristate(1) ? 1 : 0;
            _lastLatchedValue += b == Tristate(1) ? 2 : 0;
            _lastLatchedValue += c == Tristate(1) ? 4 : 0;
            _lastLatchedValue += d == Tristate(1) ? 8 : 0;
        }
        _lastStrobeDown = strobe == Tristate(0);

        for (int i = 0; i < 16; i++) {
            if (inhib == Tristate(1) || strobe == Tristate(1))
                _outputs[outputPins[i]] = Tristate(0);
            else
                _outputs[outputPins[i]] = Tristate(_lastLatchedValue == i ? 1 : 0);
        }
    }
}