/*
** EPITECH PROJECT, 2025
** IObject.hpp
** File description:
** IObject
*/

#ifndef IOBJECT_HPP_
#define IOBJECT_HPP_

#include <iostream>
#include <string>

class IObject {
public:
    virtual ~IObject() {}
    virtual void touch() const = 0;
    virtual const std::string& getName() const = 0;
};

#endif /* !IOBJECT_HPP_ */
