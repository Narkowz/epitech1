/*
** EPITECH PROJECT, 2025
** Buzz.cpp
** File description:
** Buzz
*/
#include "Buzz.hpp"

Buzz::Buzz(const std::string& name, const std::string& filename)
    : Toy(Toy::BUZZ, name, filename)
{

}

bool Buzz::speak(const std::string& statement)
{
    std::cout << "BUZZ: " << getName() << " \"" << statement << "\"" << std::endl;
    return true;
}

bool Buzz::speak_es(const std::string& statement)
{
    std::cout << "BUZZ: " << getName() << " senorita \"" << statement << "\" senorita" << std::endl;
    return true;
}