/*
** EPITECH PROJECT, 2025
** SharedPointer.cpp
** File description:
** SharedPointer
*/

#include "SharedPointer.hpp"
#include <iostream>

SharedPointer::SharedPointer() : ptr(nullptr), refCount(nullptr)
{

}

SharedPointer::SharedPointer(IObject* p) : ptr(p), refCount(new size_t(1))
{

}

SharedPointer::SharedPointer(const SharedPointer& other) 
    : ptr(other.ptr), refCount(other.refCount)
{
    if (refCount)
        (*refCount)++;
}

SharedPointer::SharedPointer(SharedPointer&& other) noexcept 
    : ptr(other.ptr), refCount(other.refCount)
{
    other.ptr = nullptr;
    other.refCount = nullptr;
}

SharedPointer::~SharedPointer()
{
    release();
}

SharedPointer& SharedPointer::operator=(const SharedPointer& other)
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

SharedPointer& SharedPointer::operator=(SharedPointer&& other) noexcept
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

void SharedPointer::reset(IObject* p)
{
    release();
    if (p) {
        ptr = p;
        refCount = new size_t(1);
    }
}

void SharedPointer::swap(SharedPointer& other) noexcept
{
    std::swap(ptr, other.ptr);
    std::swap(refCount, other.refCount);
}

IObject& SharedPointer::operator*() const
{
    return *ptr;
}

IObject* SharedPointer::operator->() const
{
    return ptr;
}

IObject* SharedPointer::get() const
{
    return ptr;
}

size_t SharedPointer::use_count() const
{
    return refCount ? *refCount : 0;
}

SharedPointer::operator bool() const
{
    return ptr != nullptr;
}

void SharedPointer::release()
{
    if (refCount) {
        (*refCount)--;
        if (*refCount == 0) {
            delete ptr;
            delete refCount;
        }
    }
}
