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
    : _id(other._id), _energy(50), _attack(25), _toughness(15),
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
        _energy = 50;
        delete _status;
        _status = new std::string(*other._status);
        *BattleData = *other.BattleData;
    }
    return *this;
}

bool Droid::operator()(const std::string *task, size_t expRequired)
{
    if (_energy < 10) {
        _energy = 0;
        *_status = "Battery Low";
        return false;
    }
    _energy -= 10;

    if (BattleData->getExp() >= expRequired) {
        BattleData->setExp(BattleData->getExp() + expRequired / 2);
        *_status = *task + " - Completed!";
        return true;
    } else {
        BattleData->setExp(BattleData->getExp() + expRequired);
        *_status = *task + " - Failed!";
        return false;
    }
}

bool Droid::operator==(const Droid &other) const
{
    return *_status == *other._status;
}

bool Droid::operator!=(const Droid &other) const
{
    return !(*this == other);
}

const std::string &Droid::getId() const
{
    return _id;
}

void Droid::setId(const std::string &id)
{
    _id = id;
}

size_t Droid::getEnergy() const
{
    return _energy;
}
void Droid::setEnergy(size_t energy)
{
    _energy = (energy > 100 ? 100 : energy);
}

const std::string &Droid::getStatus() const
{
    return *_status;
}
void Droid::setStatus(std::string *status)
{
    delete _status;
    _status = status;
}

DroidMemory *Droid::getBattleData() const { return BattleData; }
void Droid::setBattleData(DroidMemory *battleData)
{
    delete BattleData;
    BattleData = battleData;
}

std::ostream &operator<<(std::ostream &out, const Droid &droid)
{
    out << "Droid '" << droid._id << "', " << *droid._status << ", " << droid._energy;
    return out;
}
