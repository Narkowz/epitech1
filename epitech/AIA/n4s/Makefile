##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

.SILENT:

SRC	=	src/main.c	\
		src/turns.c	\
		src/do_turns.c	\
		src/bigger.c	\
		src/count_lines.c	\
		src/end_simu.c	\
		lib/my_str_to_word_array.c	\
		lib/add_word_to_string.c	\
		lib/get_str.c	\
		lib/my_strlen.c	\
		lib/my_strcpy.c	\
		lib/my_strdup.c	\

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
