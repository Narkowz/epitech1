##
## EPITECH PROJECT, 2024
## TEMPLATE
## File description:
## Makefile
##

SRC     =	main.c \
		gest_error.c	\
		opening_file.c \
		my_str_to_word_array.c \

OBJ     =   $(SRC:.c=.o)

NAME    =	mixword

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
