##
## EPITECH PROJECT, 2025
## arcade
## File description:
## Makefile
##

.SILENT:

FOLDER = src/game/flappy
BUILDFOLDER = build/game/flappy

SRC =	$(wildcard ${FOLDER}/*.cpp) \
		$(wildcard ${FOLDER}/*/*.cpp) \

OBJ = $(SRC:${FOLDER}/%.cpp=${BUILDFOLDER}/%.o)

HEADERS := $(wildcard src/**/*.hpp)
INCLUDE := $(foreach dir, $(sort $(dir $(HEADERS))), -I$(dir))

NAME = lib/arcade_flappy.so

CPPFLAGS += -Wall -Wextra -Werror -std=c++17 $(INCLUDE)

$(NAME): $(OBJ)
	g++ -shared -fPIC -o $(NAME) $(OBJ) $(CPPFLAGS)
	printf "[%s] - Successfully created shared library\n" $(NAME)

${BUILDFOLDER}/%.o: ${FOLDER}/%.cpp
	mkdir -p $(dir $@)
	g++ -c -fPIC $(CPPFLAGS) $< -o $@

all: $(NAME)

clean:
	rm -rf build/

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: CPPFLAGS += -g
debug: re
	printf "[%s] - Debug mode enabled\n" $(NAME)

.PHONY: all clean fclean debug re
