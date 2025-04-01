##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

.SILENT:

SRC	=	


OBJ	=	$(SRC:.c=.o)

NAME	=

all:	$(NAME)

$(NAME):	
	@make -C lib/ all
	@gcc -o $(NAME) -g $(OBJ) -L. -lmy

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f coding-style-reports.log

re:	fclean all

rebuild: 
	@make -C lib/ re
