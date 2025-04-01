#!/usr/bin/python3

from math import *
import sys

a = float(sys.argv[1])
b = float(sys.argv[2])
c = float(sys.argv[3])
d = float(sys.argv[4])
e = float(sys.argv[5])
f = float(sys.argv[6])
g = float(sys.argv[7])
h = float(sys.argv[8])
i = float(sys.argv[9])
j = float(sys.argv[10])
k = float(sys.argv[11])
l = float(sys.argv[12])

def make(j, k, l):
    return (j, k, l)

def main(a, b, c, d, e, f, g, h, i, j, k, l):
    matrice = ((a, b, c),
               (d, e, f),
               (g, h, i))
    matrice_init = make(j, k, l)
    vector = (round((matrice_init[0] * matrice[0][0] + matrice_init[1] * matrice[0][1] + matrice_init[2] * matrice[0][2]), 2),
             round((matrice_init[0] * matrice[1][0] + matrice_init[1] * matrice[1][1] + matrice_init[2] * matrice[1][2]), 2),
             round((matrice_init[0] * matrice[2][0] + matrice_init[1] * matrice[2][1] + matrice_init[2] * matrice[2][2]), 2))
    print(vector)
    return vector

if __name__ == '__main__':
    main(a, b, c, d, e, f, g, h, i, j, k, l)