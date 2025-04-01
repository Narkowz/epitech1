/*
** EPITECH PROJECT, 2025
** IFruit.hpp
** File description:
** IFruit
*/

#ifndef IFRUIT_HPP_
#define IFRUIT_HPP_

#include <string>
#include <iostream>

class IFruit {
public:
    virtual ~IFruit() = default;
    virtual unsigned int getVitamins() const = 0;
    virtual std::string getName() const = 0;
    virtual bool isPeeled() const = 0;
    virtual void peel() = 0;
    virtual void display(std::ostream &out) const = 0;
};
std::ostream &operator<<(std::ostream &out, const IFruit &fruit) {
    fruit.display(out);
    return out;
}
#endif /* !IFRUIT_HPP_ */
