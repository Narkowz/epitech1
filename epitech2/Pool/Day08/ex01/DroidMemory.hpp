/*
** EPITECH PROJECT, 2025
** DroidMemory.hpp
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <iostream>
#include <cstdlib>

class DroidMemory {
public:
    DroidMemory();
    DroidMemory(const DroidMemory &other);
    ~DroidMemory();
    DroidMemory &operator=(const DroidMemory &other);
    DroidMemory &operator<<(const DroidMemory &other);
    DroidMemory &operator>>(DroidMemory &other);
    DroidMemory &operator+=(const DroidMemory &other);
    DroidMemory &operator+=(size_t exp);
    DroidMemory operator+(const DroidMemory &other) const;
    DroidMemory operator+(size_t exp) const;
    size_t getFingerprint() const;
    size_t getExp() const;
    void setFingerprint(size_t fingerprint);
    void setExp(size_t exp);
    void print(std::ostream &out) const;
private:
    size_t _fingerprint;
    size_t _exp;
};

std::ostream &operator<<(std::ostream &out, const DroidMemory &memory);

#endif /* !DROIDMEMORY_HPP_ */
