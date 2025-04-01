/*
** EPITECH PROJECT, 2025
** ToyStory.cpp
** File description:
** ToyStory
*/

#include "ToyStory.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void ToyStory::tellMeAStory(const std::string& filename, Toy& toy1, FuncPtr func1, Toy& toy2, FuncPtr func2)
{
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Bad Story" << std::endl;
        return;
    }
    std::string line;
    int lineCount = 0;
    while (std::getline(file, line)) {
        lineCount++;
        Toy* currentToy = (lineCount % 2 == 1) ? &toy1 : &toy2;
        FuncPtr currentFunc = (lineCount % 2 == 1) ? func1 : func2;
        if (line.find("picture:") == 0) {
            std::string pictureFile = line.substr(8);
            if (!currentToy->setAscii(pictureFile)) {
                auto error = currentToy->getLastError();
                std::cerr << error.where() << ": " << error.what() << std::endl;
                return;
            }
            std::cout << currentToy->getAscii() << std::endl;
        } else {
            if (!(currentToy->*currentFunc)(line)) {
                auto error = currentToy->getLastError();
                std::cerr << error.where() << ": " << error.what() << std::endl;
                return;
            }
        }
    }
}
