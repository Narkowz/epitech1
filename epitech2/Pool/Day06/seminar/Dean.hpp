/*
** EPITECH PROJECT, 2025
** Dean.hpp
** File description:
** Dean
*/

#ifndef DEAN_HPP_
#define DEAN_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Student.hpp"

class Dean {
public:
    Dean(const std::string &name);
    ~Dean();
    void teachStudent(Student *student, const std::string &lesson);
    void timeCheck();
    std::string getName() const;
private:
    std::string name;
    bool isWorking;
    std::string getRandomDrink() const;
};

#endif /* !DEAN_HPP_ */
