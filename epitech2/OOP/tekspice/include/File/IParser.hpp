/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** IParser
*/

#pragma once

#include <string>
#include <vector>

#include "Console/ConsoleInstructions.hpp"

namespace File {
    class IParser {
    public:
        virtual ~IParser() = default;
        virtual void parseFile(const std::string &filename) = 0;
    };
}
