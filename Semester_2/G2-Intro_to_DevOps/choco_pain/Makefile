##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compiles libmy
##

LIB = libmy.a
PROJECT_NAME = project
MY_LIB = -lmy
CFLAGS = -Wall -Wextra -Wunused -Wimplicit -O3
SRC = $(wildcard *.c) $(wildcard src/*.c)
SRC_SEGV = $(wildcard *.c) $(wildcard src/*.c) $(wildcard lib/my/*.c)
OBJ = $(SRC:.c=.o)
INCL = -I include/
LIB_COMP = -L ./ $(MY_LIB)

all: libmy.a compile

start :
		mv gitignore.txt .gitignore
		mv src/project.c src/$(PROJECT_NAME).c

libmy.a:
		cd lib/my && make
		mv lib/my/libmy.a ./
		rm -f include/my.h
		cp lib/my/my.h include/
		@echo "libmy.a has been compiled."

$(PROJECT_NAME): $(OBJ)
		gcc -o $(PROJECT_NAME) $(OBJ) $(INCL) $(LIB_COMP) $(CFLAGS)

clean:
		cd lib/my && make clean
		rm -f $(OBJ)

fclean: clean
		rm -f a.out
		rm -f $(LIB)
		rm -f $(PROJECT_NAME)
		rm -f *~
		rm -f src/*~
		rm -f lib/my/libmy.a
		rm -f lib/my/*.o
		rm -f lib/my/*~
		rm -f coding-style-reports.log
		rm -f *.gcno
		rm -f *.gcda
		rm -f unit_tests
		rm -f *.out
		rm -f *#
		@echo "Everything has been cleaned, do make for have a \
new libmy and compilation"

re: fclean all

cs: fclean
		clear
		@echo "All none compliant file for coding style \
has been cleaned, do make for have a \
new libmy and compilation"
		coding-style . .
		cat coding-style-reports.log
		rm -f coding-style-reports.log

unit_tests: fclean
		make all
		gcc -o unit_tests $(SRC) tests/*.c -I include/ \
			-L ./ -lmy -lcriterion --coverage

tests_run: unit_tests
		if [ ! -f unit_tests ]; then make unit_tests; fi
		chmod +x unit_tests
		./unit_tests
		gcovr --exclude tests/
		gcovr --exclude tests/ --branches
		make clean_tests

clean_tests:
		rm -f *.gcno
		rm -f *.gcda

segfault:
		gcc -o $(PROJECT_NAME) -g $(SRC_SEGV) $(INCL) $(CFLAGS)

printf:
		grep -Rn printf

.PHONY: cs all clean fclean re
