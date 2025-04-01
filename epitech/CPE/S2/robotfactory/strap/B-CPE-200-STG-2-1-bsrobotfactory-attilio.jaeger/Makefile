##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Makefile
##

SRC	=	part1/step1/write_some_text.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g

NAME	=	secured

all:	$(NAME)

$(NAME):
	@gcc -o write-some-text -g part1/step1/write_some_text.c
	@mv write-some-text part1/step1
	@gcc -o write-a-number-as-text -g part1/step2/write_a_number_as_text.c
	@mv write-a-number-as-text part1/step2
	@gcc -o write-a-number-as-int -g part1/step3/write_a_number_as_int.c
	@mv write-a-number-as-int part1/step3
	@gcc -o without-padding -g part1/step4/step4.c
	@mv without-padding part1/step4
	@gcc -o with-padding -g part1/step5/step5.c
	@mv with-padding part1/step5

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f *.yolo
	@rm -f part1/step1/write-some-text
	@rm -f part1/step2/write-a-number-as-text
	@rm -f part1/step3/write-a-number-as-int
	@rm -f part1/step4/without-padding
	@rm -f part1/step5/with-padding
	@rm -f $(NAME)
	@rm -f *~
	@rm -f vgcore.*
	@rm -f coding-style-reports.log

re:	fclean all

.SILENT:
