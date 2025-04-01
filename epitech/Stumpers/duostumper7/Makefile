##
## EPITECH PROJECT, 2024
## MAKEFILE
## File description:
## Makefile
##

.SILENT:

SRC	=	src/my_isalpha.c            \
		src/my_isnum.c              \
		src/my_str_to_word_array.c  \
		src/add_word_to_string.c    \
		src/handle_error.c          \
		src/main.c

CFLAGS = -I./include -g

OBJ	=	$(SRC:.c=.o)

NAME	= crocus

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
