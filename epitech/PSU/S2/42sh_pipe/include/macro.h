/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-titouan.pradoura
** File description:
** macro.h
*/

#ifndef MACRO_H
    #define MACRO_H


    #define RESET   "\033[0m"
    #define BOLD    "\033[1m"
    #define CYAN    "\033[36m"
    #define GREEN   "\033[32m"
    #define BLUE    "\033[34m"
    #define YELLOW "\033[33m"
    #define RED "\033[31m"
    #define WHITE "\033[00m"
    #define BLACK "\033[30m"
    #define LIGHT_GRAY "\033[37m"
    #define DEFAULT "\033[0m"

    #define LIGHT_GRAY_BG "\033[47;1m"
    #define YELLOW_BG "\033[43m"
    #define BLUE_BG "\033[44m"
    #define DARK_GRAY_BG "\033[100m"
    #define CYAN_BG "\033[46m"
    #define WHITE_BG "\033[47m"
    #define BLACK_BG "\033[30m"

    #define BOLD "\033[1m"
    #define PROMPT YELLOW "$>"  WHITE
    #define EXIT BOLD RED"exit" DEFAULT WHITE

    #define EXIST_EMPTY (cpy->cmd && my_strlen(cpy->cmd) == 0)
    #define EXIST_NEMPTY (cpy->cmd && my_strlen(cpy->cmd) != 0)
    #define ISN_PAR (cpy->sep != 8 && cpy->sep != 9)
    #define ISN_QUOTE (cpy->sep != 7 && cpy->sep != 10)
    #define DOUBLE_SEP (cpy->sep != 0 && ISN_PAR && ISN_QUOTE)
    #define IS_QUOTE (cpy->command->sep == 7 || cpy->command->sep == 10)
    #define IS_DIR (cpy->command->sep == 2 || cpy->command->sep == 4)
    #define IS_PIPE (cpy->command->sep == 1)
    #define NOT_EXIST (!cpy->cmd)
    #define COMMAND shell->parser->command

#endif
