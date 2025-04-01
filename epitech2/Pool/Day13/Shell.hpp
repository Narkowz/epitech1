/*
** EPITECH PROJECT, 2025
** Shell.hpp
** File description:
** Shell
*/

#ifndef SHELL_HPP_
#define SHELL_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

class Shell {
public:
    class Error : public std::exception {
    private:
        std::string message;
    public:
        Error(const std::string& msg);
        const char* what() const noexcept override;
    };

    class Warning : public std::exception {
    private:
        std::string message;
    public:
        Warning(const std::string& msg);
        const char* what() const noexcept override;
    };

private:
    std::istream& stream;
    std::string currentLine;
    std::stringstream lineStream;

public:
    Shell(std::istream& input);
    void next();
    template <typename T>
    T extract();
};

#endif /* !SHELL_HPP_ */
