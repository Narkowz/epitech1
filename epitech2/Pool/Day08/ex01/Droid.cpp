/*
** EPITECH PROJECT, 2025
** Droid.cpp
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(const std::string &serial)
    : _id(serial), _energy(50), _attack(25), _toughness(15),
      _status(new std::string("Standing by")), BattleData(new DroidMemory)
{
    std::cout << "Droid '" << serial << "' Activated" << std::endl;
}

Droid::Droid(const Droid &other)
    : _id(other._id), _energy(other._energy), _attack(25), _toughness(15),
      _status(new std::string(*other._status)), BattleData(new DroidMemory(*other.BattleData))
{
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
    delete _status;
    delete BattleData;
}

Droid &Droid::operator=(const Droid &other)
{
    if (this != &other) {
        _id = other._id;
        _energy = other._energy;
        delete _status;
        _status = new std::string(*other._status);
        *BattleData = *other.BattleData;
    }
    return *this;
}

DroidMemory *Droid::getBattleData() const
{
    return BattleData;
}

void Droid::setBattleData(DroidMemory *battleData) {
    delete BattleData;
    BattleData = battleData;
}