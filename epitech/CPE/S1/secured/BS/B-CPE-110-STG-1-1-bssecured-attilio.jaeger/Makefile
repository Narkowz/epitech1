##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC =   main.c 					\

NAME    =   secured

all:    $(NAME)

$(NAME):
	@gcc -o $(NAME) -g $(SRC)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f *.g*
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
