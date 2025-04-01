##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for printf
##

LIB_DIR =   ./lib/my

SRC =   lib/my/my_simple_ls.c			\
		lib/my/bubble_sort.c			\
		lib/my/error_handling.c			\
		lib/my/my_strcmp.c				\
		lib/my/my_strdup.c				\
		lib/my/my_strncmp.c				\
		lib/my/find_flags.c				\
		lib/my/sort_by_reverse.c		\
		lib/my/bubble_sort_bis.c		\
		lib/my/print_list.c				\
		lib/my/print_a.c				\
		lib/mini_printf/mini_printf.c	\
		lib/mini_printf/my_put_nbr.c	\
		lib/mini_printf/my_putstr.c		\
		lib/mini_printf/my_putchar.c 	\

OBJ =   $(SRC:.c=.o)

NAME    =   libmy.a

all:    $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o my_ls main.c -L. -lmy

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
