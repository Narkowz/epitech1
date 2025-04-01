/*
** EPITECH PROJECT, 2025
** Dean.cpp
** File description:
** Dean
*/

#include "Dean.hpp"

Dean::Dean(const std::string &name) : name(name), isWorking(false)
{
    std::cout << "Dean " << name << ": I'm Dean " << name << "! How do you do, fellow kids?" << std::endl;
}

Dean::~Dean()
{
    std::cout << "Dean " << name << ": Time to go home." << std::endl;
}

void Dean::teachStudent(Student *student, const std::string &lesson)
{
    if (!student->learn(lesson)) {
        std::cout << "Dean " << name << ": All work and no play makes " << student->getName() << " a dull student." << std::endl;

        // Création d'une boisson et interaction avec les assistants
        std::string drinks[] = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};
        std::string drink = drinks[std::rand() % 5];

        // Interaction avec les assistants
        Assistant *assistant = nullptr;
        if (!assistants.empty())
            assistant = assistants[std::rand() % assistants.size()]; // Prendre un assistant aléatoire

        if (assistant) {
            std::cout << "Assistant " << assistant->getId() << ": " << student->getName() << " needs a " << drink << " *sip coffee*" << std::endl;
            std::cout << "Assistant " << assistant->getId() << ": drink this, " << student->getName() << " *sip coffee*" << std::endl;
        }

        std::ofstream outFile(student->getName() + ".drink");
        if (outFile.is_open()) {
            outFile << drink;
            outFile.close();
        }
        student->drink(drink);
    }
}

void Dean::timeCheck()
{
    if (isWorking) {
        std::cout << "Dean " << name << ": Don't forget to close the windows when you leave." << std::endl;
    } else {
        std::cout << "Dean " << name << ": Where is everyone?" << std::endl;
    }
    isWorking = !isWorking;
}

std::string Dean::getRandomDrink() const
{
    const std::string drinks[] = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};
    return drinks[std::rand() % 5];
}

std::string Dean::getName() const
{
    return name;
}
