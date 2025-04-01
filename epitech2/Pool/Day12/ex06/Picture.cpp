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

Picture::Picture(const Picture& other) : data(other.data)
{

}

Picture::~Picture()
{

}

Picture& Picture::operator=(const Picture& other)
{
    if (this != &other)
        data = other.data;
    return *this;
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