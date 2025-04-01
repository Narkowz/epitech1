/*
** EPITECH PROJECT, 2025
** FruitUtils.hpp
** File description:
** FruitUtils
*/

#ifndef FRUITUTILS_HPP_
#define FRUITUTILS_HPP_

#include "FruitBox.hpp"
#include "ACitrus.hpp"
#include "ABerry.hpp"
#include "ANut.hpp"
#include "Lemon.hpp"

class FruitUtils {
public:
    static void sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry) {
        std::vector<IFruit*> remainingFruits;
        
        // Sort fruits
        while (unsorted.nbFruits() > 0) {
            IFruit *fruit = unsorted.popFruit();
            if (dynamic_cast<Lemon*>(fruit)) {
                if (!lemon.pushFruit(fruit)) {
                    remainingFruits.push_back(fruit);
                }
            } else if (dynamic_cast<ACitrus*>(fruit)) {
                if (!citrus.pushFruit(fruit)) {
                    remainingFruits.push_back(fruit);
                }
            } else if (dynamic_cast<ABerry*>(fruit)) {
                if (!berry.pushFruit(fruit)) {
                    remainingFruits.push_back(fruit);
                }
            } else {
                remainingFruits.push_back(fruit);
            }
        }
        
        // Re-add remaining fruits to unsorted box
        for (IFruit* fruit : remainingFruits) {
            unsorted.pushFruit(fruit);
        }
    }
};

#endif /* !FRUITUTILS_HPP_ */
