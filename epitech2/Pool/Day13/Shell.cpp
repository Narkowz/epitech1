/*
** EPITECH PROJECT, 2025
** Shell.cpp
** File description:
** Shell
*/

#include "Shell.hpp"

Shell::Error::Error(const std::string& msg) : message(msg)
{

}

const char* Shell::Error::what() const noexcept
{
    return message.c_str();
}

Shell::Warning::Warning(const std::string& msg) : message(msg)
{

}

const char* Shell::Warning::what() const noexcept
{
    return message.c_str();
}

Shell::Shell(std::istream& input) : stream(input)
{

}

void Shell::next() {
    if (!std::getline(stream, currentLine)) {
        if (stream.eof())
            throw Error("End of input");
        else
            throw Error("Input failed");
    }
    lineStream.clear();
    lineStream.str(currentLine);
}

template <typename T>
T Shell::extract()
{
    T value;
    if (!(lineStream >> value))
        throw Warning("Invalid conversion");
    return value;
}

template int Shell::extract<int>();
template double Shell::extract<double>();
template std::string Shell::extract<std::string>();
