#!/usr/bin/python3

from math import *
import sys

a = int(sys.argv[1])
b = int(sys.argv[2])
c = int(sys.argv[3])
d = int(sys.argv[4])
e = int(sys.argv[5])
f = int(sys.argv[6])
g = int(sys.argv[7])
h = int(sys.argv[8])
i = int(sys.argv[9])
j = int(sys.argv[10])
k = int(sys.argv[11])
l = int(sys.argv[12])

def make(g, h, i, j, k, l):
    return ((g, h, i), (j, k, l))

def main(a, b, c, d, e, f, g, h, i, j, k, l):
    matrice = ((a, b, c),
               (d, e, f))
    matrice_init = ((g, h, i),
                    (j, k, l))
    vector = (round((matrice_init[0][0] * matrice[0][0] + matrice_init[0][1] * matrice[0][1] + matrice_init[0][2] * matrice[0][2]), 2),
             round((matrice_init[1][0] * matrice[1][0] + matrice_init[1][1] * matrice[1][1] + matrice_init[2][2] * matrice[1][2]), 2),)
    print(vector)
    return

if __name__ == '__main__':
    main(a, b, c, d, e, f, g, h, i, j, k, l)