##
## EPITECH PROJECT, 2025
## arcade
## File description:
## Makefile
##

.SILENT:

SRC = $(wildcard src/core/*.cpp) $(wildcard src/core/*/*.cpp)

# All the o in a build to be cleaner
OBJ = $(SRC:src/%.cpp=build/%.o)

HEADERS := $(wildcard src/**/*.hpp)
INCLUDE := $(foreach dir, $(sort $(dir $(HEADERS))), -I$(dir))

CPPFLAGS += -Wall -Wextra -Werror -std=c++17 -g $(INCLUDE)

NAME = arcade

all: core games graphicals
	printf "[%s] - Successfully compiled\n" $(NAME)

$(NAME): $(OBJ)
	g++ $(CPPFLAGS) -o $(NAME) $(OBJ)

core: $(NAME)
	printf "[%s] - Build core\n" $(NAME)

GAMESMAKEFILES := $(wildcard src/game/*/Makefile)
games:
	for makefile in $(GAMESMAKEFILES); do \
		$(MAKE) -f $$makefile --no-print-directory; \
		if [ $$? -ne 0 ]; then \
			exit 1; \
		fi; \
	done; \
	printf "[%s] - Build games\n" $(NAME)

LIBMAKEFILES := $(wildcard src/graphical/*/Makefile)
graphicals:
	for makefile in $(LIBMAKEFILES); do \
		$(MAKE) -f $$makefile --no-print-directory; \
		if [ $$? -ne 0 ]; then \
			exit 1; \
		fi; \
	done; \
	printf "[%s] - Build graphicals\n" $(NAME)

build/%.o: src/%.cpp
	mkdir -p $(dir $@)
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf build/

fclean: clean
	rm -rf $(NAME)
	rm -rf build/
	rm -rf lib/*.so

re: fclean
	$(MAKE) --no-print-directory all

debug: CPPFLAGS += -g
debug: re
	printf "[%s] - Debug mode enabled\n" $(NAME)

tests_script: re
	if [ -f ./tests/start_test.sh ]; then \
		clear \
		./tests/start_test.sh; \
	else \
		echo "No tester file in this repo"; \
		exit 0; \
	fi

.PHONY: all clean fclean debug re tests_script games graphicals core
