/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IExecptions.hpp
*/

#pragma once

#include <exception>
#include <string>
#include <sstream>

inline std::string makeHere(const char *file, int line)
{
    std::ostringstream oss;
    oss << "At " << file << ":" << line;
    return oss.str();
}

#define HERE makeHere(__FILE__, __LINE__)

// #define here "At " + std::string(__FILE__) + ":" + std::to_string(__LINE__)

class IException : public std::exception
{
    public:
        IException(const std::string &message, const std::string &where)
            : _message(message), _where(where) {}

        virtual ~IException() noexcept override = default;

        const char *what() const noexcept override { return _message.c_str(); }
        const char *where() const noexcept { return _where.c_str(); }

    private:
        std::string _message;
        std::string _where;
};
