##
## EPITECH PROJECT, 2023
## makefile
## File description:
## idk
##

SRC 	=	my_compute_power_rec.c	\
		my_compute_square_root.c\
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_revstr.c	\
		my_showmem.c	\
		my_showstr.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c 	\
		my_strcmp.c 	\
		my_strcpy.c	\
		my_str_isalpha.c\
		my_str_islower.c\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c 	\
		my_strncmp.c 	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_swap.c	\
		fct_lower_e.c	\
		fct_lower_f.c	\
		fct_multiple_cns.c	\
		fct_lower_pdisc.c	\
		fct_lower_uo.c	\
		fct_lower_x.c	\
		fct_upper_e.c	\
		fct_upper_f.c	\
		fct_upper_x.c	\
		fct_lower_p.c	\
		fct_fake_fe.c	\
		fct_lower_g.c	\
		fct_upper_g.c	\
		fct_fake_fe_bis.c	\
		my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

unit_tests: re
	gcc $(TEST) $(SRC) -o unit_test --coverage -lcriterion

tests_run: unit_tests
	./unit_test

coverage: tests_run
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
	rm unit_test*

auteur:
	echo $(USER) > auteur
