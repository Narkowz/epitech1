/*
** EPITECH PROJECT, 2025
** Peasant.hpp
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

#include <string>

class Peasant {
public:
    Peasant(const std::string& name, int power);
    virtual ~Peasant();
    const std::string& getName() const;
    int getPower() const;
    int getHp() const;
    virtual int attack();
    virtual int special();
    virtual void rest();
    void damage(int damage);
protected:
    std::string name;
    int power;
    int hp;
    void checkCombatStatus();
    void checkPowerStatus();
};

#endif /* !PEASANT_HPP_ */
