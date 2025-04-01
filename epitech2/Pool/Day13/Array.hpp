/*
** EPITECH PROJECT, 2025
** Array.hpp
** File description:
** Array
*/

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include <functional>
#include <stdexcept>

template <typename Type, std::size_t Size>
class Array {
private:
    Type data[Size];

public:
    Type& operator[](std::size_t index)
    {
        if (index >= Size)
            throw std::out_of_range("Out of range");
        return data[index];
    }

    const Type& operator[](std::size_t index) const
    {
        if (index >= Size)
            throw std::out_of_range("Out of range");
        return data[index];
    }

    std::size_t size() const
    {
        return Size;
    }

    void forEach(const std::function<void(const Type&)>& task) const
    {
        for (std::size_t i = 0; i < Size; ++i)
            task(data[i]);
    }

    template <typename U>
    Array<U, Size> convert(const std::function<U(const Type&)>& converter) const
    {
        Array<U, Size> result;
        for (std::size_t i = 0; i < Size; ++i)
            result[i] = converter(data[i]);
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Array<Type, Size>& array)
    {
        os << "[";
        for (std::size_t i = 0; i < Size; ++i) {
            os << array[i];
            if (i < Size - 1)
                os << ", ";
        }
        os << "]";
        return os;
    }
};
#endif /* !ARRAY_HPP_ */
