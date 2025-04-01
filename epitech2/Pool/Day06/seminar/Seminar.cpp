/*
** EPITECH PROJECT, 2025
** Seminar.cpp
** File description:
** Seminar
*/

#include "Seminar.hpp"

Seminar::Seminar() : isRunning(false)
{

}

void Seminar::run()
{
    if (!isRunning) {
        if (deans.empty() || assistants.empty() || students.empty()) {
            std::cout << "Seminar: A C++ seminar needs at least one Dean of Studies, one Assistant and one Student." << std::endl;
            return;
        }

        // Affichage des informations des participants
        std::cout << "Seminar: Begining 6th day of seminar." << std::endl;
        std::cout << "Dean of Studies: " << deans.front()->getName() << std::endl;

        std::cout << "Teaching assistants: ";
        for (size_t i = 0; i < assistants.size(); ++i) {
            if (i > 0)
                std::cout << ", ";
            std::cout << assistants[i]->getId();
        }
        std::cout << std::endl;

        std::cout << "Students: ";
        for (size_t i = 0; i < students.size(); ++i) {
            if (i > 0)
                std::cout << ", ";
            std::cout << students[i]->getName();
        }
        std::cout << std::endl;

        // Démarrage du séminaire
        std::cout << "Starting the seminar..." << std::endl;
        isRunning = true;

        for (Dean *dean : deans)
            dean->timeCheck();
        for (Assistant *assistant : assistants)
            assistant->timeCheck();

        for (Student *student : students) {
            for (Dean *dean : deans)
                dean->teachStudent(student, "Mastering the basics of C++");
        }
    } else {
        // Fin du séminaire
        std::cout << "Ending the seminar..." << std::endl;
        isRunning = false;
        for (Dean *dean : deans)
            dean->timeCheck();
        for (Assistant *assistant : assistants)
            assistant->timeCheck();
    }
}

Seminar::~Seminar()
{
    if (isRunning) {
        std::cout << "Seminar is ending..." << std::endl;
    }
}

void Seminar::addDean(Dean *dean)
{
    if (deans.size() >= 1) {
        std::cout << "Seminar: There can only be one Dean of Studies." << std::endl;
        return;
    }
    if (dean) {
        deans.push_back(dean);
        std::cout << "Seminar: Dean " << dean->getName() << " is here." << std::endl;
    }
}

void Seminar::addAssistant(Assistant *assistant)
{
    if (assistants.size() >= 2) {
        std::cout << "Seminar: There is only room for two Teaching Assistants." << std::endl;
        return;
    }
    for (const auto &existingAssistant : assistants)
        if (existingAssistant == assistant) {
            std::cout << "Seminar: Assistant " << assistant->getId() << " is already registered." << std::endl;
            return;
        }
    if (assistant) {
        assistants.push_back(assistant);
        std::cout << "Seminar: Assistant " << assistant->getId() << " joined the pedagogical team." << std::endl;
    }
}

void Seminar::addStudent(Student *student)
{
    if (students.size() >= 5) {
        std::cout << "Seminar: There is only room for five Students." << std::endl;
        return;
    }
    for (const auto &existingStudent : students)
        if (existingStudent == student) {
            std::cout << "Seminar: Student " << student->getName() << " is already registered." << std::endl;
            return;
        }
    if (student) {
        students.push_back(student);
        std::cout << "Seminar: Student " << student->getName() << " joined the seminar." << std::endl;
    }
}

void Seminar::run()
{
    if (!isRunning) {
        if (deans.empty() || assistants.empty() || students.empty()) {
            std::cout << "Seminar: A C++ seminar needs at least one Dean of Studies, one Assistant and one Student." << std::endl;
            return;
        }
        std::cout << "Starting the seminar..." << std::endl;
        isRunning = true;
        for (Dean *dean : deans)
            dean->timeCheck();
        for (Assistant *assistant : assistants)
            assistant->timeCheck();
        for (Student *student : students)
            for (Dean *dean : deans)
                dean->teachStudent(student, "Mastering the basics of C++");
    } else {
        std::cout << "Ending the seminar..." << std::endl;
        isRunning = false;
        for (Dean *dean : deans)
            dean->timeCheck();
        for (Assistant *assistant : assistants)
            assistant->timeCheck();
    }
}
