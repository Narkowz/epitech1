/*
** EPITECH PROJECT, 2025
** ToyStory.hpp
** File description:
** ToyStory
*/

#ifndef TOYSTORY_HPP_
#define TOYSTORY_HPP_

#include "Toy.hpp"
#include <string>
#include <fstream>

class ToyStory {
public:
    using FuncPtr = bool (Toy::*)(const std::string&);

    static void tellMeAStory(const std::string& filename, Toy& toy1, FuncPtr func1, Toy& toy2, FuncPtr func2);
};

#endif /* !TOYSTORY_HPP_ */
