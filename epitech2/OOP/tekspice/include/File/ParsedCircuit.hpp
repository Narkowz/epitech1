/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** ParsedCircuit
*/

#pragma once

#include <vector>
#include <string>
#include <utility>

#include "NanoTekSpice/Component/ComponentType.hpp"

class ParsedCircuit {
    public:
        void addChipset(NanoTekSpice::ComponentType type, const std::string &name);
        void addLink(std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>>);
        bool followBaseRequirements();
        void clearChipsets();
        std::vector<std::pair<NanoTekSpice::ComponentType, std::string>> getChipsets() const { return _chipsets; }
        std::vector<std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>>> getLinks() const { return _links; }
    private:
        std::vector<std::pair<NanoTekSpice::ComponentType, std::string>> _chipsets;
        std::vector<std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>>> _links;

        bool checkOutput();
};
