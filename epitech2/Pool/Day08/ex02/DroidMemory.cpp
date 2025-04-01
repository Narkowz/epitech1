/*
** EPITECH PROJECT, 2025
** DroidMemory.cpp
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
    : _fingerprint(random()), _exp(0)
{

}

DroidMemory::DroidMemory(const DroidMemory &other)
    : _fingerprint(other._fingerprint), _exp(other._exp)
{

}

DroidMemory::~DroidMemory()
{

}

DroidMemory &DroidMemory::operator=(const DroidMemory &other)
{
    if (this != &other) {
        _fingerprint = other._fingerprint;
        _exp = other._exp;
    }
    return *this;
}

DroidMemory &DroidMemory::operator<<(const DroidMemory &other)
{
    _exp += other._exp;
    _fingerprint ^= other._fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &other)
{
    other._exp += _exp;
    other._fingerprint ^= _fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &other)
{
    return *this << other;
}

DroidMemory &DroidMemory::operator+=(size_t exp)
{
    _exp += exp;
    _fingerprint ^= exp;
    return *this;
}

DroidMemory DroidMemory::operator+(const DroidMemory &other) const
{
    DroidMemory result(*this);
    result += other;
    return result;
}

DroidMemory DroidMemory::operator+(size_t exp) const
{
    DroidMemory result(*this);
    result += exp;
    return result;
}

bool DroidMemory::operator==(const DroidMemory &other) const
{
    return _exp == other._exp && _fingerprint == other._fingerprint;
}

bool DroidMemory::operator!=(const DroidMemory &other) const
{
    return !(*this == other);
}

bool DroidMemory::operator<(const DroidMemory &other) const
{
    return _exp < other._exp;
}

bool DroidMemory::operator>(const DroidMemory &other) const
{
    return _exp > other._exp;
}

bool DroidMemory::operator<=(const DroidMemory &other) const
{
    return _exp <= other._exp;
}

bool DroidMemory::operator>=(const DroidMemory &other) const
{
    return _exp >= other._exp;
}

bool DroidMemory::operator<(size_t exp) const
{
    return _exp < exp;
}

bool DroidMemory::operator>(size_t exp) const
{
    return _exp > exp;
}

bool DroidMemory::operator<=(size_t exp) const
{
    return _exp <= exp;
}

bool DroidMemory::operator>=(size_t exp) const
{
    return _exp >= exp;
}

size_t DroidMemory::getFingerprint() const
{
    return _fingerprint;
}

size_t DroidMemory::getExp() const
{
    return _exp;
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    _fingerprint = fingerprint;
}

void DroidMemory::setExp(size_t exp)
{
    _exp = exp;
}

void DroidMemory::print(std::ostream &out) const
{
    out << "DroidMemory '" << _fingerprint << "', " << _exp;
}

std::ostream &operator<<(std::ostream &out, const DroidMemory &memory)
{
    memory.print(out);
    return out;
}

