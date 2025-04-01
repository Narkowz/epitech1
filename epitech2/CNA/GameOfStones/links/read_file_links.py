#!/usr/bin/env python3

##
## EPITECH PROJECT, 2025
## Game_Of_Stone
## File description:
## read_file
##

import os
from error_handling import print_error

def read_file_links(file_path):
    if not os.path.exists(file_path):
        print_error("File does not exist: " + file_path)
        exit(84)
    name_list = []
    if open(file_path, 'r').read() == '':
        print_error("Empty file: " + file_path)
        exit(84)
    with open(file_path, 'r') as file:
        for line in file:
            tokens = line.strip().split(" is friends with ")
            if len(tokens) != 2:
                print_error("Invalid file format: " + file_path)
                exit(84)
            name_list.append(tokens)
    return name_list
