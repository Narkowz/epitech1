/*
** EPITECH PROJECT, 2025
** Droid.cpp
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid()
    : _id(""), _energy(50), _attack(25), _toughness(15), _status(new std::string("Standing by"))
{
    std::cout << "Droid '' Activated" << std::endl;
}

Droid::Droid(const std::string& serial)
    : _id(serial), _energy(50), _attack(25), _toughness(15), _status(new std::string("Standing by"))
{
    std::cout << "Droid '" << serial << "' Activated" << std::endl;
}

Droid::Droid(const Droid& other)
    : _id(other._id), _energy(other._energy), _attack(25), _toughness(15), _status(new std::string(*other._status))
{
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
    delete _status;
}

Droid& Droid::operator=(const Droid& other)
{
    if (this != &other) {
        _id = other._id;
        _energy = other._energy;
        delete _status;
        _status = new std::string(*other._status);
    }
    return *this;
}

bool Droid::operator==(const Droid& other) const
{
    return _id == other._id && _energy == other._energy && *_status == *other._status;
}

bool Droid::operator!=(const Droid& other) const
{
    return !(*this == other);
}

Droid& Droid::operator<<(size_t& energy)
{
    size_t required = 100 - _energy;
    size_t transfer = std::min(required, energy);
    _energy += transfer;
    energy -= transfer;
    return *this;
}

const std::string& Droid::getId() const
{
    return _id;
}

size_t Droid::getEnergy() const
{
    return _energy;
}

size_t Droid::getAttack() const
{
    return _attack;
}

size_t Droid::getToughness() const
{
    return _toughness;
}

const std::string& Droid::getStatus() const
{
    return *_status;
}

void Droid::setId(const std::string& id)
{
    _id = id;
}

void Droid::setEnergy(size_t energy)
{
    if (energy > 100)
        _energy = 100;
    else
        _energy = energy;
}

void Droid::setStatus(std::string* status)
{
    delete _status;
    _status = status;
}

std::ostream& operator<<(std::ostream& out, const Droid& droid)
{
    out << "Droid '" << droid._id << "', " << *droid._status << ", " << droid._energy;
    return out;
}
