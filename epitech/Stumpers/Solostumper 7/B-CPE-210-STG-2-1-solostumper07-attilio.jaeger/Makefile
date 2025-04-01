##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

.SILENT:

SRC	=	main.c			\
		lib/my/my_strlen.c	\


OBJ	=	$(SRC:.c=.o)

NAME	= anagram

all:	$(NAME)

$(NAME):
	@gcc -o $(NAME) -g $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f coding-style-reports.log

re:	fclean all

rebuild:
	@make -C lib/ re
