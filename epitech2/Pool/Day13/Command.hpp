/*
** EPITECH PROJECT, 2025
** Command.hpp
** File description:
** Command
*/

#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include <map>
#include <string>
#include <functional>
#include <stdexcept>
#include <iostream>

class Command {
public:
    class Error : public std::exception {
    private:
        std::string message;
    public:
        Error(const std::string& msg) : message(msg)
        {

        }

        const char* what() const noexcept override
        {
            return message.c_str();
        }
    };

private:
    std::map<std::string, std::function<void()>> commands;

public:
    void registerCommand(const std::string& name, const std::function<void()>& function);

    void executeCommand(const std::string& name);
};
#endif /* !COMMAND_HPP_ */
