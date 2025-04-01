## ----------------------------------------------------------------------------------- ##
##                                                                                     ##
## EPITECH PROJECT - Sun, Feb, 2025                                                    ##
## Title           - cmake-sfml-project                                                ##
## Description     -                                                                   ##
##     Makefile                                                                        ##
##                                                                                     ##
## ----------------------------------------------------------------------------------- ##
##                                                                                     ##
##             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                    ##
##             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                    ##
##             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                    ##
##             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                    ##
##             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                    ##
##             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                    ##
##                                                                                     ##
## ----------------------------------------------------------------------------------- ##

all:
	@echo "Building project..."
	@cmake -B build
	@cmake --build build
	@cp build/bin/MyGKrellm .
	@echo "Project built successfully."

clean:
	@echo "Cleaning project..."
	@rm -rf build
	@echo "Project cleaned successfully."


fclean: clean
	@echo "Removing project..."
	@rm -rf MyGKrellm
	@echo "Project removed successfully."

re: fclean all
