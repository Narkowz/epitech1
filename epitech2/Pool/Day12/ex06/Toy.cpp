/*
** EPITECH PROJECT, 2025
** Toy.cpp
** File description:
** Toy
*/


Copy
#include "Toy.hpp"

// Default Constructor
Toy::Toy() : type(BASIC_TOY), name("toy"), picture("") {}

// Parameterized Constructor
Toy::Toy(ToyType type, const std::string& name, const std::string& filename)
    : type(type), name(name), picture(filename) {}

// Copy Constructor
Toy::Toy(const Toy& other)
    : type(other.type), name(other.name), picture(other.picture) {}

// Destructor
Toy::~Toy() {}

// Copy Assignment Operator
Toy& Toy::operator=(const Toy& other) {
    if (this != &other) {
        type = other.type;
        name = other.name;
        picture = other.picture;
    }
    return *this;
}

// Getter for type
Toy::ToyType Toy::getType() const {
    return type;
}

// Getter for name
std::string Toy::getName() const {
    return name;
}

// Setter for name
void Toy::setName(const std::string& name) {
    this->name = name;
}

// Set picture from file
bool Toy::setAscii(const std::string& filename) {
    if (!picture.getPictureFromFile(filename)) {
        lastError.type = Error::PICTURE;
        lastError.function = "setAscii";
        return false;
    }
    return true;
}

// Get picture as string
std::string Toy::getAscii() const {
    return picture.data;
}

// Speak method (now returns bool)
bool Toy::speak(const std::string& statement) {
    std::cout << name << " \"" << statement << "\"" << std::endl;
    return true; // Always returns true unless there's an error
}

// Speak Spanish method
bool Toy::speak_es(const std::string& statement) {
    lastError.type = Error::SPEAK;
    lastError.function = "speak_es";
    return false;
}

// Get last error
Toy::Error Toy::getLastError() const {
    return lastError;
}

// Overload << operator as a member function
std::ostream& Toy::print(std::ostream& os) const {
    os << name << std::endl << picture.data << std::endl;
    return os;
}

// Overload << operator between Toy and std::string
Toy& Toy::operator<<(const std::string& str) {
    picture.data = str;
    return *this;
}

// Overload << operator for Toy using a non-friend function
std::ostream& operator<<(std::ostream& os, const Toy& toy) {
    return toy.print(os);
}