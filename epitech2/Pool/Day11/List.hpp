/*
** EPITECH PROJECT, 2025
** List.hpp
** File description:
** List
*/

#ifndef LIST_HPP_
#define LIST_HPP_

#include "IObject.hpp"
#include <stdexcept> // For std::exception
#include <cstddef>   // For std::size_t

class List {
private:
    struct Node {
        IObject* data;
        Node* prev;
        Node* next;
        Node(IObject* obj = nullptr, Node* p = nullptr, Node* n = nullptr)
            : data(obj), prev(p), next(n) {}
    };
    Node* head;
    Node* tail;
    std::size_t listSize;
    void clearNodes();
public:
    List();
    ~List();
    List(const List&) = delete;
    List& operator=(const List&) = delete;
    class InvalidOperationException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Invalid operation on a list";
        }
    };
    bool empty() const;
    std::size_t size() const;
    IObject*& front();
    IObject* front() const;
    IObject*& back();
    IObject* back() const;
    void pushBack(IObject* obj);
    void pushFront(IObject* obj);
    void popFront();
    void popBack();
    void clear();
    void forEach(void(*function)(IObject*));
};

#endif /* !LIST_HPP_ */
