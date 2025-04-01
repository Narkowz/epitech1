/*
** EPITECH PROJECT, 2025
** KoalaBot.cpp
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include "Parts.hpp"
#include <string>
#include <iostream>

class KoalaBot {
public:
    KoalaBot(const std::string& serial = "Bob-01");
    void setParts(const Arms& arms);
    void setParts(const Legs& legs);
    void setParts(const Head& head);

    void swapParts(Arms& arms);
    void swapParts(Legs& legs);
    void swapParts(Head& head);

    void informations() const;
    bool status() const;

private:
    std::string _serial;
    Arms _arms;
    Legs _legs;
    Head _head;
};


#endif /* !KOALABOT_HPP_ */
