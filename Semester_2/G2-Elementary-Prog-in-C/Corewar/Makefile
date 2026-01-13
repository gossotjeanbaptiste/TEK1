##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compiles libmy
##

LIB = libmy.a
PROJECT_NAME = corewar
MY_LIB = -lmy
CFLAGS = -Wall -Wextra -Wunused -Wimplicit -O3
SRC = $(wildcard *.c) $(wildcard src/*.c) \
$(wildcard src/parser/*.c) $(wildcard src/functions/*.c) \
$(wildcard src/tools/*.c) $(wildcard src/progs/*.c) \
$(wildcard src/tools/getter/*.c) $(wildcard src/progs/remove/*.c) \
$(wildcard src/progs/valid/*.c)
SRC_SEGV = $(wildcard *.c) $(wildcard src/*.c) $(wildcard lib/my/*.c) \
$(wildcard src/parser/*.c) $(wildcard src/functions/*.c) \
$(wildcard src/tools/*.c) $(wildcard src/progs/*.c) \
$(wildcard src/tools/getter/*.c) $(wildcard src/progs/remove/*.c) \
$(wildcard src/progs/valid/*.c)
OBJ = $(SRC:.c=.o)
INCL = -I include/
LIB_COMP = -L ./ $(MY_LIB)

all: libmy.a $(PROJECT_NAME)

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
		rm -f init_arena_test
		rm -f load_program_test
		rm -f read_write_test
		rm -f test_champion_loader
		@echo "Everything has been cleaned, do make to have a \
new libmy and compilation"

re: fclean all

cs: fclean
		clear
		@echo "All none compliant file for coding style \
has been cleaned, do make to have a \
new libmy and compilation"
		coding-style . .
		cat coding-style-reports.log
		rm -f coding-style-reports.log

unit_tests: fclean
		make all
		gcc -o unit_tests tests/*.c -I include/ \
			-L ./ -lmy -lcriterion --coverage


tests_run: unit_tests
		./unit_tests
		gcovr --exclude tests/
		gcovr --exclude tests/ --branches
		make fclean

segfault:
		gcc -o $(PROJECT_NAME) -g $(SRC_SEGV) $(INCL) $(CFLAGS)

printf:
		grep -Rn printf

.PHONY: cs all clean fclean re
