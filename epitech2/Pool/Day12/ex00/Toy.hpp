/*
** EPITECH PROJECT, 2025
** Toy.hpp
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"
#include <string>

class Toy {
public:
    enum ToyType {
        BASIC_TOY,
        ALIEN
    };
private:
    ToyType type;
    std::string name;
    Picture picture;
public:
    Toy();
    Toy(ToyType type, const std::string& name, const std::string& filename);
    ToyType getType() const;
    std::string getName() const;
    void setName(const std::string& name);
    bool setAscii(const std::string& filename);
    std::string getAscii() const;
};

#endif /* !TOY_HPP_ */
