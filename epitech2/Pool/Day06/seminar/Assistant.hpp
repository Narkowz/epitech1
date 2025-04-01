/*
** EPITECH PROJECT, 2025
** Assistant.hpp
** File description:
** Assistant
*/

#ifndef ASSISTANT_HPP_
#define ASSISTANT_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include "Student.hpp"

class Assistant {
public:
    Assistant(int id);
    ~Assistant();
    void giveDrink(Student *student, const std::string &drink);
    std::string readDrink(const std::string &studentName);
    void helpStudent(Student *student);
    void timeCheck();
    int getId() const;
private:
    int id;
    bool isWorking;
};

#endif /* !ASSISTANT_HPP_ */
