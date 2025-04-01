##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

NAME	= cat

SRC	= cat.c

OBJ	= $(SRC:.c=.o)

LIB	= -L ../lib/ -lmy

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
