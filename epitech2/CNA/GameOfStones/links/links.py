##
## EPITECH PROJECT, 2025
## links.py
## File description:
## links
##

from sys import argv
from error_handling import *
from links.read_file_links import read_file_links
from links.bffs import bffs

def is_friend(tab_friend, perso, name1, name2):
    print("Degree of separation between " + name1 + " and " + name2 + ":", bffs(tab_friend, perso, name1, name2))
    exit(0)

def create_tab_friend(friends_list):
    perso = set()
    for names in friends_list:
        perso.add(names[0])
        perso.add(names[1])
    perso = sorted(list(perso))
    n = len(perso)
    tab_friend = [[0] * n for _ in range(n)]
    for names in friends_list:
        person1 = names[0]
        person2 = names[1]
        i = perso.index(person1)
        j = perso.index(person2)
        tab_friend[i][j] = 1
        tab_friend[j][i] = 1
    return tab_friend, perso

def create_relationship_matrix(tab_friend, perso, max_distance):
    n = len(perso)
    relationship_matrix = [[0] * n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if i == j:
                relationship_matrix[i][j] = 0
            else:
                distance = bffs(tab_friend, perso, perso[i], perso[j])
                if distance != -1 and distance <= max_distance:
                    relationship_matrix[i][j] = distance
                else:
                    relationship_matrix[i][j] = 0

    return relationship_matrix, perso

def links(friends_file, first, second):
    friends_list = read_file_links(friends_file)
    tab_friend, perso = create_tab_friend(friends_list)
    is_friend(tab_friend, perso, first, second)
