##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compiles libmy
##

LIB = libmy.a libmy_graphical.a
PROJECT_NAME = my_radar
CSFML_FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio \
		-lcsfml-network
INCLUDE = include/
SRC = $(wildcard *.c) $(wildcard src/*.c)

all: libmy.a compile

start :
		mv gitignore.txt .gitignore

libmy.a:
		cd lib/my && make
		cd ../..
		cd lib/my_graphical && make
		make clean
		echo "libmy.a and libmy_graphical.a has been compiled."

compile:
		gcc -o $(PROJECT_NAME) $(SRC) -I $(INCLUDE) -L ./ $(LIB) $(CSFML_FLAGS)

segfault :
		gcc -o $(PROJECT_NAME) -g $(SRC) -I $(INCLUDE) -L ./ $(LIB) \
		$(CSFML_FLAGS)

clean:
		cd lib/my && make clean
		rm -f *.o

fclean: clean
		rm -f a.out
		rm -f $(PROJECT_NAME)
		rm -f $(LIB)
		rm -f *~
		rm -f lib/my/libmy.a
		rm -f lib/my_graphical/libmy_graphical.a
		rm -f lib/my/*.o
		rm -f lib/my/*~
		rm -f coding-style-reports.log
		rm -f *.gcno
		rm -f *.gcda
		rm -f unit_tests
		rm -f *.out
		echo "Everything has been cleaned, do make for have a \
new libmy and compilation"

re: fclean all

cs: fclean
		clear
		coding-style . .
		cat coding-style-reports.log
		rm -f coding-style-reports.log

unit_tests: fclean
		make all
		gcc -o unit_tests tests/*.c -I include/ \
			-L ./ -lmy -lcriterion --coverage


tests_run:
		./unit_tests
		gcovr --exclude tests/
		gcovr --exclude tests/ --branches
		make fclean

printf:
		grep -Rn printf

.PHONY: cs all clean fclean re
