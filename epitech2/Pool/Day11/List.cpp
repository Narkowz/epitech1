/*
** EPITECH PROJECT, 2025
** Liste.cpp
** File description:
** List
*/

#include "List.hpp"
#include <iostream>

List::List() : head(nullptr), tail(nullptr), listSize(0) {}

List::~List()
{
    clearNodes();
}

void List::clearNodes()
{
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    tail = nullptr;
    listSize = 0;
}

bool List::empty() const
{
    return listSize == 0;
}

std::size_t List::size() const
{
    return listSize;
}

IObject*& List::front()
{
    if (empty())
        throw InvalidOperationException();
    return head->data;
}

IObject* List::front() const
{
    if (empty())
        throw InvalidOperationException();
    return head->data;
}

IObject*& List::back()
{
    if (empty())
        throw InvalidOperationException();
    return tail->data;
}

IObject* List::back() const
{
    if (empty())
        throw InvalidOperationException();
    return tail->data;
}

void List::pushBack(IObject* obj)
{
    Node* newNode = new Node(obj, tail, nullptr);
    if (tail)
        tail->next = newNode;
    else
        head = newNode;
    tail = newNode;
    listSize++;
}

void List::pushFront(IObject* obj)
{
    Node* newNode = new Node(obj, nullptr, head);
    if (head)
        head->prev = newNode;
    else
        tail = newNode;
    head = newNode;
    listSize++;
}

void List::popFront()
{
    if (empty())
        throw InvalidOperationException();
    Node* temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;
    delete temp->data;
    delete temp;
    listSize--;
}

void List::popBack()
{
    if (empty())
        throw InvalidOperationException();
    Node* temp = tail;
    tail = tail->prev;
    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;
    delete temp->data;
    delete temp;
    listSize--;
}

void List::clear()
{
    clearNodes();
}

void List::forEach(void(*function)(IObject*))
{
    Node* current = head;
    while (current) {
        function(current->data);
        current = current->next;
    }
}
