/*
** EPITECH PROJECT, 2024
** nankoTekSpice
** File description:
** StringUtils.cpp
*/

#include "Utils/StringUtils.hpp"

namespace Utils
{
    std::string StringUtils::trim(const std::string &str)
    {
        size_t start = str.find_first_not_of(" \t\n\r\f\v");
        size_t end = str.find_last_not_of(" \t\n\r\f\v");
        return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
    }

    bool StringUtils::endWith(const std::string& string, const std::string& end) {
        if (string.length() < end.length()) {
            return false;
        }
        return (0 == string.compare(string.length() - end.length(), end.length(), end));
    }

    std::string StringUtils::removeCommand(const std::string& str) {
        size_t pos = str.find('#');
        return (pos == std::string::npos) ? str : str.substr(0, pos);
    }

    std::string StringUtils::putWhitespaces(std::string str) {
        for (std::size_t i = 0; i < str.length(); i++) {
            if (str[i] == '\t') {
                str[i] = ' ';
            }
        }
        return str;
    }

    std::vector<std::string> StringUtils::split(std::string const& string, char delim)
    {
        std::string str = putWhitespaces(string);
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);

        while (std::getline(tokenStream, token, delim)) {
            token = trim(token);
            if (!token.empty())
                tokens.push_back(token);
        }
        return tokens;
    }

    std::size_t StringUtils::countChar(const std::string &str, char c) {
        std::size_t count = 0;
        for (char i : str) {
            if (i == c) {
                count++;
            }
        }
        return count;
    }
}
