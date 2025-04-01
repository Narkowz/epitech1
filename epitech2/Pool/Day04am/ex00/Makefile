##
## EPITECH PROJECT, 2025
## Day04am
## File description:
## Makefile
##

.SILENT:

SRC =	./z.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	z

all:	$(NAME)

$(NAME):
	@gcc -o $(NAME) $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f coding-style-reports.log
	@rm -f vgcore.*

re: fclean all

.PHONY : all clean re fclean
