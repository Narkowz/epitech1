/*
** EPITECH PROJECT, 2025
** SharedPointer.hpp
** File description:
** SharedPointer
*/

#ifndef SHAREDPOINTER_HPP_
#define SHAREDPOINTER_HPP_

#include "IObject.hpp"
#include <utility>

class SharedPointer {
private:
    IObject* ptr;
    size_t* refCount;
    void release();
public:
    SharedPointer();
    explicit SharedPointer(IObject* p);
    SharedPointer(const SharedPointer& other);
    SharedPointer(SharedPointer&& other) noexcept;
    ~SharedPointer();
    SharedPointer& operator=(const SharedPointer& other);
    SharedPointer& operator=(SharedPointer&& other) noexcept;
    void reset(IObject* p = nullptr);
    void swap(SharedPointer& other) noexcept;
    IObject& operator*() const;
    IObject* operator->() const;
    IObject* get() const;
    size_t use_count() const;
    explicit operator bool() const;
};

#endif /* !SHAREDPOINTER_HPP_ */
