/*
** EPITECH PROJECT, 2025
** Student.hpp
** File description:
** Student
*/

#ifndef STUDENT_HPP_
    #define STUDENT_HPP_

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

class Student {
public:
    Student(const std::string &name);
    ~Student();
    bool learn(const std::string &text);
    void drink(const std::string &drink);
    std::string getName() const;
private:
    std::string name;
    int energy;
};

#endif /* !STUDENT_HPP_ */
