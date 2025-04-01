/*
** EPITECH PROJECT, 2025
** ABerry.hpp
** File description:
** ABerry
*/

#ifndef ABERRY_HPP_
#define ABERRY_HPP_

#include "AFruit.hpp"

class ABerry : public AFruit {
public:
    ABerry(const std::string &name, unsigned int vitamins) : AFruit(name, vitamins) {
        peel(); // Berries are always peeled
    }
};

#endif /* !ABERRY_HPP_ */
