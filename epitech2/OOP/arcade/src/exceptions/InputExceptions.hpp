/*
** EPITECH PROJECT, 2025
** tekspice
** File description:
** MainExceptions
*/

#pragma once

#include "IExceptions.hpp"

class InputException : public IException
{
    public:
        InputException(const std::string &message, const std::string &where)
            : IException("Input Error: " + message, where) {}
};
