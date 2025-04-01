#!/usr/bin/env python3

##
## EPITECH PROJECT, 2025
## Game_Of_Stone
## File description:
## read_file
##

import os
from error_handling import print_error

def read_file_plots(file_path):
    if not os.path.exists(file_path):
        print_error("File does not exist: " + file_path)
        exit(84)

    if os.path.getsize(file_path) == 0:
        print_error("Empty file: " + file_path)
        exit(84)

    conspiracies = []

    with open(file_path, 'r') as file:
        for line in file:
            line = line.strip()
            if not line:
                continue

            tokens = line.split(" is plotting against ")
            if len(tokens) != 2:
                print_error("Invalid file format: " + file_path)
                exit(84)

            attacker, target = tokens
            conspiracies.append((attacker.strip(), target.strip()))

    return conspiracies