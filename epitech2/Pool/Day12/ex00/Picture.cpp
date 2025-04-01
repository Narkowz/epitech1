/*
** EPITECH PROJECT, 2025
** Picture.cpp
** File description:
** Picture
*/

#include "Picture.hpp"
#include <fstream>
#include <sstream>

Picture::Picture(const std::string& file)
{
    if (!file.empty())
        getPictureFromFile(file);
    else
        data = "";
}

bool Picture::getPictureFromFile(const std::string& file)
{
    std::ifstream inputFile(file);
    if (!inputFile) {
        data = "ERROR";
        return false;
    }
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    data = buffer.str();
    return true;
}
