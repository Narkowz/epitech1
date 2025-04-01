##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for printf
##

SRC =   mini_printf/mini_printf.c		\
		mini_printf/my_putchar.c		\
		mini_printf/my_putnbr.c			\
		mini_printf/my_putstr.c			\
		mini_printf/my_strlen.c			\
		mini_printf/add_word_to_string.c\
		mini_printf/my_strncmp.c		\
		mini_printf/my_strcpy.c			\
		mini_printf/my_strdup.c			\
		my_paint.c						\
		src/print_usage.c				\
		src/start_paint.c				\
		src/handle_event.c				\
		src/free_everything.c			\
		src/init_gui.c					\
		src/create_screenshot.c			\
		src/tool_functions.c			\
		src/hover_functions.c			\
		src/menu/file/hover_file_functions.c		\
		src/menu/edit/hover_edit_functions.c		\
		src/menu/help/hover_help_functions.c		\
		src/click_functions.c			\
		src/menu/file/init_file_menu.c			\
		src/menu/edit/init_edit_menu.c			\
		src/menu/help/init_help_menu.c			\
		src/draw_everything.c			\
		src/menu/file/click_file_functions.c		\
		src/menu/edit/click_edit_functions.c		\
		src/menu/help/click_help_functions.c		\
		src/menu/help/init_aled_text.c				\

NAME    =   my_paint

all:    $(NAME)

$(NAME):	$(SRC)
	@gcc -o $(NAME) -g $(SRC) -lcsfml-window -lcsfml-graphics \
	 -lcsfml-system -lcsfml-audio -lm

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f *.g*
	@rm -f vgcore.*
	@rm -f coding-style-reports.log
	@rm -f unit_tests
	@rm -f info_file

re:	fclean all

unit:
	gcc $(UNI) -o unit_tests tests/unit_tests.c --coverage -lcriterion
	./unit_tests

cover:
	gcovr --exclude tests

branches:
	gcovr --exclude tests --branches
