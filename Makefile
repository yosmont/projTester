##
## EPITECH PROJECT, 2018
## yet another Makefile
## File description:
## not a copy of a exemple Makefile... not at all
##

NAME	=	projTester

SRC	=	src/main.c			\
		src/getoptprog.c		\
		src/pathlist.c			\
		src/searchbin.c			\
		src/list/destroy_list.c		\
		src/list/listsize.c		\
		src/list/my_put_in_list.c	\
		src/list/my_rev_list.c		\
		src/lib.c			\
		src/testlist.c			\
		src/print.c			\
		src/test.c			\
		src/gnl_redux.c			\
		src/strtowordtab.c		\
		src/free.c			\
		src/test_two.c

CFLAGS	+=	-Wall -Wextra -Iinclude/

DFLAG	+=	-g

OBJ	=	$(SRC:.c=.o)

all:		$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)
	@echo "┌─┐┌┐┌┌┬┐  ┌─┐┌─┐┌┬┐┌─┐┬┬  ┬┌┐┌┌─┐   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  │  │ ││││├─┘││  │││││ ┬   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  └─┘└─┘┴ ┴┴  ┴┴─┘┴┘└┘└─┘┘   ┴ ┴ ┴┴ ┴o"

clean:
	rm -f $(OBJ)
	@echo "┌─┐┌┐┌┌┬┐  ┌─┐┬  ┌─┐┌─┐┌┐┌   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  │  │  ├┤ ├─┤│││   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  └─┘┴─┘└─┘┴ ┴┘└┘┘   ┴ ┴ ┴┴ ┴o"

fclean:		clean
	rm -f $(NAME)
	@echo "┌─┐┌┐┌┌┬┐  ┌─┐┌─┐┬  ┌─┐┌─┐┌┐┌   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  ├┤ │  │  ├┤ ├─┤│││   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  └  └─┘┴─┘└─┘┴ ┴┘└┘┘   ┴ ┴ ┴┴ ┴o"

re:		fclean all
	@echo "┌─┐┌┐┌┌┬┐  ┬─┐┌─┐   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  ├┬┘├┤    └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  ┴└─└─┘┘   ┴ ┴ ┴┴ ┴o"

tests_run:
	make -C tests
	./tests/tests
	@echo "┌─┐┌┐┌┌┬┐  ┬─┐┬ ┬┌┐┌┌┐┌┬┌┐┌┌─┐  ┌┬┐┌─┐┌─┐┌┬┐  ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  ├┬┘│ ││││││││││││ ┬   │ ├┤ └─┐ │   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  ┴└─└─┘┘└┘┘└┘┴┘└┘└─┘   ┴ └─┘└─┘ ┴┘   ┴ ┴ ┴┴ ┴o"

bonus:
	cd bonus; make; make clean
	cp bonus/projTester_bonus projTester_bonus
	@echo "┌─┐┌┐┌┌┬┐ ┌─┐┌─┐┌┬┐┌─┐┬┬  ┬┌┐┌┌─┐  ┌┐ ┌─┐┌┐┌┬ ┬┌─┐   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││ │  │ ││││├─┘││  │││││ ┬  ├┴┐│ │││││ │└─┐   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘ └─┘└─┘┴ ┴┴  ┴┴─┘┴┘└┘└─┘  └─┘└─┘┘└┘└─┘└─┘┘   ┴ ┴ ┴┴ ┴o"

.PHONY: 	all clean fclean re bonus tests_run
