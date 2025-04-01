/*
** EPITECH PROJECT, 2025
** Assistant.cpp
** File description:
** Assistant
*/

#include "Assistant.hpp"

Assistant::Assistant(int id) : id(id), isWorking(false)
{
    std::cout << "Assistant " << id << ": 'morning everyone *sip coffee*" << std::endl;
}

Assistant::~Assistant()
{
    std::cout << "Assistant " << id << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

void Assistant::giveDrink(Student *student, const std::string &drink)
{
    if (student) {
        std::cout << "Assistant " << id << ": drink this, " << student->getName() << " *sip coffee*" << std::endl;
        student->drink(drink);
    }
}

std::string Assistant::readDrink(const std::string &studentName)
{
    std::string filename = studentName + ".drink";
    std::ifstream file(filename);
    std::string drink;

    if (file.is_open()) {
        std::getline(file, drink);
        file.close();
        std::remove(filename.c_str());
        std::cout << "Assistant " << id << ": " << studentName << " needs a " << drink << " *sip coffee*" << std::endl;
        return drink;
    }
    return "";
}

void Assistant::helpStudent(Student *student)
{
    if (student) {
        std::string drink = readDrink(student->getName());
        if (!drink.empty()) {
            giveDrink(student, drink);
        } else {
            std::cout << "Assistant " << id << ": " << student->getName() << " seems fine *sip coffee*" << std::endl;
        }
    }
}

void Assistant::timeCheck()
{
    if (isWorking)
        std::cout << "Assistant " << id << ": Enough teaching for today *sip coffee*" << std::endl;
    else
        std::cout << "Assistant " << id << ": Time to teach some serious business *sip coffee*" << std::endl;
    isWorking = !isWorking;
}

int Assistant::getId() const
{
    return id;
}