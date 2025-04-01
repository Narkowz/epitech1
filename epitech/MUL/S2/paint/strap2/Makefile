##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for printf
##

SRC =   main.c			\

NAME    =   my_paint

all:    $(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) -g $(SRC) -lcsfml-window -lcsfml-graphics \
	 -lcsfml-system -lcsfml-audio -lm

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f *.g*
	@rm -f vgcore.*
	@rm -f coding-style-reports.log
	@rm -f unit_tests
	@rm -f info_file

re:	fclean all

unit:
	gcc $(UNI) -o unit_tests tests/unit_tests.c --coverage -lcriterion
	./unit_tests

cover:
	gcovr --exclude tests

branches:
	gcovr --exclude tests --branches
