/*
** EPITECH PROJECT, 2024
** nankoTekSpice
** File description:
** ConsoleParser.cpp
*/

#include <sstream>
#include <unordered_map>

#include "Console/ConsoleParser.hpp"
#include "Utils/StringUtils.hpp"

namespace Console
{
    Console::ConsoleInstructions ConsoleParser::getInstruction(const std::string &command) {
        static const std::unordered_map<std::string, Console::ConsoleInstructions> commandMap = {
            {"exit", Console::ConsoleInstructions::CI_EXIT},
            {"simulate", Console::ConsoleInstructions::CI_SIMULATE},
            {"display", Console::ConsoleInstructions::CI_DISPLAY},
            {"loop", Console::ConsoleInstructions::CI_LOOP},
            {"", Console::ConsoleInstructions::CI_EMPTY}
        };

        auto it = commandMap.find(command);
        return (it != commandMap.end()) ? it->second : Console::ConsoleInstructions::CI_UNDEFINED;
    }

    std::pair<std::string, std::string> ConsoleParser::parseCommand(const std::string &command, Console::ConsoleInstructions &instruction) {
        std::string trimmedCommand = Utils::StringUtils::trim(command);

        instruction = getInstruction(trimmedCommand);

        if (instruction != Console::ConsoleInstructions::CI_UNDEFINED) {
            return {"", ""};
        }
        std::stringstream stream(trimmedCommand);
        std::string token;

        size_t equalPos = trimmedCommand.find('=');
        if (equalPos != std::string::npos) {
            std::string key = Utils::StringUtils::trim(trimmedCommand.substr(0, equalPos));
            std::string value = Utils::StringUtils::trim(trimmedCommand.substr(equalPos + 1));

            instruction = ConsoleInstructions::CI_UPDATE;
            return {key, value};
        }
        return {"", ""};
    }
}