/*
** EPITECH PROJECT, 2025
** FruitBoc.hpp
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "IFruit.hpp"
#include <vector>

class FruitBox {
private:
    unsigned int size;
    std::vector<IFruit*> fruits;

public:
    FruitBox(unsigned int size) : size(size) {}

    unsigned int getSize() const {
        return size;
    }

    unsigned int nbFruits() const {
        return fruits.size();
    }

    bool pushFruit(IFruit* fruit) {
        if (fruits.size() < size) {
            fruits.push_back(fruit);
            return true;
        }
        return false;
    }

    IFruit* popFruit() {
        if (fruits.empty()) return nullptr;
        IFruit* fruit = fruits.front();
        fruits.erase(fruits.begin());
        return fruit;
    }

    ~FruitBox() {
        for (auto fruit : fruits) {
            delete fruit;  // Ensure fruits are deleted
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const FruitBox& box);
};
#endif /* !FRUITBOX_HPP_ */
