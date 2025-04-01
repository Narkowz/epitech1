/*
** EPITECH PROJECT, 2025
** Toy.cpp
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy() : type(BASIC_TOY), name("toy"), picture("")
{

}

Toy::Toy(ToyType type, const std::string& name, const std::string& filename)
    : type(type), name(name), picture(filename)
{

}

Toy::ToyType Toy::getType() const
{
    return type;
}

std::string Toy::getName() const
{
    return name;
}

void Toy::setName(const std::string& name)
{
    this->name = name;
}

bool Toy::setAscii(const std::string& filename)
{
    return picture.getPictureFromFile(filename);
}

std::string Toy::getAscii() const
{
    return picture.data;
}
