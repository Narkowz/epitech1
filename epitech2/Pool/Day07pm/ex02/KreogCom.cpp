/*
** EPITECH PROJECT, 2025
** KreogCom.cpp
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) 
    : m_serial(serial), m_x(x), m_y(y), next(nullptr)
{
    std::cout << "KreogCom " << m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    delete next;
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial) {
    KreogCom* newCom = new KreogCom(x, y, serial);
    newCom->next = next;
    next = newCom;
}

void KreogCom::removeCom()
{
    if (next) {
        KreogCom* toDelete = next;
        next = next->next;
        toDelete->next = nullptr;
        delete toDelete;
    }
}

KreogCom* KreogCom::getCom()
{
    return next;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << m_serial << " currently at " << m_x << " " << m_y << std::endl;
}

void KreogCom::locateSquad() const
{
    if (next)
        next->locateSquad();
    ping();
}
