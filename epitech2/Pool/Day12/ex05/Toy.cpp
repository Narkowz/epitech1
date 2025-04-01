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

Toy::Toy(const Toy& other)
    : type(other.type), name(other.name), picture(other.picture)
{

}

Toy::~Toy()
{

}

Toy& Toy::operator=(const Toy& other)
{
    if (this != &other) {
        type = other.type;
        name = other.name;
        picture = other.picture;
    }
    return *this;
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
    if (!picture.getPictureFromFile(filename)) {
        lastError.type = Error::PICTURE;
        lastError.function = "setAscii";
        return false;
    }
    return true;
}

std::string Toy::getAscii() const
{
    return picture.data;
}

void Toy::speak(const std::string& statement)
{
    std::cout << name << " \"" << statement << "\"" << std::endl;
}

bool Toy::speak_es(const std::string& statement)
{
    (void)statement;
    lastError.type = Error::SPEAK;
    lastError.function = "speak_es";
    return false;
}

Toy::Error Toy::getLastError() const
{
    return lastError;
}

std::ostream& operator<<(std::ostream& os, const Toy& toy)
{
    os << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return os;
}

Toy& Toy::operator<<(const std::string& str)
{
    picture.data = str;
    return *this;
}
