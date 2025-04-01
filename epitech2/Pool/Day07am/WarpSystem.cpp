/*
** EPITECH PROJECT, 2025
** WarpSystem.cpp
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

namespace WarpSystem {
    QuantumReactor::QuantumReactor() : _stability(true)
    {

    }

    bool QuantumReactor::isStable()
    {
        return _stability;
    }

    void QuantumReactor::setStability(bool stability)
    {
        _stability = stability;
    }

    Core::Core(QuantumReactor *coreReactor) : _coreReactor(coreReactor)
    {

    }

    QuantumReactor *Core::checkReactor()
    {
        return _coreReactor;
    }
}