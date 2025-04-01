##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for printf
##

LIB_DIR =   ./lib/my

SRC = 	my_printf.c			\
	lib/my/print_a.c		\
	lib/my/print_g.c		\
        lib/my/my_putnbr.c		\
	lib/my/my_putstr.c		\
        lib/my/my_strlen.c		\
        lib/my/print_int.c		\
	lib/my/my_putchar.c		\
        lib/my/print_char.c		\
        lib/my/print_hexa.c		\
        lib/my/print_octal.c		\
        lib/my/print_float.c		\
	lib/my/print_sub_x.c		\
	lib/my/print_binary.c		\
        lib/my/print_hexaup.c		\
        lib/my/print_string.c		\
	lib/my/print_percent.c		\
	lib/my/print_floatup.c		\
        lib/my/print_pointer.c		\
        lib/my/print_unsigned.c		\
	lib/my/print_scientifup.c	\
	lib/my/print_scientific.c	\

UNI = 	my_printf.c			\
	lib/my/print_a.c		\
	lib/my/print_g.c		\
        lib/my/my_putnbr.c		\
	lib/my/my_putstr.c		\
        lib/my/my_strlen.c		\
        lib/my/print_int.c		\
	lib/my/my_putchar.c		\
        lib/my/print_char.c		\
        lib/my/print_hexa.c		\
        lib/my/print_octal.c		\
        lib/my/print_float.c		\
	lib/my/print_sub_x.c		\
	lib/my/print_binary.c		\
        lib/my/print_hexaup.c		\
        lib/my/print_string.c		\
	lib/my/print_percent.c		\
	lib/my/print_floatup.c		\
        lib/my/print_pointer.c		\
        lib/my/print_unsigned.c		\
	lib/my/print_scientifup.c	\
	lib/my/print_scientific.c	\

OBJ =   $(SRC:.c=.o)

NAME    =   libmy.a

all:    $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm *.g*
	rm unit_tests

re:	fclean all

my_printf:	$(NAME)
	gcc -o my_printf my_printf.c -L. -lmy
	./my_printf

unit:
	gcc $(UNI) -o unit_tests tests/unit_tests.c --coverage -lcriterion
	./unit_tests

cover:
	gcovr --exclude tests

branches:
	gcovr --exclude tests --branches
