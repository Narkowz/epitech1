/*
** EPITECH PROJECT, 2025
** AFruit.hpp
** File description:
** AFruit
*/

#ifndef AFRUIT_HPP_
#define AFRUIT_HPP_

#include "IFruit.hpp"

class AFruit : public IFruit {
protected:
    bool peeled = false;
    unsigned int vitamins;
    std::string name;
public:
    AFruit(const std::string &name, unsigned int vitamins)
        : vitamins(vitamins), name(name) {}
    unsigned int getVitamins() const override
    {
        return peeled ? vitamins : 0;
    }
    std::string getName() const override
    {
        return name;
    }
    bool isPeeled() const override
    {
        return peeled;
    }
    void peel() override
    {
        peeled = true;
    }
    void display(std::ostream &out) const override
    {
        out << "[name: " << name << ", vitamins: " << getVitamins() << ", peeled: " << (peeled ? "true" : "false") << "]";
    }
};

#endif /* !AFRUIT_HPP_ */
