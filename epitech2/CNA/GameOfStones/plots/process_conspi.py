#!/usr/bin/env python3

##
## EPITECH PROJECT, 2025
## Game_Of_Stone
## File description:
## process_conspiracies
##

from collections import deque
from .read_file_plots import read_file_plots
from links.read_file_links import read_file_links
from .prints_plots import print_names
from .prints_plots import print_relationships
from .prints_plots import print_result
from links.links import create_relationship_matrix
from error_handling import print_error
import os
from links.links import create_tab_friend
from links.bffs import bffs

def is_conspired_by_defender(target, defenders, conspiracies, max_distance, current_distance=1, path=None, visited=None):
    if path is None:
        path = [target]
    if visited is None:
        visited = set()
    for conspiracy in conspiracies:
        if conspiracy[1] == target and conspiracy[0] not in visited:
            new_path = [conspiracy[0]] + path  # Préfixe le conspirateur
            new_visited = visited | {conspiracy[0], conspiracy[1]}
            if conspiracy[0] in defenders:
                return True, new_path
            result, found_path = is_conspired_by_defender(
                conspiracy[0], defenders, conspiracies, max_distance,
                current_distance + 1, new_path, new_visited
            )
            if result:
                return True, found_path
    return False, path

def limit_path(path, friends_queen, saves, max_distance):
    while len(path) > 2:
        print("enter:" , path)
        found = False
        print("friends: ", friends_queen)
        for friend in friends_queen:
            print("friend", friend)
            if max_distance == 1 and path[0] == friend:
                print("remove: ", path[0])
                path.pop(0)
                saves.append(friend)
                friends_queen.remove(friend)
                found = True
                break
            if path[1] == friend:
                print("remove: ", path[0])
                if path[0] in friends_queen:
                    print("remove1111: ", path[0])
                    friends_queen.remove(path[0])
                saves.append(path[0])
                path.pop(0)
                found = True
                break
            print("not remove: ", path[0])
            if path[0] in saves and path[1] == friend:
                print("remove2222: ", path[0])
                path.pop(0)
                found = True
        if not found:
            break
    return path

def process_conspiracies(friends_file, plots_file, max_distance):
    if not os.path.exists(friends_file) or not os.path.exists(plots_file):
        print_error("File not found.")
        exit(84)

    try:
        friendships = read_file_links(friends_file)
        conspiracies = read_file_plots(plots_file)
    except Exception as e:
        print_error(f"Error reading file: {e}")
        exit(84)

    names = list(set([item for sublist in friendships + conspiracies for item in sublist]))
    names.sort()
    print_names(names)

    friend_matrix = [[0 for _ in range(len(names))] for _ in range(len(names))]
    for friend_pair in friendships:
        i = names.index(friend_pair[0])
        j = names.index(friend_pair[1])
        friend_matrix[i][j] = 1
        friend_matrix[j][i] = 1

    friend_matrix, names = create_relationship_matrix(friend_matrix, names, max_distance)
    print_relationships(friend_matrix, names)

    print("Conspiracies:")
    cersei = "Cersei Lannister"
    attackers_of_cersei = [conspiracy[0] for conspiracy in conspiracies if conspiracy[1] == cersei]

    cersei_index = names.index(cersei)

    defenders = []
    for i in range(len(names)):
        if friend_matrix[cersei_index][i] == 1 and i != cersei_index:
            defenders.append(names[i])

    friends_queen = []
    for i in range(len(names)):
        if friend_matrix[cersei_index][i] <= max_distance and friend_matrix[cersei_index][i] > 0 and i != cersei_index:
            friends_queen.append(names[i])

    is_safe = True
    attackers_of_cersei.sort()
    defenders.sort()

    all_paths = []

    for attacker in attackers_of_cersei:
        available_defenders = defenders[:]

        is_conspired, path = is_conspired_by_defender(attacker, available_defenders, conspiracies, max_distance)
        if is_conspired:
            all_paths.append(path)

    all_paths.sort(key=len)

    final = []
    saves = []
    for i in range(len(all_paths)):
        if len(all_paths[i]) == 2:
            final.append(all_paths[i])
        else:
            final.append(limit_path(all_paths[i], friends_queen, saves, max_distance))
    
    final.sort()
    for i in range(len(final)):
        tab_friend, perso = create_tab_friend(friendships)
        if bffs(tab_friend, perso, final[i][0], "Cersei Lannister") > max_distance:
            print(f"No conspiracy possible against {final[i][-1]}")
            is_safe = False
        else:
            print(" -> ".join(final[i]))

    if is_safe:
        print_result(0)
    else:
        print_result(1)