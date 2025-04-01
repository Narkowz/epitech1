##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

.SILENT:

SRC	=	minishell.c 						\
		shell.c 							\
		command_input.c						\
		handle_environment.c				\
		handle_args.c						\
		basic_tests_command.c 				\
		path_to_array.c						\
		add_to_environment.c				\
		add_word.c							\
		handle_segfault.c					\

CFLAGS = -g

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	@make --no-print-directory -C lib/ all
	@gcc -o $(NAME) $(OBJ) -g -L. -lmy

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f vgcore.*
	@rm -f coding-style-reports.log

re:	fclean all

rebuild:
	make --no-print-directory -C lib/ re

allclean:
	make --no-print-directory fclean
	make --no-print-directory -C lib/ fclean

cs:
	make --no-print-directory fclean
	make --no-print-directory -C lib/ fclean
	coding-style . .
	cat coding-style-reports.log
	rm -f coding-style-reports.log
