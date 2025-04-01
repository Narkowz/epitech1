/*
** EPITECH PROJECT, 2025
** Command.cpp
** File description:
** Command
*/

#include "Command.hpp"

void Command::registerCommand(const std::string& name, const std::function<void()>& function)
{
    if (commands.find(name) != commands.end())
        throw Error("Already registered command");
    commands[name] = function;
}

void Command::executeCommand(const std::string& name)
{
    auto it = commands.find(name);
    if (it == commands.end())
        throw Error("Unknow command");
    it->second();
}
