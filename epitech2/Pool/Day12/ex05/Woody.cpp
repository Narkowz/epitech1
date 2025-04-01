/*
** EPITECH PROJECT, 2025
** Woody.cpp
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string& name, const std::string& filename)
    : Toy(Toy::WOODY, name, filename)
{
    
}

void Woody::speak(const std::string& statement)
{
    std::cout << "WOODY: " << getName() << " \"" << statement << "\"" << std::endl;
}

bool Woody::speak_es(const std::string& statement)
{
    return Toy::speak_es(statement);
}
