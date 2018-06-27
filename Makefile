##
## EPITECH PROJECT, 2017
## makefile cat
## File description:
## build the cat
##

CC	=	gcc

OBJ	=	src/my_strlen.c	\
		src/my_strdup.c	\
		src/my_tabs_copy.c	\
		src/quit.c	\
		src/check.c	\
		src/init.c	\
		src/move.c	\
		src/display.c	\
		src/gameloop.c	\
		src/main.c

RM	=	rm -f

NAME	=	my_sokoban

LIB	=	-lmy -Llib/my/ -Iinclude

COM	=	$(OBJ:.c=.o)

FLAG	=	-Iinclude -lncurses

TEST	=	tests/unittest.c

TESTNAM	=	test

TESTFLA	=	-lcriterion -coverage

TESTCOM	=	$(TEST:.c=.o)

all:	$(COM)
	$(CC) -o $(NAME) $(COM) $(FLAG)
	make clean

clean:
	$(RM) $(COM)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

test_clean:
		$(RM) $(TESTCOM)

tests_run:	$(TESTCOM)
		$(CC) -o $(TESTNAM) $(TESTCOM) $(TESTFLA)
		make test_clean
		./$(TESTNAM)

bonus_bin:
		cd bonus/; make re
		mv bonus/my_sokoban bonus_bin
