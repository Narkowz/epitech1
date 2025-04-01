/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Main
*/

#include <fstream>
#include <iostream>
#include <string>

#include "Arcade.hpp"
#include "InputExceptions.hpp"
#include "PathExceptions.hpp"

int display_help(void)
{
    std::ifstream file("assets/help.txt");
    for (std::string line; std::getline(file, line);)
        std::cout << line << std::endl;
    return 0;
}

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
        {
            display_help();
            throw InputException("One argument is needed", HERE);
        }
    }
    catch(const InputException& e)
    {
        std::cerr << e.what() << std::endl << e.where() << std::endl;
        _Exit(84);
    }

    if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")
    {
        display_help();
        return 0;
    }

    try
    {
        Arcade arcade(argv[1]);
        arcade.run();
    }
    catch (const PathException& e)
    {
        std::cerr << e.what() << std::endl << e.where() << std::endl;
        return 84;
    }
    catch (std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
