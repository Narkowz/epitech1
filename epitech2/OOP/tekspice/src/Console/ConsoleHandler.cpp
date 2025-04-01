/*
** EPITECH PROJECT, 2024
** nankoTekSpice
** File description:
** ConsoleHandler.cpp
*/


#include "Console/ConsoleHandler.hpp"
#include "Console/ConsoleParser.hpp"

#include "Exception/RuntimeException.hpp"

#include <iostream>

namespace Console {
    ConsoleHandler::ConsoleHandler() {
        _instruction = ConsoleInstructions::CI_EMPTY;
        _instructionArgs = std::make_pair("", "");
        _returnValue = 0;
    }

    int ConsoleHandler::run(NanoTekSpice::Circuit &circuit) {
        std::string command;

        while (true) {
            std::cout << "> ";
            if (!std::getline(std::cin, command)) {
                break;
            }
            try {
                _instruction = ConsoleInstructions::CI_UNDEFINED;
                _instructionArgs = std::make_pair("", "");
                _instructionArgs = ConsoleParser::parseCommand(command, _instruction);
                if (_instruction ==  ConsoleInstructions::CI_EXIT)
                    return _returnValue;
                ExecuteInstruction(circuit);
                _returnValue = 0;

            } catch (Exception::RuntimeException &e) {
                std::cerr << "RuntimeException:: " << e.what() << " at " << e.where() << std::endl;
                _returnValue = 84;
            }
        }
        return _returnValue;
    }

    void ConsoleHandler::ExecuteInstruction(NanoTekSpice::Circuit &circuit) {
        
        switch (_instruction) {
            case ConsoleInstructions::CI_DISPLAY:
                circuit.display();
                break;
            case ConsoleInstructions::CI_SIMULATE:
                circuit.simulate();
                break;
            case ConsoleInstructions::CI_UPDATE:
                circuit.update(_instructionArgs.first, _instructionArgs.second);
                break;
            case ConsoleInstructions::CI_LOOP:
                circuit.loop();
                break;
            case ConsoleInstructions::CI_EMPTY:
                break;
            default:
                THROW_RUNTIME_EXCEPTION("Invalid command");
                break;
        }
    }
}
