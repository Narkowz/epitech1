/*
** EPITECH PROJECT, 2025
** tekspice
** File description:
** MainExceptions
*/

#pragma once

#include "IExceptions.hpp"

class PathException : public IException
{
    public:
        PathException(const std::string &message, const std::string &where)
            : IException("Path Error: " + message, where) {}
};
