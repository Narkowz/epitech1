/*
** EPITECH PROJECT, 2024
** nankoTekSpice
** File description:
** ConsoleParser.hpp
*/

#pragma once

#include <string>
#include <utility>

#include "Console/ConsoleInstructions.hpp"

namespace Console {
    class ConsoleParser{
    public:
        static std::pair<std::string, std::string> parseCommand(const std::string &command, Console::ConsoleInstructions &instruction);
    private:
        static Console::ConsoleInstructions getInstruction(const std::string &command);
    };
}
