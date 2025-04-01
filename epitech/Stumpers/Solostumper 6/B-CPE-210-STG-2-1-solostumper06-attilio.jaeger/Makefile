##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

.SILENT:

SRC	=	main.c		\

NAME	= text_to_multi_tap

all:	$(NAME)

$(NAME):
	@gcc -o $(NAME) $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f coding-style-reports.log

re:	fclean all
