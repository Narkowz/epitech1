##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for printf
##

.SILENT:

LIB_DIR =   ./lib/my

SRC = 	my_printf/my_printf.c					\
		my_printf/print_a_printf.c				\
		my_printf/print_g_printf.c				\
        my_printf/my_putnbr_printf.c			\
		my_printf/my_putstr_printf.c			\
        my_printf/my_strlen_printf.c			\
        my_printf/print_int_printf.c			\
		my_printf/my_putchar_printf.c			\
        my_printf/print_char_printf.c			\
        my_printf/print_hexa_printf.c			\
        my_printf/print_octal_printf.c			\
        my_printf/print_float_printf.c			\
		my_printf/print_sub_x_printf.c			\
		my_printf/print_binary_printf.c			\
        my_printf/print_hexaup_printf.c			\
        my_printf/print_string_printf.c			\
		my_printf/print_percent_printf.c		\
		my_printf/print_floatup_printf.c		\
        my_printf/print_pointer_printf.c		\
        my_printf/print_unsigned_printf.c		\
		my_printf/print_scientifup_printf.c		\
		my_printf/print_scientific_printf.c		\
		my/my_compute_power_rec.c		\
		my/my_compute_square_root.c		\
		my/my_find_prime_sup.c			\
		my/my_getnbr.c					\
		my/my_is_isupper.c				\
		my/my_isneg.c					\
		my/my_is_prime.c				\
		my/my_putchar.c					\
		my/my_putnbr.c					\
		my/my_putstr.c					\
		my/my_revstr.c					\
		my/my_showmem.c					\
		my/my_showstr.c					\
		my/my_sort_int_array.c			\
		my/my_strcapitalize.c			\
		my/my_strcmp.c					\
		my/my_strcpy.c					\
		my/my_str_isalpha.c				\
		my/my_str_islower.c				\
		my/my_str_isnum.c				\
		my/my_str_isprintable.c			\
		my/my_strlen.c					\
		my/my_strlowcase.c				\
		my/my_strncat.c					\
		my/my_strncmp.c					\
		my/my_strncpy.c					\
		my/my_strstr.c					\
		my/my_strupcase.c				\
		my/my_swap.c					\
		my/my_strdup.c					\
		my/my_str_to_word_array.c		\
		my/add_word_to_string.c			\
		my/int_to_char.c				\

OBJ =   $(SRC:.c=.o)

NAME    =   libmy.a

all:    $(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@mv $(NAME) ..

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f ../libmy.a
	@rm -f $(NAME)
	@rm -f *~
	@rm -f coding-style-reports.log

re:	fclean all
