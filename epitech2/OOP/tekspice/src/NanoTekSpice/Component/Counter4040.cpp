/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Counter4040
*/

#include "NanoTekSpice/Component/Counter4040.hpp"

namespace NanoTekSpice {
    Counter4040::Counter4040() : AComponent(17, ComponentType::CT_4040) {
        _outputs[1] = Tristate();
        _outputs[2] = Tristate();
        _outputs[3] = Tristate();
        _outputs[4] = Tristate();
        _outputs[5] = Tristate();
        _outputs[6] = Tristate();
        _outputs[7] = Tristate();
        _outputs[9] = Tristate();
        _outputs[12] = Tristate();
        _outputs[13] = Tristate();
        _outputs[14] = Tristate();
        _outputs[15] = Tristate();
        _value = 0;
        _lastClockUp = false;
    }

    Counter4040::~Counter4040() {}

    void Counter4040::simulate(int tick, bool isSameTick) {
        if (isSameTick) {
            return;
        }
        Tristate clock = simulateLink(10, tick);
        Tristate reset = simulateLink(11, tick);
    
        if (reset == Tristate(1)) {
            _value = 0;
        } else if ((clock == Tristate(0) && _lastClockUp)) {
            _value = (_value + 1) % 4096;
        }

        _lastClockUp = clock == Tristate(1);

        int outputPins[12] = { 9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1 };
        for (int i = 0; i < 12; i++) {
            _outputs[outputPins[i]] = Tristate((_value >> i) & 1);
        }
    }
}