/*
** EPITECH PROJECT, 2025
** Woody.hpp
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
public:
    Woody(const std::string& name, const std::string& filename = "woody.txt");
    bool speak(const std::string& statement) override;
    bool speak_es(const std::string& statement) override;
};
#endif /* !WOODY_HPP_ */
