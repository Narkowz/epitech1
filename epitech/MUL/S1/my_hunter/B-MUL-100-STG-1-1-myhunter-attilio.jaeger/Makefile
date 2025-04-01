##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for printf
##

SRC =   create_window.c				\
		game.c						\
		handle_event.c				\
		my_hunter.c					\
		int_to_char.c				\
		my_strdup.c					\
		main.c						\
		help_flag.c					\
		mini_printf/mini_printf.c	\
		mini_printf/my_putchar.c	\
		mini_printf/my_putstr.c		\

NAME    =   my_hunter

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) -g $(SRC) -lcsfml-window -lcsfml-graphics \
	 -lcsfml-system -lcsfml-audio

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.g*
	rm -f my_ls
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
