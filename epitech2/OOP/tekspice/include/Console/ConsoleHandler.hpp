/*
** EPITECH PROJECT, 2024
** nankoTekSpice
** File description:
** ConsoleHandler.hpp
*/

#pragma once

#include <iostream>
#include <unistd.h>

#include "Console/ConsoleParser.hpp"
#include "NanoTekSpice/Circuit.hpp"

namespace Console {
    class ConsoleHandler {
    public:
        ConsoleHandler();
        int run(NanoTekSpice::Circuit &circuit);
    private:
        void ExecuteInstruction(NanoTekSpice::Circuit& circuit);
        ConsoleInstructions _instruction;
        std::pair<std::string, std::string> _instructionArgs;
        int _returnValue;
    };
}
