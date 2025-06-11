##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compiles libmy
##

PROJECT_NAME = frenchNameFormatter
FLAGS = -Wall -Wextra -Wunused -Wimplicit -O3
SRC = $(wildcard *.c) $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
INCL = -I include/

all: $(PROJECT_NAME)

start :
		mv gitignore.txt .gitignore
		mv src/project.c src/$(PROJECT_NAME).c

$(PROJECT_NAME): $(OBJ)
		gcc -o $(PROJECT_NAME) $(OBJ) $(INCL) $(FLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f a.out
		rm -f $(LIB)
		rm -f $(PROJECT_NAME)
		rm -f *~
		rm -f include/*~
		rm -f src/*~
		rm -f coding-style-reports.log
		rm -f *.out
		rm -f *#
		@echo "Everything has been cleaned, do make for have a \
new libmy and compilation"

re: fclean all

cs: fclean
		clear
		@echo "Everything has been cleaned, do make for have a \
new libmy and compilation"
		coding-style . .
		cat coding-style-reports.log
		rm -f coding-style-reports.log

segfault: $(OBJ)
		gcc -o $(PROJECT_NAME) -g $(OBJ) $(INCL) $(LIB_COMP) $(FLAGS)

printf:
		grep -Rn printf

.PHONY: cs all clean fclean re
