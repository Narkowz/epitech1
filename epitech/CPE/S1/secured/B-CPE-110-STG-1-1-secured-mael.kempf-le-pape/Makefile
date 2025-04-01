##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Makefile
##

SRC	=	main.c					\
		ht_dump.c				\
		ht_delete.c				\
		ht_insert.c				\
		ht_search.c				\
		new_hashtable.c 		\
		my_strdup.c 			\
		my_strlen.c				\
		my_strcmp.c				\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g

NAME	=	secured

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc libhashtable.a $(OBJ)
	@gcc -o $(NAME) -g -L. -lhashtable

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f libhashtable.a
	@rm -f $(NAME)
	@rm -f *~
	@rm -f vgcore.*
	@rm -f coding-style-reports.log

re:	fclean all

.SILENT:
