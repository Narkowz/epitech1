##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

.SILENT:

SRC	=	MyGKrellm.cpp				\
		src/getCPU/getCore.cpp		\
		src/getCPU/getCPU.cpp		\
		src/getOS/getOS.cpp			\
		src/NcursesDisplay.cpp			\
		displays/*.cpp				\
		modules/*.cpp				\
		# displays/display.cpp		\
		# displays/displaySystem.cpp	\
		# displays/displayCPU.cpp		\

NAME	=	MyGKrellm

all:	$(NAME)

$(NAME):
	@g++ $(SRC) -o $(NAME) -lncurses

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re:	fclean all
