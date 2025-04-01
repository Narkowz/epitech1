##
## EPITECH PROJECT, 2022
## Documents
## File description:
## Makefile
##

SRC	=	src/main.c 					\
		src/print_usage.c 			\
		src/test_file.c				\
		src/translate_to_cor.c 		\
		src/add_to_file.c			\
		src/my_str_bis.c			\
		src/parse_parameters.c		\
		src/op.c					\
		src/binary_to_int.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

all:	$(NAME)

$(NAME):
	@make --no-print-directory -C lib/ all
	@gcc -o $(NAME) $(SRC) -g -L. -lmy

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f coding-style-reports.log
	@rm -f vgcore.*

re: fclean all

rebuild:
	@make --no-print-directory -C lib/ re

allclean: fclean
	@make --no-print-directory -C lib/ fclean

cs:
	@make --no-print-directory fclean
	@make --no-print-directory -C lib/ fclean
	@coding-style . .
	@cat coding-style-reports.log
	@rm -f coding-style-reports.log

SILENT. :
