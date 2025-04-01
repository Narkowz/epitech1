/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** FlipFlop4013
*/

#include "NanoTekSpice/Component/FlipFlop4013.hpp"

namespace NanoTekSpice {
    FlipFlop4013::FlipFlop4013() : AComponent(15, ComponentType::CT_4013) {
        _outputs[1] = Tristate();
        _outputs[2] = Tristate();
        _outputs[12] = Tristate();
        _outputs[13] = Tristate();
        _lastClockUp = false;
        _lastClockUp2 = false;
    }

    FlipFlop4013::~FlipFlop4013() {}

    void FlipFlop4013::simulate(int tick, bool isSameTick) {
        if (isSameTick) {
            return;
        }
        
        Tristate clock = simulateLink(3, tick);
        Tristate reset = simulateLink(4, tick);
        Tristate data = simulateLink(5, tick);
        Tristate set = simulateLink(6, tick);
        
        if (reset == Tristate(1) && set == Tristate(1)) {
            _outputs[1] = Tristate(1);
            _outputs[2] = Tristate(1);
        } else if (reset == Tristate(1)) {
            _outputs[1] = Tristate(0);
            _outputs[2] = Tristate(1);
        } else if (set == Tristate(1)) {
            _outputs[1] = Tristate(1);
            _outputs[2] = Tristate(0);
        } else if (clock == Tristate(1) && !_lastClockUp) {
            _outputs[1] = data;
            _outputs[2] = !data;
        }
        _lastClockUp = clock == Tristate(1);

        clock = simulateLink(11, tick);
        reset = simulateLink(10, tick);
        data = simulateLink(9, tick);
        set = simulateLink(8, tick);
        if (reset == Tristate(1) && set == Tristate(1)) {
            _outputs[13] = Tristate(1);
            _outputs[12] = Tristate(1);
        } else if (reset == Tristate(1)) {
            _outputs[13] = Tristate(0);
            _outputs[12] = Tristate(1);
        } else if (set == Tristate(1)) {
            _outputs[13] = Tristate(1);
            _outputs[12] = Tristate(0);
        } else if (clock == Tristate(1) && !_lastClockUp2) {
            _outputs[13] = data;
            _outputs[12] = !data;
        }
        _lastClockUp2 = clock == Tristate(1);
    }
}