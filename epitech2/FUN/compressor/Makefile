##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

.SILENT:

build:
	@stack build
	@cp `stack path --local-install-root`/bin/imageCompressor .

install:
	@stack install

copy-executable:
	@cp `stack path --local-install-root`/bin/imageCompressor .

all: build copy-executable

clean:
	stack clean

fclean: clean
	@rm -f imageCompressor

re: fclean all

.PHONY: all build install copy-executable clean fclean re