#!/usr/bin/env python3

##
## EPITECH PROJECT, 2025
## Game_Of_Stone
## File description:
## error_handling
##

from sys import argv
import sys
from print_helper import print_helper

def print_error(message):
    print(message, file=sys.stderr)

def error_handling():
    if len(argv) < 2:
        print_helper()
    if argv[1] == "--plots":
        if len(argv) != 5:
            print_error("Invalid number of arguments")
            exit(84)
    elif argv[1] == "--links":
        if len(argv) != 5:
            print_error("Invalid number of arguments")
            exit(84)
    else:
        print_helper()