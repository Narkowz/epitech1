/*
** EPITECH PROJECT, 2024
** nankoTekSpice
** File description:
** main.cpp
*/

#include "File/FileParser.hpp"
#include "Console/ConsoleHandler.hpp"
#include "NanoTekSpice/Circuit.hpp"
#include "Exception/FileParsingException.hpp"
#include "Exception/CircuitException.hpp"
#include "Exception/NanoTekSpiceException.hpp"

#include <csignal>
#include <iostream>

NanoTekSpice::Circuit *glbCircuit = nullptr;

void sigintHsandler(int) {
    if (glbCircuit != nullptr && glbCircuit->isLooping()) {
        glbCircuit->endLoop();
    } else {
        exit(0);
    }
}

int main(int argc, char **argv) {
    signal(SIGINT, sigintHsandler);
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 84;
    }

    File::FileParser fileParser;
    try
    {
        fileParser.parseFile(argv[1]);
        ParsedCircuit parsedCircuit = fileParser.getParsedCircuit();
        NanoTekSpice::Circuit circuit(parsedCircuit);
        glbCircuit = &circuit;
        Console::ConsoleHandler console;
        return console.run(circuit);
    }
    catch(const Exception::FileParsingException &e)
    {
        std::cerr << "FileParsingException: " << e.what() << std::endl << "Where: " << e.where() << std::endl;
        return 84;
    }
    catch(const Exception::CircuitException &e)
    {
        std::cerr << "CircuitException: " << e.what() << std::endl << "Where: " << e.where() << std::endl;
        return 84;
    }
    catch(const Exception::NanoTekSpiceException &e)
    {
        std::cerr << "NanoTekSpiceException: " << e.what() << '\n';
        return 84;
    }
    return 0;
}
