/*
** EPITECH PROJECT, 2025
** Woody.hpp
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
public:
    Woody(const std::string& name, const std::string& filename = "woody.txt");
};

#endif /* !WOODY_HPP_ */
