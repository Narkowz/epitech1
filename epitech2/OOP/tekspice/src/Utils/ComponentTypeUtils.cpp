/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** ComponentTypeUtils
*/

#include "Utils/ComponentTypeUtils.hpp"

namespace Utils
{
    static const std::map<std::string, NanoTekSpice::ComponentType> stringToComponentTypeMap = {
        {"input", NanoTekSpice::CT_INPUT},
        {"output", NanoTekSpice::CT_OUTPUT},
        {"true", NanoTekSpice::CT_TRUE},
        {"false", NanoTekSpice::CT_FALSE},
        {"clock", NanoTekSpice::CT_CLOCK},
        {"and", NanoTekSpice::CT_AND},
        {"or", NanoTekSpice::CT_OR},
        {"xor", NanoTekSpice::CT_XOR},
        {"not", NanoTekSpice::CT_NOT},
        {"logger", NanoTekSpice::CT_LOGGER},
        {"4001", NanoTekSpice::CT_4001},
        {"4011", NanoTekSpice::CT_4011},
        {"4030", NanoTekSpice::CT_4030},
        {"4069", NanoTekSpice::CT_4069},
        {"4071", NanoTekSpice::CT_4071},
        {"4081", NanoTekSpice::CT_4081},
        {"4008", NanoTekSpice::CT_4008},
        {"4013", NanoTekSpice::CT_4013},
        {"4017", NanoTekSpice::CT_4017},
        {"4040", NanoTekSpice::CT_4040},
        {"4094", NanoTekSpice::CT_4094},
        {"4512", NanoTekSpice::CT_4512},
        {"4514", NanoTekSpice::CT_4514},
        {"4801", NanoTekSpice::CT_4801},
        {"2716", NanoTekSpice::CT_2716}
    };

    NanoTekSpice::ComponentType ComponentTypeUtils::getComponentType(const std::string &type) {
        auto it = stringToComponentTypeMap.find(type);
        if (it == stringToComponentTypeMap.end()) {
            return NanoTekSpice::CT_UNDEFINED;
        }
        return it->second;
    }
}
