#!/usr/bin/env python3

##
## EPITECH PROJECT, 2025
## Game_Of_Stone
## File description:
## prints_plots
##

def print_names(names):
    print("Names:")
    for i in range (len(names)):
        print(names[i])
    print()

def print_relationships(friend_matrix, names):
    print("Relationships:")
    for i in range(len(names)):
        for j in range(len(names)):
            print(friend_matrix[i][j], end=" ")
        print()
    print()

def print_conspiracies(attackers_of_cersei):
    print("Conspiracies:")
    for attacker in attackers_of_cersei:
        print( "->", attacker)
    print()


def print_result(answer):
    print()
    print("Result:")
    if answer == 1:
        print("There is only one way out: treason!")
    if answer == 0:
        print("The stone is safe!")