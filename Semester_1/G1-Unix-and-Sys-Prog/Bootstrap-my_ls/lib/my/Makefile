##
## EPITECH PROJECT, 2024
## B-CPE-101-NCY-1-1-myprintf-jean-baptiste.gossot
## File description:
## Makefile of lib/my
##

SRC 	= 	mini_printf.c 	\
		mini_printf_verif_case.c 	\
		mini_vprintf.c 	\
		my_compute_power_it.c 	\
		my_compute_power_rec.c 	\
		my_compute_square_root.c 	\
		my_convert_num_to_str.c 	\
		my_fabs.c 	\
		my_find_prime_sup.c 	\
		my_getnbr.c 	\
		my_is_prime.c 	\
		my_isneg.c 	\
		my_isprint.c 	\
		my_printf_error_handler.c 	\
		my_printf_handling.c 	\
		my_printf_handle_flags_wiss.c 	\
		my_printf_handle_flags_wiss_2.c 	\
		my_printf_handle_precision1.c 	\
		my_printf_handle_precision2.c 	\
		my_printf_handle_precision3.c 	\
		my_printf_switch_base.c 	\
		my_printf_verification_case1.c 		\
		my_printf.c 	\
		my_vprintf.c 	\
		my_put_float.c 	\
		my_put_long_double.c 	\
		my_put_long_long.c 	\
		my_put_long.c 	\
		my_put_nbr_intmax.c 	\
		my_put_nbr.c 	\
		my_put_short_int.c 	\
		my_put_size_t.c 	\
		my_put_ssize_t.c 	\
		my_putchar.c 	\
		my_puthex.c 	\
		my_putstr.c 	\
		my_reverse_str.c 	\
		my_revstr.c 	\
		my_showmem.c 	\
		my_showstr.c 	\
		my_sort_int_array.c 	\
		my_str_isalpha.c 	\
		my_str_islower.c 	\
		my_str_isnum.c 	\
		my_str_isprintable.c 	\
		my_str_isupper.c 	\
		my_strcapitalize.c 	\
		my_strcat.c 	\
		my_strcmp.c 	\
		my_strcpy.c 	\
		my_strdup.c 	\
		my_strlen.c 	\
		my_strlowcase.c 	\
		my_strncat.c 	\
		my_strncmp.c 	\
		my_strncpy.c 	\
		my_strstr.c 	\
		my_strupcase.c 	\
		my_swap.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../../
	cp my.h ../../include/
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)
