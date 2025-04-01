/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** ParsedCircuit
*/

#include "File/ParsedCircuit.hpp"

void ParsedCircuit::addChipset(NanoTekSpice::ComponentType type, const std::string &name) {
    _chipsets.push_back({type, name});
}

void ParsedCircuit::clearChipsets() {
    _chipsets.clear();
}

void ParsedCircuit::addLink(std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>> link) {
    _links.push_back(link);
}

bool ParsedCircuit::checkOutput() {
    for (const auto &chipset : _chipsets) {
        if (chipset.first == NanoTekSpice::CT_OUTPUT || chipset.first == NanoTekSpice::CT_LOGGER) {
            return true;
        }
    }
    return false;
}

bool ParsedCircuit::followBaseRequirements() {
    if (_chipsets.empty()) {
        return false;
    }
    if (!checkOutput()) {
        return false;
    }
    return true;
}