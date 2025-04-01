#!/usr/bin/env python3

##
## EPITECH PROJECT, 2025
## Game_Of_Stone
## File description:
## bffs
##

from collections import deque

def bffs(tab_friend, perso, first, second):
    queue = deque([(first, 0)])
    checked = set([first])
    while queue:
        current, distance = queue.popleft()
        if current == second:
            return distance
        i = perso.index(current)
        for j in range(len(perso)):
            if tab_friend[i][j] == 1 and perso[j] not in checked:
                checked.add(perso[j])
                queue.append((perso[j], distance + 1))
    return -1