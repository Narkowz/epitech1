#!/usr/bin/python3

from math import *

x = 3
y = -1

def make(x, y):
    return (x, y, 1.00)

def main(T):
    T = radians(2 * T)
    matrice = ((cos(T), sin(T), 0),
               (sin(T), -cos(T), 0),
               (0, 0, 1))
    matrice_init = make(x, y)
    vector = (round((matrice_init[0] * matrice[0][0] + matrice_init[1] * matrice[0][1] + matrice_init[2] * matrice[0][2]), 2),
             round((matrice_init[0] * matrice[1][0] + matrice_init[1] * matrice[1][1] + matrice_init[2] * matrice[1][2]), 2),
             round((matrice_init[0] * matrice[2][0] + matrice_init[1] * matrice[2][1] + matrice_init[2] * matrice[2][2]), 2))
    return vector

print(main(270))