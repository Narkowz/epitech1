##
## EPITECH PROJECT, 2024
## TEMPLATE
## File description:
## Makefile
##

SRC     =	main.c \
		opening_file.c \

OBJ     =   $(SRC:.c=.o)

NAME    =	cesar

all:    $(NAME)

$(NAME):    $(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all clean

.PHONY: all clean fclean re
