/*
** EPITECH PROJECT, 2025
** FruitUtils.cpp
** File description:
** FruitUtils
*/

#include "FruitUtils.hpp"
#include "Lemon.hpp"
#include "ACitrus.hpp"
#include "ABerry.hpp"

void FruitUtils::sort(FruitBox& unsorted, FruitBox& lemon, FruitBox& citrus, FruitBox& berry)
{
    FruitBox temp(unsorted.nbFruits());

    while (unsorted.nbFruits() > 0) {
        IFruit* fruit = unsorted.popFruit();

        if (dynamic_cast<Lemon*>(fruit)) {
            if (!lemon.pushFruit(fruit)) {
                temp.pushFruit(fruit);
            }
        }
        else if (dynamic_cast<ACitrus*>(fruit) && !dynamic_cast<Lemon*>(fruit)) {
            if (!citrus.pushFruit(fruit)) {
                temp.pushFruit(fruit);
            }
        }
        else if (dynamic_cast<ABerry*>(fruit)) {
            if (!berry.pushFruit(fruit)) {
                temp.pushFruit(fruit);
            }
        }
        else {
            temp.pushFruit(fruit);
        }
    }

    while (temp.nbFruits() > 0) {
        unsorted.pushFruit(temp.popFruit());
    }
}
