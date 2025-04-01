##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

.SILENT:

SHELL   =   /bin/bash

CPROG   =   $(wildcard src/*/*.c src/*/*/*.c)\
			src/main.c

CBONUS   =   $(wildcard src/*/*.c src/*/*/*.c)\
			bonus/main.c

CLIB    =   $(wildcard lib/my/*.c lib/my/*/*.c)

NAME    =   42sh

LIB     =   libmy.a

OLIB	=	$(CLIB:.c=.o)

OPROG	=	$(CPROG:.c=.o)

OBONUS	=	$(CBONUS:.c=.o)

IFLAGS	=	-I./lib/include/ -I./include/ -I./include/struct/

NCURSES	=	-lncurses

WFLAGS	=	-g -Wall -Wconversion -Wpedantic \
            -Wsign-compare -Wtype-limits -Walloc-zero \
            -Wmissing-field-initializers \
            -Wcast-qual -Wduplicated-branches -Wfloat-equal \
            -Winit-self -Wuninitialized

CFLAGS  += $(IFLAGS) $(NCURSES)

all: $(LIB)

$(LIB): $(OLIB) $(OPROG)
	ar rc $(LIB) $(OLIB)
	bash -c "mv libmy.a lib/libmy.a"
	gcc -o $(NAME) $(OPROG) $(CFLAGS) -L./lib -lmy
	printf "\033[1m\033[32m[%s]\033[0m — Successfully compiled\n" $(NAME)

clean:
	rm -f $(OLIB) $(OPROG)
	rm -f coding-style-reports.log
	rm -f vgcore.*

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)
	rm -f "tester/42sh"
	bash -c "rm -f lib/libmy.a"
	printf "\033[1m\033[32m[%s]\033[0m — Fclean done\n" $(NAME)


re: fclean all

debug: CFLAGS += -g $(WFLAGS)

debug: re
	printf "\033[1m\033[32m[%s]\033[0m — Debug mode enabled\n" $(NAME)

bonus: fclean $(OLIB) $(OBONUS)
	ar rc $(LIB) $(OLIB)
	bash -c "mv libmy.a lib/libmy.a"
	gcc -o $(NAME) $(OBONUS) $(CFLAGS) -L./lib -lmy
	printf "\033[1m\033[32m[%s]\033[0m — Successfully compiled\n" $(NAME)

tests_mysh1: re
	bash -c "cp 42sh tester/42sh"
	bash -c "cp script/.42shrc tester/script/.42shrc"
	printf "\033[1m\033[32m[Starting mysh 1 tests]\033[0m\n"
	bash -c "cd tester; ./tester.sh tests_basic; ./tester.sh tests_builtin"

tests_mysh2: re
	bash -c "cp 42sh tester/42sh"
	bash -c "cp script/.42shrc tester/script/.42shrc"
	printf "\033[1m\033[32m[Starting mysh 2 tests]\033[0m\n"
	bash -c "cd tester; ./tester.sh tests_redirection; ./tester.sh tests_pipe"

tests_42sh: re
	bash -c "cp 42sh tester/42sh"
	bash -c "cp script/.42shrc tester/script/.42shrc"
	printf "\033[1m\033[32m[Starting 42sh tests]\033[0m\n"
	bash -c "cd tester; ./tester.sh tests_parenthesis; ./tester.sh tests_quote"
	bash -c "cd tester; ./tester.sh tests_alias; ./tester.sh tests_operator"
	bash -c "cd tester; ./tester.sh tests_variables"

tests_all: re
	bash -c "cp 42sh tester/42sh"
	bash -c "cp script/.42shrc tester/script/.42shrc"
	printf "\033[1m\033[32m[Starting mysh 1 tests]\033[0m\n"
	bash -c "cd tester; ./tester.sh tests_basic; ./tester.sh tests_builtin"
	printf "\033[1m\033[32m[Starting mysh 2 tests]\033[0m\n"
	bash -c "cd tester; ./tester.sh tests_redirection; ./tester.sh tests_pipe"
	printf "\033[1m\033[32m[Starting 42sh tests]\033[0m\n"
	bash -c "cd tester; ./tester.sh tests_parenthesis; ./tester.sh tests_quote"
	bash -c "cd tester; ./tester.sh tests_alias; ./tester.sh tests_operator"
	bash -c "cd tester; ./tester.sh tests_variables"

.PHONY: all clean fclean re debug tests_all tests_42sh tests_mysh1 \
		tests_mysh2 bonus
