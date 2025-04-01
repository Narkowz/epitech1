/*
** EPITECH PROJECT, 2025
** Student.cpp
** File description:
** Student
*/

#include "Student.hpp"

Student::Student(const std::string &name) : name(name), energy(100)
{
    std::cout << "Student " << name << ": I'm ready to learn C++." << std::endl;
}

Student::~Student()
{
    std::cout << "Student " << name << ": Wow, much learning today, very smart, such C++." << std::endl;
}

bool Student::learn(const std::string &text)
{
    if (energy >= 42) {
        energy -= 42;
        std::cout << "Student " << name << ": I'm learning " << text << "!" << std::endl;
        return true;
    } else {
        std::string modifiedText = text;
        size_t pos = 0;
        while ((pos = modifiedText.find("C++", pos)) != std::string::npos) {
            modifiedText.replace(pos, 3, "shit");
            pos += 4;
        }
        std::cout << "Student " << name << ": I'm learning " << modifiedText << "!" << std::endl;
        return false;
    }
}


void Student::drink(const std::string &drink)
{
    if (drink == "Red Bull") {
        std::cout << "Student " << name << ": Red Bull gives you wings!" << std::endl;
        energy = std::min(100, energy + 32);
    } else if (drink == "Monster") {
        std::cout << "Student " << name << ": Unleash The Beast!" << std::endl;
        energy = std::min(100, energy + 64);
    } else {
        std::cout << "Student " << name << ": ah, yes... enslaved moisture." << std::endl;
        energy = std::min(100, energy + 1);
    }
}

std::string Student::getName() const
{
    return name;
}
