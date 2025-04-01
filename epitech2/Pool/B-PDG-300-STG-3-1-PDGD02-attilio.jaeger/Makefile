EXECUTABLE = doop

SOURCES = DoOp.hs

HC = ghc

HCFLAGS = -Wall -O2

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	@echo "Compiling $(EXECUTABLE)..."
	$(HC) $(HCFLAGS) -o $(EXECUTABLE) $(SOURCES)

clean:
	@echo "Cleaning temporary files..."
	rm -f *.hi *.o

fclean: clean
	@echo "Removing $(EXECUTABLE)..."
	rm -f $(EXECUTABLE)

re: fclean all