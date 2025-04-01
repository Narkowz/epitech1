/*
** EPITECH PROJECT, 2024
** nankoTekSpice
** File description:
** StringUtils.hpp
*/

#pragma once

#include <string>
#include <vector>
#include <sstream>

namespace Utils
{
    class StringUtils
    {
        public:
            static std::string trim(const std::string& str);
            static bool endWith(const std::string& str, const std::string& end);
            static std::string removeCommand(const std::string& str);
            static std::vector<std::string> split(const std::string &str, char delim);
            static std::size_t countChar(const std::string &str, char c);
        protected:
            static std::string putWhitespaces(std::string str);
    };
}

