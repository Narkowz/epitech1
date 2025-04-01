##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC =   main.c 							\
		add.c 							\
		disp.c 							\
		del.c 							\
		sort.c 							\
		lib/my/my_strdup.c 				\
		lib/my/my_strcmp.c 				\
		lib/my/get_nbr.c 				\
		lib/my/sort_id.c 				\
		lib/my/sort_name.c 				\
		lib/my/sort_type.c 				\
		lib/my/sort_by_reverse.c 			\
		lib/mini_printf/mini_printf.c 	\
		lib/mini_printf/my_putchar.c 	\
		lib/mini_printf/my_putstr.c 	\
		lib/mini_printf/my_put_nbr.c 	\

OBJ =   $(SRC:.c=.o)

NAME    =   organized

all:    $(NAME)

$(NAME):
	gcc -o $(NAME) -g $(SRC) -Lshell -lshell

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.g*
	rm -f unit_tests
	rm -f vgcore.*
	rm -f coding-style-reports.log
	rm -f info_file

re:	fclean all

unit:
	gcc $(UNI) -o unit_tests tests/unit_tests.c --coverage -lcriterion
	./unit_tests

cover:
	gcovr --exclude tests

branches:
	gcovr --exclude tests --branches
