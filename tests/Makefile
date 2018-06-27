##
## EPITECH PROJECT, 2018
## palindrome
## File description:
## Makefile for units tests
##

NAME	=	tests

RM	=	rm -f

CC	=	gcc

SRC	=	../src/getoptprog.c		\
		../src/pathlist.c		\
		../src/searchbin.c		\
		../src/list/destroy_list.c	\
		../src/list/listsize.c		\
		../src/list/my_put_in_list.c	\
		../src/list/my_rev_list.c	\
		../src/lib.c			\
		../src/testlist.c		\
		../src/print.c				\
		../src/test.c				\
		../src/gnl_redux.c		\
		../src/strtowordtab.c		\
		../src/free.c			\
		../src/test_two.c		\
		basic_my.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I ../include/ --coverage

LDFLAGS	+=	-lcriterion

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
		@echo "┌─┐┌┐┌┌┬┐  ┌─┐┌─┐┌┬┐┌─┐┬┬  ┬┌┐┌┌─┐   ┬ ┬┌─┐┌┬┐┬"
		@echo "├┤ │││ ││  │  │ ││││├─┘││  │││││ ┬   └┬┘├─┤││││"
		@echo "└─┘┘└┘─┴┘  └─┘└─┘┴ ┴┴  ┴┴─┘┴┘└┘└─┘┘   ┴ ┴ ┴┴ ┴o"

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		rm *.gc*
		rm ../src/*.gc*
		rm ../src/list/*.gc*
		@echo "┌─┐┌┐┌┌┬┐  ┌─┐┬  ┌─┐┌─┐┌┐┌   ┬ ┬┌─┐┌┬┐┬"
		@echo "├┤ │││ ││  │  │  ├┤ ├─┤│││   └┬┘├─┤││││"
		@echo "└─┘┘└┘─┴┘  └─┘┴─┘└─┘┴ ┴┘└┘┘   ┴ ┴ ┴┴ ┴o"

fclean:		clean
		$(RM) $(NAME)
		@echo "┌─┐┌┐┌┌┬┐  ┌─┐┌─┐┬  ┌─┐┌─┐┌┐┌   ┬ ┬┌─┐┌┬┐┬"
		@echo "├┤ │││ ││  ├┤ │  │  ├┤ ├─┤│││   └┬┘├─┤││││"
		@echo "└─┘┘└┘─┴┘  └  └─┘┴─┘└─┘┴ ┴┘└┘┘   ┴ ┴ ┴┴ ┴o"

re:		fclean all
		@echo "┌─┐┌┐┌┌┬┐  ┬─┐┌─┐   ┬ ┬┌─┐┌┬┐┬"
		@echo "├┤ │││ ││  ├┬┘├┤    └┬┘├─┤││││"
		@echo "└─┘┘└┘─┴┘  ┴└─└─┘┘   ┴ ┴ ┴┴ ┴o"

.PHONY:		all clean fclean re
