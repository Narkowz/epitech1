/*
** EPITECH PROJECT, 2025
** Enchanter.hpp
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP_
#define ENCHANTER_HPP_

#include "Peasant.hpp"

class Enchanter : public Peasant {
public:
    Enchanter(const std::string& name, int power);
    ~Enchanter();
    int attack() override;
    int special() override;
    void rest() override;
};

#endif /* !ENCHANTER_HPP_ */
