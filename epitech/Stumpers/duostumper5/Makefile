##
## EPITECH PROJECT, 2024
## TEMPLATE
## File description:
## Makefile
##

SRC     =	main.c \
		SRC/opening_file.c \
		SRC/my_str_to_word_array.c \
		SRC/print_header.c \
		SRC/game_loop.c \

OBJ     =   $(SRC:.c=.o)

NAME    =	lingo

all:    $(NAME)

$(NAME):    $(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)
		rm -f *~

fclean: clean
		rm -f $(NAME)

re:		fclean all clean

.PHONY: all clean fclean re
