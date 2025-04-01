/*
** EPITECH PROJECT, 2025
** Knight.cpp
** File description:
** Knight
*/

#include "Knight.hpp"
#include <iostream>

Knight::Knight(const std::string& name, int power) : Peasant(name, power)
{
    std::cout << name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    checkCombatStatus();
    checkPowerStatus();
    if (getHp() == 0 || getPower() < 10)
        return 0;
    power -= 10;
    std::cout << name << " strikes with his sword." << std::endl;
    return 20;
}

int Knight::special()
{
    checkCombatStatus();
    checkPowerStatus();
    if (getHp() == 0 || getPower() < 30)
        return 0;
    power -= 30;
    std::cout << name << " impales his enemy." << std::endl;
    return 50;
}

void Knight::rest()
{
    checkCombatStatus();
    power += 50;
    if (power > 100)
        power = 100;
    std::cout << name << " eats." << std::endl;
}