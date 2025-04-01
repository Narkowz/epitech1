/*
** EPITECH PROJECT, 2025
** FruitBox.cpp
** File description:
** FruitBox
*/

#include "FruitBox.hpp"
#include "IFruit.hpp"
#include <algorithm>

FruitBox::FruitBox(unsigned int size) : _size(size)
{
}

FruitBox::~FruitBox()
{
    // No need to manually delete fruits, unique_ptr handles it
}

unsigned int FruitBox::getSize() const
{
    return _size;
}

unsigned int FruitBox::nbFruits() const
{
    return fruits.size();
}

bool FruitBox::pushFruit(std::unique_ptr<IFruit> fruit)
{
    if (fruits.size() >= _size || !fruit)
        return false;
    for (const auto& f : fruits)
        if (f.get() == fruit.get())
            return false;
    fruits.push_back(std::move(fruit));
    return true;
}

std::unique_ptr<IFruit> FruitBox::popFruit()
{
    if (fruits.empty())
        return nullptr;
    std::unique_ptr<IFruit> fruit = std::move(fruits.front());
    fruits.erase(fruits.begin());
    return fruit;
}

void FruitBox::display(std::ostream& os) const
{
    os << "[";
    for (size_t i = 0; i < fruits.size(); ++i) {
        os << *fruits[i];
        if (i < fruits.size() - 1)
            os << ", ";
    }
    os << "]";
}

const std::vector<std::unique_ptr<IFruit>>& FruitBox::getFruits() const
{
    return fruits;
}

std::ostream& operator<<(std::ostream& os, const FruitBox& box) {
    const auto& fruits = box.getFruits();
    os << "[";
    for (size_t i = 0; i < fruits.size(); ++i) {
        if (i > 0) os << ", ";
        os << "[name: \"" << fruits[i]->getName()
           << "\", vitamins: " << fruits[i]->getVitamins()
           << ", peeled: " << (fruits[i]->isPeeled() ? "true" : "false") << "]";
    }
    os << "]";
    return os;
}
