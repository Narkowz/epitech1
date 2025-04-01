/*
** EPITECH PROJECT, 2025
** Enchanter.cpp
** File description:
** Enchanter
*/

#include "Enchanter.hpp"

#include "Enchanter.hpp"
#include <iostream>

Enchanter::Enchanter(const std::string& name, int power) : Peasant(name, power)
{
    std::cout << name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    checkCombatStatus();
    std::cout << name << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    checkCombatStatus();
    checkPowerStatus();
    if (getHp() == 0 || getPower() < 50)
        return 0;
    power -= 50;
    std::cout << name << " casts a fireball." << std::endl;
    return 99;
}

void Enchanter::rest()
{
    checkCombatStatus();
    power += 100;
    if (power > 100)
        power = 100;
    std::cout << name << " meditates." << std::endl;
}
