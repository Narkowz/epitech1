##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

.SILENT:

SRC	=	minishell.c 									\
		SRC/commands/shell.c 							\
		SRC/commands/command_input.c					\
		SRC/environment/handle_environment.c			\
		SRC/commands/handle_args.c						\
		SRC/commands/basic_tests_command.c 				\
		SRC/environment/path_to_array.c					\
		SRC/environment/add_to_environment.c			\
		SRC/segfault/handle_segfault.c					\
		SRC/commands/cut_multi_command.c				\
		SRC/pipe/handle_pipe.c							\
		SRC/redirections/handle_redirections.c			\

CFLAGS = -g

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	@make --no-print-directory -C lib/ all
	@gcc -o $(NAME) $(OBJ) -g -L. -lmy
	@mv $(OBJ) OBJ

clean:
	@rm -f $(OBJ)
	@rm -f OBJ/*.o
	@rm -f tmp/temp_db_redirect

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
