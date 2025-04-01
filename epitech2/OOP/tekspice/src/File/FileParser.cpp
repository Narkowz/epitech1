/*
** EPITECH PROJECT, 2024
** nankoTekSpice
** File description:
** FileParser.cpp
*/

#include "File/FileParser.hpp"
#include "Utils/ComponentTypeUtils.hpp"

namespace File {
    void FileParser::parseFile(const std::string &filename) {
        checkFileName(filename);

        std::ifstream file(filename);
        if (!file || !file.is_open()) {
            THROW_FILE_EXCEPTION("Cannot open file: " + filename);
        }

        std::string line;

        while (std::getline(file, line)) {
            line = Utils::StringUtils::removeCommand(line);
            line = Utils::StringUtils::trim(line);
            if (line.empty()) {
                continue;
            }
            ProcessLine(line);
        }
        if (!_parsedCircuit.followBaseRequirements()) {
            THROW_FILE_EXCEPTION("Invalid circuit");
        }
    }

    void FileParser::ProcessLine(const std::string &line) {
        if (line == ".chipsets:") {
            _parsingPart = PARSING_CHIPSETS;
            return;
        }
        if (line == ".links:") {
            _parsingPart = PARSING_LINKS;
            return;
        }
        if (_parsingPart == PARSING_CHIPSETS) {
            parseChipset(line);
        } else if (_parsingPart == PARSING_LINKS) {
            parseLink(line);
        } else {
            THROW_FILE_EXCEPTION("Missing .chipsets or .links: " + line);
        }
    }

    void FileParser::checkFileName(const std::string &filename) {
        if (filename.empty()) {
            THROW_FILE_EXCEPTION("Filename is empty");
        }
        if (Utils::StringUtils::endWith(filename, ".nts") == false) {
            THROW_FILE_EXCEPTION("Invalid file extension: " + filename);
        }
    }

    void FileParser::parseChipset(const std::string &line) {
        std::vector<std::string> tokens = Utils::StringUtils::split(line, ' ');
        if (tokens.size() != 2) {
            THROW_FILE_EXCEPTION("Invalid chipset line: " + line);
        }

        NanoTekSpice::ComponentType type = Utils::ComponentTypeUtils::getComponentType(tokens[0]);
        if (type == NanoTekSpice::CT_UNDEFINED) {
            THROW_FILE_EXCEPTION("Invalid chipset type: " + tokens[0]);
        }

        if (_seenComponentNames.find(tokens[1]) != _seenComponentNames.end()) {
            THROW_FILE_EXCEPTION("Duplicate component name: " + tokens[1]);
        }
        _seenComponentNames.insert(tokens[1]);
        _parsedCircuit.addChipset(type, tokens[1]);
    }

    void FileParser::parseLink(const std::string &line) {
        std::vector<std::string> tokens = Utils::StringUtils::split(line, ' ');
        if (tokens.size() != 2) {
            THROW_FILE_EXCEPTION("Invalid link line: " + line);
        }

        if (Utils::StringUtils::countChar(tokens[0], ':') != 1 || Utils::StringUtils::countChar(tokens[1], ':') != 1) {
            THROW_FILE_EXCEPTION("Invalid link line: " + line);
        }

        std::vector<std::string> firstPin = Utils::StringUtils::split(tokens[0], ':');
        std::vector<std::string> secondPin = Utils::StringUtils::split(tokens[1], ':');
    
        if (firstPin.size() != 2 || secondPin.size() != 2) {
            THROW_FILE_EXCEPTION("Invalid link line: " + line);
        }
        
        std::size_t firstPinIndex = std::stoul(firstPin[1]);
        std::size_t secondPinIndex = std::stoul(secondPin[1]);

        _parsedCircuit.addLink({{firstPin[0], firstPinIndex}, {secondPin[0], secondPinIndex}});
    }
}
