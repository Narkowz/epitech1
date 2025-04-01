/*
** EPITECH PROJECT, 2025
** ACitrus.hpp
** File description:
** ACitrus
*/

#ifndef ACITRUS_HPP_
#define ACITRUS_HPP_

#include "AFruit.hpp"

class ACitrus : public AFruit {
public:
    ACitrus(const std::string &name, unsigned int vitamins) : AFruit(name, vitamins) {}
};

#endif /* !ACITRUS_HPP_ */
