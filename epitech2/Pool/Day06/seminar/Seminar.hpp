/*
** EPITECH PROJECT, 2025
** Seminar.hpp
** File description:
** Seminar
*/

#ifndef SEMINAR_HPP_
#define SEMINAR_HPP_

#include <vector>
#include <iostream>
#include "Dean.hpp"
#include "Assistant.hpp"
#include "Student.hpp"

class Seminar {
public:
    Seminar();
    ~Seminar();
    void addDean(Dean *dean);
    void addAssistant(Assistant *assistant);
    void addStudent(Student *student);
    void run();
    
private:
    std::vector<Dean *> deans;
    std::vector<Assistant *> assistants;
    std::vector<Student *> students;
    bool isRunning;
};

#endif /* !SEMINAR_HPP_ */
