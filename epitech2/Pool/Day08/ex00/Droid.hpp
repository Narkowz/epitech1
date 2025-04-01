/*
** EPITECH PROJECT, 2025
** Droid.hpp
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>
#include <string>

class Droid {
public:
    Droid();
    explicit Droid(const std::string& serial);
    Droid(const Droid& other);
    ~Droid();
    Droid& operator=(const Droid& other);
    bool operator==(const Droid& other) const;
    bool operator!=(const Droid& other) const;
    Droid& operator<<(size_t& energy);
    const std::string& getId() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    const std::string& getStatus() const;
    void setId(const std::string& id);
    void setEnergy(size_t energy);
    void setStatus(std::string* status);
    friend std::ostream& operator<<(std::ostream& out, const Droid& droid);
private:
    std::string _id;
    size_t _energy;
    const size_t _attack;
    const size_t _toughness;
    std::string* _status;
};

#endif /* !DROID_HPP_ */
