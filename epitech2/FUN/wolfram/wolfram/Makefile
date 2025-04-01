##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

.SILENT:

BUILD_DIR = .stack-work/dist/x86_64-linux-tinfo6/ghc-9.8.4/build/wolfram
EXECUTABLE_NAME = wolfram

build:
	@stack build
	@cp $(BUILD_DIR)/$(EXECUTABLE_NAME) ./$(EXECUTABLE_NAME)

all: build

clean:
	@stack clean

fclean: clean
	@rm -f ./$(EXECUTABLE_NAME)

re: fclean all

.PHONY: build all clean fclean re
