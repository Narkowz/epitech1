##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

.SILENT:

SRC	=	main.c		\

NAME	=	maze

all:	$(NAME)

$(NAME):	
	@make -C lib/ all
	@gcc -o $(NAME) -g $(SRC) -L. -lmy

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f coding-style-reports.log

re:	fclean all

rebuild: 
	@make -C lib/ re
