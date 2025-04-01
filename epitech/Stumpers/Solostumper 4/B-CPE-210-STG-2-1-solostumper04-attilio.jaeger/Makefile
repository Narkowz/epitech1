##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

.SILENT:

SRC	=	lib/my/my_strlen.c					\
		start_program.c						\

OBJ	=	$(SRC:.c=.o)

NAME	=	geekNameFormatter

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc libmy.a $(OBJ)
	@gcc -o $(NAME) -g geekNameFormatter.c -L. -lmy

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f libmy.a
	@rm -f $(NAME)
	@rm -f *~
	@rm -f coding-style-reports.log

re:	fclean all
