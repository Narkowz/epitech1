##
## EPITECH PROJECT, 2025
## Day02
## File description:
## Makefile
##

EXECUTABLE = pushswap_checker

SOURCES = pushswapChecker.hs operation.hs

GHC = ghc

# GHC_FLAGS = -Wall -O2

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(GHC) $(GHC_FLAGS) -o $(EXECUTABLE) $(SOURCES)

clean:
	rm -f *.hi *.o

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re