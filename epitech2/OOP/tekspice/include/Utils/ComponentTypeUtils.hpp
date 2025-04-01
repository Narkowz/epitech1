/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** ComponentTypeUtils
*/

#pragma once

#include <string>

#include "NanoTekSpice/Component/ComponentType.hpp"

namespace Utils
{
    class ComponentTypeUtils
    {
        public:
            static NanoTekSpice::ComponentType getComponentType(const std::string &type);
    };
}
