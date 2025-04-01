/*
** EPITECH PROJECT, 2025
** Peasant.cpp
** File description:
** Peasant
*/

#include "Peasant.hpp"
#include <iostream>

Peasant::Peasant(const std::string& name, int power) : name(name), power(power), hp(100)
{
    if (this->power > 100)
        this->power = 100;
    if (this->power < 0)
        this->power = 0;
    std::cout << name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << name << " is back to his crops." << std::endl;
}

const std::string& Peasant::getName() const
{
    return name;
}

int Peasant::getPower() const
{
    return power;
}

int Peasant::getHp() const
{
    return hp == 0 ? 0 : hp;
}

int Peasant::attack()
{
    checkCombatStatus();
    checkPowerStatus();
    if (hp == 0 || power < 10)
        return 0;
    power -= 10;
    std::cout << name << " tosses a stone." << std::endl;
    return 5;
}

int Peasant::special()
{
    checkCombatStatus();
    std::cout << name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    checkCombatStatus();
    power += 30;
    if (power > 100)
        power = 100;
    std::cout << name << " takes a nap." << std::endl;
}

void Peasant::damage(int damage)
{
    hp -= damage;
    if (hp <= 0) {
        std::cout << name << " is out of combat." << std::endl;
        return;
    }
    std::cout << name << " takes " << damage << " damage." << std::endl;

}

void Peasant::checkCombatStatus()
{
    if (hp == 0)
        std::cout << name << " is out of combat." << std::endl;
}

void Peasant::checkPowerStatus()
{
    if (power == 0)
        std::cout << name << " is out of power." << std::endl;
}
