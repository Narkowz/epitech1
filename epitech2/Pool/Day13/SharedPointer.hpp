/*
** EPITECH PROJECT, 2025
** SharedPointer.hpp
** File description:
** SharedPointer
*/

#ifndef SHAREDPOINTER_HPP_
#define SHAREDPOINTER_HPP_

#include <iostream>

template <typename Type>
class SharedPointer {
private:
    Type* ptr;
    size_t* refCount;

    void release()
    {
        if (refCount) {
            (*refCount)--;
            if (*refCount == 0) {
                delete ptr;
                delete refCount;
            }
        }
    }

public:
    SharedPointer() : ptr(nullptr), refCount(nullptr)
    {

    }

    explicit SharedPointer(Type* p) : ptr(p), refCount(new size_t(1))
    {

    }

    SharedPointer(const SharedPointer& other) : ptr(other.ptr), refCount(other.refCount)
    {
        if (refCount)
            (*refCount)++;
    }

    SharedPointer(SharedPointer&& other) noexcept : ptr(other.ptr), refCount(other.refCount)
    {
        other.ptr = nullptr;
        other.refCount = nullptr;
    }

    ~SharedPointer()
    {
        release();
    }

    SharedPointer& operator=(const SharedPointer& other)
    {
        if (this != &other) {
            release();
            ptr = other.ptr;
            refCount = other.refCount;
            if (refCount)
                (*refCount)++;
        }
        return *this;
    }

    SharedPointer& operator=(SharedPointer&& other) noexcept
    {
        if (this != &other) {
            release();
            ptr = other.ptr;
            refCount = other.refCount;
            other.ptr = nullptr;
            other.refCount = nullptr;
        }
        return *this;
    }

    SharedPointer& operator=(Type* p)
    {
        release();
        ptr = p;
        refCount = new size_t(1);
        return *this;
    }

    void reset()
    {
        release();
        ptr = nullptr;
        refCount = nullptr;
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

    size_t use_count() const
    {
        return (refCount) ? *refCount : 0;
    }
};

#endif /* !SHAREDPOINTER_HPP_ */
