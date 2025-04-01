/*
** EPITECH PROJECT, 2025
** Buz.hpp
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_
#include "Toy.hpp"

class Buzz : public Toy {
public:
    Buzz(const std::string& name, const std::string& filename = "buzz.txt");
    bool speak(const std::string& statement) override;
    bool speak_es(const std::string& statement) override;
};

#endif /* !BUZZ_HPP_ */
