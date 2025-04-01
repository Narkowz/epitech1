##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

.SILENT:

SRC	=	main.c		\

CFLAGS = -g

OBJ	=	$(SRC:.c=.o)

NAME	=	test

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) -g

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f vgcore.*
	@rm -f coding-style-reports.log

re:	fclean all

tests_run:
	@gcc -o testou tests/unit_tests.c --coverage -lcriterion