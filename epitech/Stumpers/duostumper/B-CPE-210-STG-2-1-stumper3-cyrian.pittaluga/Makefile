##
## EPITECH PROJECT, 2024
## Project Template
## File description:
## Makefile
##

.SILENT:
NAME = gameoflife

CC = gcc

CFLAGS = -Wextra -g

SRC = 	SRC/main/main.c \
	SRC/opening_file/opening_file.c \
	SRC/syntax_checks/check_map_characters.c \
	SRC/syntax_checks/check_map_format.c \
	SRC/output_handling/print_map.c \
	SRC/free/free_list.c \
	SRC/neighbor/get_neighbor_nbr.c \
	SRC/cells/cells_handling.c \
	lib_funcs/my_atoi.c \
	lib_funcs/my_isdigit.c \
	lib_funcs/my_isalpha.c \
	lib_funcs/my_isin.c \
	lib_funcs/my_putchar.c \
	lib_funcs/my_putstr.c \
	lib_funcs/my_puterror.c \
	lib_funcs/my_strcat.c \
	lib_funcs/my_strchr.c \
	lib_funcs/my_strcmp.c \
	lib_funcs/my_strcpy.c \
	lib_funcs/my_strcspn.c \
	lib_funcs/my_strdup.c \
	lib_funcs/my_strlen.c \
	lib_funcs/my_strncmp.c \
	lib_funcs/my_putnbr.c \
	lib_funcs/my_strndup.c \
	lib_funcs/my_isspace.c \
	lib_funcs/count_char.c \
	lib_funcs/my_strncpy.c \
	lib_funcs/my_str_to_word_array.c \

OBJ = $(SRC:.c=.o)

-include $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~

re: fclean all clean

.PHONY: clean fclean re
