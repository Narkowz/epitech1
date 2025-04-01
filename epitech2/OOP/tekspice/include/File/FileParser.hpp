/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** FileParser
*/

#pragma once

#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_set>

#include "IParser.hpp"
#include "File/ParsedCircuit.hpp"
#include "Exception/FileParsingException.hpp"
#include "Utils/StringUtils.hpp"

namespace File {
    class FileParser : public IParser {
    private:
        static void checkFileName(const std::string &filename);
        void parseChipset(const std::string &line);
        void parseLink(const std::string &line);
        void ProcessLine(const std::string &line);

        enum ParsingPart {
            PARSING_NOTHING,
            PARSING_CHIPSETS,
            PARSING_LINKS
        };

        ParsingPart _parsingPart;
        ParsedCircuit _parsedCircuit;

        std::unordered_set<std::string> _seenComponentNames;
    public:
        FileParser() : _parsingPart(PARSING_NOTHING) {};
        void parseFile(const std::string &filename) override;
        ParsedCircuit getParsedCircuit() const { return _parsedCircuit; };
    };
}
