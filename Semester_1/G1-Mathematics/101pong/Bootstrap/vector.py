#-*- coding: utf-8 -*-
#!/usr/bin/python3

from math import *
#from collections import *

def norme(tuple_coord:tuple):
    return sqrt(float(tuple_coord[0] ** 2) + float(tuple_coord[1] ** 2) + float(tuple_coord[2] ** 2))

def vector(x:float, y:float, z:float) -> tuple:
    x, y, z = float(x), float(y), float(z)
    v = (x, y, z)
    return v

def dif_vector(p_1_tuple:tuple, p_2_tuple:tuple):
    element_p1, element_p2 = 0, 0
    vector_list = []

    for _ in p_1_tuple:
        element_p1 += 1
    for _ in p_2_tuple:
        element_p2 += 1
    if element_p1 == element_p2:
        for i in range(element_p1):
            vector_list.append(p_2_tuple[i] - p_1_tuple[i])
    else:
        print("Impossible les deux points n'ont pas le même nombre de coordonnées")
        return 84
    vector = tuple(vector_list)
    return vector


def sum_vector(p_1_tuple: tuple, p_2_tuple: tuple):
    element_p1, element_p2 = 0, 0
    vector_list = []
    
    for _ in p_1_tuple:
        element_p1 += 1
    for _ in p_2_tuple:
        element_p2 += 1
    if element_p1 == element_p2:
        for i in range(element_p1):
            vector_list.append(p_2_tuple[i] + p_1_tuple[i])
    else:
        print("Impossible les deux points n'ont pas le même nombre de coordonnées")
        return 84
    vector = tuple(vector_list)
    return vector

def n_vector(vector:tuple, n:int):
    n_vect_list = []
    
    for element in vector:
        n_vect_list.append(element * n)
    n_vect_tuple = tuple(n_vect_list)
    return n_vect_tuple

def is_touching(x0, y0, z0, x1, y1, z1, n):
    pass