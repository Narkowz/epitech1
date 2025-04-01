/*
** EPITECH PROJECT, 2025
** KreogCom.hpp
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include <iostream>

class KreogCom {
public:
    KreogCom(int x, int y, int serial);
    ~KreogCom();

    void addCom(int x, int y, int serial);
    void removeCom();
    KreogCom* getCom();
    void ping() const;
    void locateSquad() const;

private:
    const int m_serial;
    int m_x;
    int m_y;
    KreogCom* next;
};

#endif /* !KREOGCOM_HPP_ */
