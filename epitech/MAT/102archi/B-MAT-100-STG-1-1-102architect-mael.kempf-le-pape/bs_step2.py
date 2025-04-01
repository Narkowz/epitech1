#!/usr/bin/python3

x = 5
y = 0

def make(x, y):
    return (x, y, 1)

def main(i, j):
    matrice = ((1, 0, i),
               (0, 1, j),
               (0, 0, 1))
    matrice_init = make(x, y)
    vector = ((matrice_init[0] * matrice[0][0] + matrice_init[1] * matrice[0][1] + matrice_init[2] * matrice[0][2]),
             (matrice_init[0] * matrice[1][0] + matrice_init[1] * matrice[1][1] + matrice_init[2] * matrice[1][2]),
             (matrice_init[0] * matrice[2][0] + matrice_init[1] * matrice[2][1] + matrice_init[2] * matrice[2][2]))

    return vector

print(main(-1, 1))