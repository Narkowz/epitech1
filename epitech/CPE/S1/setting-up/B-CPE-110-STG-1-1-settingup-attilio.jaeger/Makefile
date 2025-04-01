##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC =   opening_file.c 					\
		put_in_2d_list.c 				\
		setting_up.c 					\
		prepare_square.c 				\
		operating_square.c				\
		find_square.c					\
		lib/mini_printf/mini_printf.c	\
		lib/mini_printf/my_putchar.c	\
		lib/mini_printf/my_put_nbr.c	\
		lib/mini_printf/my_putstr.c		\
		generating_square.c				\
		get_nbr.c						\

OBJ =   $(SRC:.c=.o)

NAME    =   libmy.a

all:    $(NAME)

$(NAME):
	gcc -o setting_up -g $(SRC)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.g*
	rm -f setting_up
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
