/*
** EPITECH PROJECT, 2025
** Phaser.cpp
** File description:
** Phaser
*/

#include "Phaser.hpp"

Phaser::Phaser(int maxAmmo, AmmoType type) 
    : maxAmmo(maxAmmo), currentAmmo(maxAmmo), defaultType(type), magazine(maxAmmo, type)
{

}

Phaser::~Phaser()
{

}

void Phaser::fire()
{
    if (currentAmmo == Empty)
        std::cout << "Clip empty, please reload" << std::endl;
    else {
        std::cout << getAmmoSound(magazine[0]) << std::endl;
        magazine.erase(magazine.begin());
        --currentAmmo;
    }
}

void Phaser::ejectClip()
{
    magazine.clear();
    currentAmmo = Empty;
}

void Phaser::changeType(AmmoType newType)
{
    defaultType = newType;
    std::cout << "Switching ammo to type: " << ammoTypeToString(newType) << std::endl;
}

void Phaser::reload()
{
    std::cout << "Reloading..." << std::endl;
    magazine.assign(maxAmmo, defaultType);
    currentAmmo = maxAmmo;
}

void Phaser::addAmmo(AmmoType type)
{
    if (currentAmmo >= maxAmmo) {
        std::cout << "Clip full" << std::endl;
        return;
    }
    magazine.push_back(type);
    ++currentAmmo;
}

int Phaser::getCurrentAmmos() const
{
    return currentAmmo;
}

std::string Phaser::getAmmoSound(AmmoType type) const
{
    switch (type) {
        case REGULAR: return Sounds::Regular;
        case PLASMA: return Sounds::Plasma;
        case ROCKET: return Sounds::Rocket;
        default: return "";
    }
}

std::string Phaser::ammoTypeToString(AmmoType type) const
{
    switch (type) {
        case REGULAR: return "regular";
        case PLASMA: return "plasma";
        case ROCKET: return "rocket";
        default: return "";
    }
}
