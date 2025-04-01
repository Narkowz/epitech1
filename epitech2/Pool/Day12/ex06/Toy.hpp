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
#include <iostream>

class Toy {
public:
    enum ToyType {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    };

    class Error {
    public:
        enum ErrorType {
            UNKNOWN,
            PICTURE,
            SPEAK
        };

        ErrorType type;
        std::string message;
        std::string function;
        Error() : type(UNKNOWN), message(""), function("") {}
        std::string what() const {
            if (type == PICTURE)
                return "bad new illustration";
            if (type == SPEAK)
                return "wrong mode";
            return "";
        }
        std::string where() const {
            return function;
        }
    };

private:
    ToyType type;
    std::string name;
    Picture picture;
    Error lastError;

public:
    Toy();
    Toy(ToyType type, const std::string& name, const std::string& filename);
    Toy(const Toy& other);
    ~Toy();
    Toy& operator=(const Toy& other);
    ToyType getType() const;
    std::string getName() const;
    void setName(const std::string& name);
    bool setAscii(const std::string& filename);
    std::string getAscii() const;
    virtual bool speak(const std::string& statement);
    virtual bool speak_es(const std::string& statement);
    Error getLastError() const;
    std::ostream& print(std::ostream& os) const;
    Toy& operator<<(const std::string& str);
};
std::ostream& operator<<(std::ostream& os, const Toy& toy);

#endif /* !TOY_HPP_ */
