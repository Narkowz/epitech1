/*
** EPITECH PROJECT, 2025
** Picture.hpp
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>

class Picture {
public:
    std::string data;

    Picture(const std::string& file = "");
    Picture(const Picture& other);
    ~Picture();
    Picture& operator=(const Picture& other);
    bool getPictureFromFile(const std::string& file);
};

#endif /* !PICTURE_HPP_ */
