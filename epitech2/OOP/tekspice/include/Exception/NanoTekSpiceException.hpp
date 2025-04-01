/*
** EPITECH PROJECT, 2024
** nankoTekSpice
** File description:
** NanoException.hpp
*/

#pragma once
#include <exception>
#include <string>
#include <iostream>

namespace Exception {
    /**
     * @brief Base NanoTekkSpice excpetion.
     * 
     */
    class NanoTekSpiceException : public std::exception {
    public:
        virtual const char* what() const noexcept override {
            return "NanoTekSpice Error";
        }
    };
}
