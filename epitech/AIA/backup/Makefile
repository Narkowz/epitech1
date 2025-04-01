##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

.SILENT:

SRC	=	main.c		\
		my_str_to_word_array.c		\
		my_getnbr.c			\

CFLAGS = -g

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f vgcore.*
	@rm -f coding-style-reports.log

re:	fclean all

cs:
	make --no-print-directory fclean
	coding-style . .
	cat coding-style-reports.log
	rm -f coding-style-reports.log
