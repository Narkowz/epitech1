/*
** EPITECH PROJECT, 2025
** Phaser.hpp
** File description:
** Phaser
*/

#ifndef PHASER_HPP_
#define PHASER_HPP_

#include "Sounds.hpp"
#include <iostream>
#include <vector>
#include <string>

class Phaser {
public:
    enum AmmoType { REGULAR, PLASMA, ROCKET };

    Phaser(int maxAmmo, AmmoType type);
    ~Phaser();

    void fire();
    void ejectClip();
    void changeType(AmmoType newType);
    void reload();
    void addAmmo(AmmoType type);
    int getCurrentAmmos() const;

private:
    static const int Empty = 0;
    int maxAmmo;
    int currentAmmo;
    AmmoType defaultType;
    std::vector<AmmoType> magazine;

    std::string getAmmoSound(AmmoType type) const;
    std::string ammoTypeToString(AmmoType type) const;
};

#endif /* !PHASER_HPP_ */
