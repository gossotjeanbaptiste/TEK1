##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

all: $(NAME)
	bash ./build.sh
	cd ../..
	mkdir include
	mv ./lib/my/my.h ./include/
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re:
	make fclean all
