##
## EPITECH PROJECT, 2025
## Solo Stumpers 1
## File description:
## Makefile
##

SRC = $(wildcard *.c) $(wildcard src/*.c)
PROJECT_NAME = clean_str
OBJ = $(SRC:.c : .o)

all:
	gcc -o $(PROJECT_NAME) -g $(SRC)

clean:
	rm -f $(OBJ)

fclean:
	cd include/ && ./script.sh && cd ..
	cd src/ && ./script.sh && cd ..
	rm -f $(OBJ)
	rm -f $(PROJECT_NAME)
	rm -rf *~
	rm -f *#

re: fclean all

cs:
	make fclean
	clear
	coding-style . .
	cat coding-style-reports.log
	rm -f coding-style-reports.log
