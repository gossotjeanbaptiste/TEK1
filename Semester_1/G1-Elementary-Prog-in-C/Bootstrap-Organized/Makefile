##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compiles libmy
##

LIB = libmy.a
PROJECT_NAME = bsorganized
MY_LIB = -lmy
FLAGS = -Wall -Wextra -Wunused -Wimplicit

all: libmy.a compile

start :
		mv gitignore.txt .gitignore

libmy.a:
		cd lib/my && make
		make clean
		echo "libmy.a has been compiled."

$(PROJECT_NAME):
		gcc -o $(PROJECT_NAME) *.c src/*.c -I include/ -L ./ $(MY_LIB) $(FLAGS)
clean:
		cd lib/my && make clean
		rm -f *.o

fclean: clean
		rm -f a.out
		rm -f $(LIB)
		rm -f $(PROJECT_NAME)
		rm -f *~
		rm -f lib/my/libmy.a
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

segfault: all
		gcc -o $(PROJECT_NAME) -g *.c src/*.c -I include/ -L ./ $(MY_LIB) \
		$(FLAGS)
printf:
		grep -Rn printf

.PHONY: cs all clean fclean re
