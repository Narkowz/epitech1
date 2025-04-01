/*
** EPITECH PROJECT, 2025
** Knight.hpp
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

#include "Peasant.hpp"

#include "Peasant.hpp"

class Knight : public Peasant {
public:
    Knight(const std::string& name, int power);
    ~Knight();
    int attack();
    int special();
    void rest();
};

#endif /* !KNIGHT_HPP_ */
