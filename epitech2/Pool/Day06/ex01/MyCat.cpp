/*
** EPITECH PROJECT, 2025
** MyCat.cpp
** File description:
** MyCat
*/

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    std::string line;
    if (argc == 1)
        while (std::getline(std::cin, line))
            std::cout << line << std::endl;
    for (int i = 1; i < argc; ++i) {
        std::ifstream file(argv[i]);
        if (!file.is_open()) {
            std::cerr << "MyCat: " << argv[i] << ": No such file or directory" << std::endl;
            return 84;
        }
        while (std::getline(file, line))
            std::cout << line << std::endl;
        file.close();
    }
    return 0;
}