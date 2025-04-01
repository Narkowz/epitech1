/*
** EPITECH PROJECT, 2024
** nankoTekSpice
** File description:
** NoChipsetsError.hpp
*/

#pragma once

#include "NanoTekSpiceException.hpp"


#define THROW_FILE_EXCEPTION(msg) throw Exception::FileParsingException(msg, std::string(__FILE__) + ":" + std::to_string(__LINE__))

namespace Exception {
    /**
     * @brief Exception thrown if the file is invalid
     * 
     */
    class FileParsingException : public NanoTekSpiceException {
    private:
        const std::string _message;
        const std::string _location;
    public:
        FileParsingException(const std::string& message, const std::string& where) : _message(message), _location(where) {}
        const char* what() const noexcept override {
            return _message.c_str();
        }
        const char* where() const noexcept {
            return _location.c_str();
        }
    };
}