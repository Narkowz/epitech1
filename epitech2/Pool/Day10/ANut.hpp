/*
** EPITECH PROJECT, 2025
** ANut.hpp
** File description:
** ANut
*/

#ifndef ANUT_HPP_
#define ANUT_HPP_

#include "AFruit.hpp"

class ANut : public AFruit {
public:
    ANut(const std::string &name, unsigned int vitamins) : AFruit(name, vitamins) {}
};

#endif /* !ANUT_HPP_ */
