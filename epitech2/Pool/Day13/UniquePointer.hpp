/*
** EPITECH PROJECT, 2025
** UniquePointer.hpp
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
#define UNIQUEPOINTER_HPP_

#include <iostream>

template <typename Type>
class UniquePointer {
private:
    Type* ptr;

public:
    explicit UniquePointer(Type* p = nullptr) : ptr(p)
    {

    }

    ~UniquePointer()
    {
        delete ptr;
    }

    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    UniquePointer(UniquePointer&& other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    UniquePointer& operator=(UniquePointer&& other) noexcept
    {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    void reset()
    {
        delete ptr;
        ptr = nullptr;
    }

    Type* get() const
    {
        return ptr;
    }

    Type* operator->() const
    {
        return ptr;
    }

    Type& operator*() const
    {
        return *ptr;
    }

    UniquePointer& operator=(Type* p)
    {
        if (ptr != p) {
            delete ptr;
            ptr = p;
        }
        return *this;
    }
};

#endif /* !UNIQUEPOINTER_HPP_ */
