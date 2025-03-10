##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC = my_compute_power_it.c \n
	my_compute_power_rec.c \n
	my_compute_square_root.c \n
	my_fabs.c \n
	my_find_prime_sup.c \n
	my_getnbr.c \n
	my_isneg.c \n
	my_is_prime.c \n
	my_putchar.c \n
	my_put_nbr.c \n
	my_putstr.c \n
	my_showmem.c \n
	my_showstr.c \n
	my_sort_int_array.c \n
	my_strcapitalize.c \n
	my_strcat.c \n
	my_strcmp.c \n
	my_strcpy.c \n
	my_strdup.c \n
	my_str_isalpha.c \n
	my_str_islower.c \n
	my_str_isnum.c \n
	my_str_isprintable.c \n
	my_str_isupper.c \n
	my_strlen.c \n
	my_strlowcase.c \n
	my_strncat.c \n
	my_strncmp.c \n
	my_strncpy.c \n
	my_strstr.c \n
	my_strupcase.c \n
	my_swap.c

OBJ = $(SRC:.c=.o)

NAME = libmy

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)
my:
	cd ../..
	mkdir include
	mv ./lib/my/my.h ./include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re: fclean all
