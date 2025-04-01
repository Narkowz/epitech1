/*
** EPITECH PROJECT, 2025
** UniquePointer.hpp
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
#define UNIQUEPOINTER_HPP_

#include "IObject.hpp"
#include <utility>
#include <ostream>

class UniquePointer {
private:
    IObject* ptr;
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

public:
    UniquePointer() : ptr(nullptr) {}
    explicit UniquePointer(IObject* p) : ptr(p) {}
    UniquePointer(UniquePointer&& other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }
    UniquePointer& operator=(UniquePointer&& other) noexcept
    {
        if (this != &other) {
            reset();
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    ~UniquePointer()
    {
        reset();
    }
    void reset(IObject* p = nullptr)
    {
        if (ptr) {
            std::cout << ptr->getName() << " is dead" << std::endl;
            delete ptr;
        }
        ptr = p;
    }
    void swap(UniquePointer& other) noexcept
    {
        std::swap(ptr, other.ptr);
    }
    IObject& operator*() const
    {
        return *ptr;
    }
    IObject* operator->() const
    {
        return ptr;
    }
    IObject* get() const
    {
        return ptr;
    }
    explicit operator bool() const
    {
        return ptr != nullptr;
    }
};

#endif /* !UNIQUEPOINTER_HPP_ */
