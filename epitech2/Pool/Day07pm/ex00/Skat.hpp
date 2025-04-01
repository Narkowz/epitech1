/*
** EPITECH PROJECT, 2025
** Skat.hpp
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <string>
#include <iostream>

class Skat {
public:
    Skat(const std::string &name = "bob", int stimPaks = 15);
    ~Skat();

    int stimPaks() const;
    const std::string& name() const;

    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status() const;

private:
    std::string _name;
    int _stimPaks;
};

#endif /* !SKAT_HPP_ */
