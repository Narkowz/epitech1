/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** ComponentType
*/

#pragma once

#include <map>
#include <string>

namespace NanoTekSpice {
    enum ComponentType {
        CT_INPUT,       // Input
        CT_OUTPUT,      // Output
        CT_TRUE,        // True     Done
        CT_FALSE,       // False    Done
        CT_CLOCK,       // Clock
        CT_AND,         // And      Done
        CT_OR,          // Or       Done
        CT_XOR,         // Xor      Done
        CT_NOT,         // Not      Done
        CT_LOGGER,       // Logger
        CT_4001,        // Four NOR gates
        CT_4011,        // Four NAND gates
        CT_4030,        // Four XOR gates
        CT_4069,        // Six NOT gates
        CT_4071,        // Four OR gates
        CT_4081,        // Four AND gates
        CT_4008,        // 4-bit adder
        CT_4013,        // Dual D-type flip-flop
        CT_4017,        // Decade counter
        CT_4040,        // 12-bit binary counter
        CT_4094,        // 8-bit shift register
        CT_4512,        // 8-bit channel data selector
        CT_4514,        // 4-bit decoder
        CT_4801,        // Random access memory
        CT_2716,        // Read-only memory
        CT_UNDEFINED    // Undefined
    };
}