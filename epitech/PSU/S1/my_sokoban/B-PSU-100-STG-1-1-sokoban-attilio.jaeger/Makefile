##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile my_sokoban
##

SRC =   main2.c 						\
		lib/my/my_strlen.c 				\
		lib/my/my_strdup.c 				\
		opening_file.c 					\
		movements.c 					\
		check_win.c						\
		error_handling.c				\
		count_line.c					\
		reset.c							\
		my_sokoban.c 					\
		display_usage.c					\
		lib/mini_printf/mini_printf.c	\
		lib/mini_printf/my_putchar.c	\
		lib/mini_printf/my_put_nbr.c	\
		lib/mini_printf/my_putstr.c		\
		check_loose.c					\

OBJ =   $(SRC:.c=.o)

NAME    =   my_sokoban

all:    $(NAME)

$(NAME):
	gcc -o $(NAME) -g $(SRC) -lncurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.g*
	rm -f unit_tests
	rm -f info_file

re:	fclean all

unit:
	gcc $(UNI) -o unit_tests tests/unit_tests.c --coverage -lcriterion
	./unit_tests

cover:
	gcovr --exclude tests

branches:
	gcovr --exclude tests --branches
