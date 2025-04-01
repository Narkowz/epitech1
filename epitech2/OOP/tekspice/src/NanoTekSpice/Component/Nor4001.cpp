/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Nor4001
*/

#include "NanoTekSpice/Component/Nor4001.hpp"

namespace NanoTekSpice {
    Nor4001::Nor4001() : AComponent(15, ComponentType::CT_4001) {
        _outputs[3] = Tristate();
        _outputs[4] = Tristate();
        _outputs[11] = Tristate();
        _outputs[10] = Tristate();
    }

    Nor4001::~Nor4001() {}
    
    void Nor4001::simulate(int tick, bool isSameTick) {
        Tristate val1 = simulateLink(1, tick, isSameTick);
        Tristate val2 = simulateLink(2, tick, isSameTick);
        _outputs[3] = !(val1 | val2);
        
        val1 = simulateLink(5, tick, isSameTick);
        val2 = simulateLink(6, tick, isSameTick);
        _outputs[4] = !(val1 | val2);
        
        val1 = simulateLink(8, tick, isSameTick);
        val2 = simulateLink(9, tick, isSameTick);
        _outputs[10] = !(val1 | val2);
        
        val1 = simulateLink(12, tick, isSameTick);
        val2 = simulateLink(13, tick, isSameTick);
        _outputs[11] = !(val1 | val2);

        
    }
}