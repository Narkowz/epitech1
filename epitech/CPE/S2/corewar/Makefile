##
## EPITECH PROJECT, 2023
## makefile
## File description:
## idk
##

.SILENT :

SRC 	=	./projects/main.c	\
			./projects/print_h.c	\

NAME	=	corewar

OBJ	=	${SRC:.c=.o}

all:	lib $(NAME)
	echo "\033[0;32m[Successfully compiled]\033[0m"

lib:
	bash -c "cd my/ && make && cd .."

$(NAME):
	gcc -o $(NAME) $(SRC) -L./my -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	bash -c "cd my/ && make fclean && cd .."

re:	fclean all
	bash -c "cd my/ && make fclean all && cd .."

auteur:
	echo $(USER) > auteur

.PHONY : all clean re lib fclean auteur
