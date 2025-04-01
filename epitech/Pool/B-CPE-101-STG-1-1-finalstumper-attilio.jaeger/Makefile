##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Day10
##

SRC	=	main.c \
		printing_function.c \
		my_put_nbr.c \
		my_putchar.c \
		my_putstr.c \
		recognising_char.c \
		my_strlen.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS +=

NAME	=	rush3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
