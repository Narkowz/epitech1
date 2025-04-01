##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

.Silent:

NAME = libasm.so
NASM = nasm
CC = gcc
LD = ld
CFLAGS = -fPIC -shared
SRC_DIR = src
OBJ_DIR = obj

ASM_FILES = $(wildcard $(SRC_DIR)/*.asm)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.asm, $(OBJ_DIR)/%.o, $(ASM_FILES))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.asm
	@mkdir -p $(OBJ_DIR)
	@$(NASM) -f elf64 $< -o $@

$(NAME): $(OBJ_FILES)
	@$(LD) -shared -o $(NAME) $(OBJ_FILES)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
