##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compiles libmy
##

LIB = libmy.a libmy_graphical.a
PROJECT_NAME = bsmy_hunter

all: libmy.a

start :
		mv gitignore.txt .gitignore

libmy.a:
		cd lib/my && make
		cd ../..
		cd lib/my_graphical && make
		make clean
		echo "libmy.a and libmy_graphical.a has been compiled."
		make compile

compile:
		gcc -o $(PROJECT_NAME) *.c -I include/ -L ./ -lmy -lmy_graphical \
		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio \
		-lcsfml-network

segfault :
		gcc -o $(PROJECT_NAME) -g *.c -I include/ -L ./ -lmy -lmy_graphical \
		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio \
		-lcsfml-network

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


.PHONY: cs all clean fclean re
