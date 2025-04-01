from math import *

x = 1
y = 3
z = 5

x1 = 5
y1 = 4
z1 = 6

coeff = 3

vector1 = [x, y, z]
vector2 = [x1, y1, z1]

def sum_vector(vector1, vector2):
    vector_sum = [0, 0, 0]
    for i in range(0,3):
       vector_sum[i] = vector1[i] + vector2[i]
    return vector_sum

def diff_vector(vector1, vector2):
    vector_diff = [0, 0, 0]
    for i in range(0,3):
       vector_diff[i] = vector1[i] - vector2[i]
    return vector_diff

def coeff_vector(vector1, coeff):
    coefficient_vector = [0, 0, 0]
    for i in range(0,3):
       coefficient_vector[i] = vector1[i] * coeff
    return coefficient_vector

def norm_vector(vector1):
    normal_vector = 0
    for i in range (0,3):
        normal_vector = normal_vector + vector1[i] * vector1[i]
    normal_vector = sqrt(normal_vector)
    return normal_vector

sum = sum_vector(vector1, vector2)
diff = diff_vector(vector1, vector2)
coeff = coeff_vector(vector1, coeff)
no_vector = norm_vector(vector1)
print("Sum = ", sum)
print("Difference = ", diff)
print("Coefficient vector = ", coeff)
print("Normal : ", no_vector)