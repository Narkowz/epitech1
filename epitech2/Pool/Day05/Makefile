##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

.SILENT:

SRC	=	string_init.c	\
		assign.c \
		append.c \
		at.c \
		clear.c \
		length.c \
		compare.c \
		copy.c \
		c_str.c \
		empty.c \
		find.c \
		insert.c \
		to_int.c \
		split.c \
		print.c \
		join.c \
		substr.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libstring.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re:	fclean all
