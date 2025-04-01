/*
** EPITECH PROJECT, 2025
** main.cpp
** File description:
** main
*/

#include "MyGKrellm.hpp"


void printHelp()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "    ./MyGKrellm [OPTIONS]" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "    -h    print the usage and quit." << std::endl;
    std::cout << "    -t    use the ncurses display." << std::endl;
    std::cout << "    -g    use the sfml display." << std::endl;
    exit(0);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Invalid argument" << std::endl;
        return 84;
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        printHelp();
        return 0;
    }
    Krell::Monitor monitor; // Crée un moniteur

    monitor.addModule(std::make_shared<Krell::SYSModule>()); // Ajoute des modules
    monitor.addModule(std::make_shared<Krell::CPUModule>());
    monitor.addModule(std::make_shared<Krell::RAMModule>());
    monitor.addModule(std::make_shared<Krell::NETModule>());

    if (av[1][0] == '-' && av[1][1] == 't')
        monitor.setDisplay(std::make_shared<Krell::ncursesDisplay>()); // Définit l'affichage ncurses
    else if (av[1][0] == '-' && av[1][1] == 'g')
        monitor.setDisplay(std::make_shared<Krell::SFMLDisplay>()); // Définit l'affichage SFML
    else {
        std::cerr << "Invalid argument" << std::endl;
        return 84;
    }

    monitor.run(); // Lance le programme

    return 0;
}